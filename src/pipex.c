/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:00:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/31 13:37:38 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
//	// TODO: remove it.
//	while (env[i])
//	{
//		if (ft_strnstr(env[i], "PATH", 4))
//			ft_printf("env[%d] : %s\n", i, env[i]);
//		i++;
//	}

// TODO: compare with bash, its probably need not to exit.
// STEPS:
//	1: init_pipex
//	2: parse_args
//	2.1 : open infile
//	3: execute cmds
//	3.1 : write outfile
//	4: cleanup_pipex
//int	main(int argc, char **argv) //, const char ** const env)

static void	fork_and_execute(t_pipex *data, int *pipe_fd)
{
	size_t	i;

	i = 0;
	while (i < NUM_CMD)
	{
		data->childs[i] = fork();
		if (data->childs[i] < 0)
			ft_exit(data, "FORK_ERROR");
		if (data->childs[i] == 0)
			execute_cmd(data, i, pipe_fd);
		i++;
	}
}

static void	ft_waitpid(t_pipex *data)
{
	size_t	i;

	i = 0;
	if (waitpid(data->childs[i], NULL, 0) < 0)
		ft_exit(data, "waitpid: data->childs[0]");
	i++;
	if (waitpid(data->childs[i], &(data->status), 0) < 0)
		ft_exit(data, "waitpid: data->childs[1]");
}

static void	close_pipe_fd(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	t_pipex	*data;

	if (argc != 5)
		ft_exit(NULL, "ARGC_ERROR");
	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (data == NULL)
		ft_exit(data, "MALLOC_ERROR : data");
	init_pipex(argc, argv, env, data);
	if (pipe(pipe_fd) < 0)
		ft_exit(data, "PIPE_ERROR");
	fork_and_execute(data, pipe_fd);
	close_pipe_fd(pipe_fd);
	ft_waitpid(data);
	ft_cleanup(data);
	return (EXIT_SUCCESS);
}
