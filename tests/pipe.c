/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:20:37 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/28 14:28:04 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	pipe_fd[2];

void	do_child(void)
{
	char	*p = "Hello, dad or mam!\n";

	printf("This is child.\n");
	close(pipe_fd[0]);
	while (*p != '\0')
	{
		if (write(pipe_fd[1], p, 1) < 0)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		p++;
	}
}

void	do_parent(void)
{
	char	c;
	int		count, status;

	printf("This is parent.\n");

	close(pipe_fd[1]);

	while ((count = read(pipe_fd[0], &c, 1)) > 0)
		putchar(c);
	
	if (count < 0)
	{
		perror("read");
		exit (EXIT_FAILURE);
	}
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
