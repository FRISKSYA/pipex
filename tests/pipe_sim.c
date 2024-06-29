/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:40:31 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/29 17:54:20 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

extern char	**environ;

int	main(int argc, char** argv)
{
	int	fd[2];
	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	
	int	pid1 = fork();
	if (pid1 < 0)
		return (EXIT_FAILURE);

	if (pid1 == 0)
	{
		char	*argv[5];
		// child proc 1
		argv[0] = "/bin/ping";
		argv[1] = "-c";
		argv[2] = "5";
		argv[3] = "google.com";
		argv[4] = NULL;
		execve(argv[0], argv, environ);
	}
	waitpid(pid1, NULL, 0);
	return (0);
}
