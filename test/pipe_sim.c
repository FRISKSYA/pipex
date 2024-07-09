/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:40:31 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/29 18:05:36 by kfukuhar         ###   ########.fr       */
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

		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(argv[0], argv, environ);
	}

	int	pid2 = fork();
	if (pid2 < 0)
		return (EXIT_FAILURE);
	if (pid2 == 0)
	{
		char	*argv[3];
		// child proc 2
		argv[0] = "/bin/grep";
		argv[1] = "rtt";
		argv[2] = NULL;

		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(argv[0], argv, environ);
	}
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
