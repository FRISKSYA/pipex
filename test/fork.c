/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:01:22 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/18 14:29:07 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

void	do_child(void)
{
	printf("this is child(pid=%d).\n", getpid());
	exit(2);
}

int	main(void)
{
	int	child, status;

	if ((child = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
		do_child();
	else
	{
		if (wait(&status) < 0)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		printf("the child (pid=%d) exited with status(%d).\n", child, WEXITSTATUS(status));
	}
	return (EXIT_SUCCESS);
}
