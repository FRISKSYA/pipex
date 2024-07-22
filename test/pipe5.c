/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:01 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/18 15:23:21 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

int			pipe_fd[2];
extern char	**environ;

void	do_child_1(void)
{
	char	*argv[3];

	printf("This is child_1 (pid=%d).\n", getpid());
	close(pipe_fd[0]);
	close(STDOUT_FILENO);

	argv[0] = "/bin/cat";
	//argv[0] = "aaaaa";
	argv[1] = "pipe3.c";
	//argv[1] = "invalid_file";
	argv[2] = NULL;

	// pipe_fd[1] <- STDOUT_FILENOとするよ的な
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2 (child)");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	execve(argv[0], argv, environ);
	perror("execve(child_1)");
	exit(EXIT_FAILURE);
}

void	do_child_2(void)
{
	char	*argv[3];
	int		fd;

	printf("This is child_2 (pid=%d).\n", getpid());
	close(pipe_fd[1]);
	close(STDIN_FILENO);

	argv[0] = "/bin/wc";
	argv[1] = "-l";
	argv[2] = NULL;

	// stdin dup
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
	{
		perror("dup2 (parent)");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);

	// stdout dup
	fd = open("output", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	execve(argv[0], argv, environ);
	perror("execve(child_2)");
	exit(EXIT_FAILURE);
}

int	main(void)
{
	int		status;
	pid_t	child_1;
	pid_t	child_2;

	if (pipe(pipe_fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// cmd1: execve
	if ((child_1 = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_1 == 0)
	{
		do_child_1();
		exit(EXIT_SUCCESS);
	}

	// cmd2: execve
	if ((child_2 = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_2 == 0)
	{
		do_child_2();
		exit(EXIT_SUCCESS);
	}

	// pipe close
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	// cmd1: waitpid
	if (waitpid(child_1, &status, 0) < 0)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
	printf("The child_1 (pid=%d) exited with status(%d).\n", child_1, WEXITSTATUS(status));

	// cmd2: waitpid
	if (waitpid(child_2, &status, 0) < 0)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
	printf("The child_2 (pid=%d) exited with status(%d).\n", child_2, WEXITSTATUS(status));

	return (EXIT_SUCCESS);
}
