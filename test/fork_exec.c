/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:30:44 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/09 20:13:43 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

extern char	**environ;

void	do_child(void)
{
	char	*argv[3];

	printf("This is child (pid=%d).\n", getpid());
	argv[0] = "/bin/ls";
	argv[1] = "/";
	argv[2] = NULL;
	execve(argv[0], argv, environ);
}

int	main(void)
{
	int	child, status;

	if ((child = fork()) < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
		do_child();
	else
	{
		if (wait(&status) < 0)
		{
			perror("wait error");
			exit(EXIT_FAILURE);
		}
		printf("The child (pid=%d) exited with status(%d).\n", child, WEXITSTATUS(status));
	}
	return (EXIT_SUCCESS);
}
