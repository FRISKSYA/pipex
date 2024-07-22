/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:01 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/18 13:23:02 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

int			pipe_fd[2];
extern char	**environ;

void	do_child(void)
{
	char	*argv[3];

	printf("This is child (pid=%d).\n", getpid());
	printf("cat pipe3.c\n");

	close(pipe_fd[0]);

	argv[0] = "/bin/cat";
	argv[1] = "pipe3.c";
	argv[2] = NULL;

	close(STDOUT_FILENO);
	// pipe_fd[1] <- STDOUT_FILENOとするよ的な
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2 (child)");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	execve(argv[0], argv, environ);
}

void	do_parent(void)
{
	char	*argv[3];
	int		status;

	printf("This is parent (pid=%d).\n", getpid());
	printf("wc -l\n");

	close(pipe_fd[1]);

	argv[0] = "/bin/wc";
	argv[1] = "-l";
	argv[2] = NULL;

	close(STDIN_FILENO);
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
	{
		perror("dup2 (parent)");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	execve(argv[0], argv, environ);
}

int	main(void)
{
	int	child;

	if (pipe(pipe_fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if ((child = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child)
		do_parent();
	else
		do_child();
	return (EXIT_SUCCESS);
}
