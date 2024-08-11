/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:00:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/11 13:19:29 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	***split_cmd_args(char **argv)
{
	size_t	i;
	char	***cmd_args;

	cmd_args = (char ***)malloc(3 * sizeof(char **));
	if (!cmd_args)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		cmd_args[i] = ft_split(argv[i + 2], ' ');
		if (cmd_args[i] == NULL)
		{
			cleanup_cmd_args(cmd_args);
			return (NULL);
		}
		i++;
	}
	cmd_args[i] = NULL;
	return (cmd_args);
}

static void	init_pipex(t_pipex **data, int argc, char **argv, char **env)
{
	size_t	i;

	if (argc != 5)
		ft_exit(NULL, "init_pipex : args must be 5.");
	*data = (t_pipex *)malloc(sizeof(t_pipex));
	if (!(*data))
		ft_exit(NULL, "init_pipex : data is NULL.");
	(*data)->argv = argv;
	(*data)->childs = (pid_t *)malloc(2 * sizeof(pid_t));
	if (!(*data)->childs)
		ft_exit(*data, "init_pipex : data->childs is NULL.");
	i = 0;
	while (i < 2)
		(*data)->childs[i++] = 0;
	(*data)->env = env;
	(*data)->cmd_args = split_cmd_args(argv);
	if (!(*data)->cmd_args)
		ft_exit(*data, "init_pipex : data->cmd_args is NULL.");
	(*data)->status = 0;
	if (pipe((*data)->pipe_fd) < 0)
	{
		(*data)->status = EXIT_FAILURE;
		ft_exit(*data, "init_pipex : pipe is failure.");
	}
}

static int	ft_waitpid(t_pipex *data)
{
	size_t	i;
	int		status;

	i = 0;
	if (waitpid(data->childs[i], NULL, 0) < 0)
	{
		data->status = EXIT_FAILURE;
		ft_exit(data, "ft_waitpid : data->childs[0]");
	}
	i++;
	if (waitpid(data->childs[i], &status, 0) < 0)
	{
		data->status = EXIT_FAILURE;
		ft_exit(data, "ft_waitpid : data->childs[1]");
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_SUCCESS);
}

static void	close_pipe_fd(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*data;
	int		status;

	init_pipex(&data, argc, argv, env);
	execute_cmd(data);
	close_pipe_fd(data->pipe_fd);
	status = ft_waitpid(data);
	ft_cleanup(data);
	return (status);
}
