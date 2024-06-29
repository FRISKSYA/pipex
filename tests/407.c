/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   407.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:30:44 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/28 17:04:55 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

extern char	**environ;

void	do_child(int i)
{
	int	status;
	
	if (wait(&status) < 0)
	{
		perror("wait (child) error");
		exit(EXIT_FAILURE);
	}
	else
		write(1, ft_itoa(i), ft_strlen(ft_itoa(i)));
}

int	main(int argc, char **argv)
{
	int	start, end;
	int	child, status;

	if (argc > 2)
		exit (EXIT_FAILURE);
	else if (argc == 1)
		end = 20;
	else
		end = atoi(argv[1]);
	start = 0;
	if ((child = fork()) < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		while (start < end)
			do_child(start++);
	}
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
