/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:35:01 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/28 15:24:40 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	pipe_fd[2];

void	do_child(void)
{
	char	*p = "Hello, dad or man!.\n";

	printf("This is child.\n");

	close(pipe_fd[0]);

	close(1);
	if (dup2(pipe_fd[1], 1) < 0)
	{
		perror("dup2 (child)");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	while (*p)
		putchar(*p++);
}

void	do_parent(void)
{
	char	c;
	int		status;

	printf("This is parent.\n");
	close(pipe_fd[1]);

	close(0);
	if (dup2(pipe_fd[0], 0) < 0)
	{
		perror("dup2 (parent)");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	while ((c = getchar()) != EOF)
		putchar(c);
	if (wait(&status) < 0)
	{
		perror("wait");
		exit(EXIT_FAILURE);
	}
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
