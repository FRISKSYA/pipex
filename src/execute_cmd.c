/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:54:32 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/01 18:05:51 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	free_split(char **str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (EXIT_SUCCESS);
}

static char	**get_paths(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			env[i] += ft_strlen("PATH=");
			return (ft_split(env[i], ':'));
		}
		i++;
	}
	return (NULL);
}

static char	*join_dir_cmd(char *prefix, char *cmd)
{
	char	*prev;

	prev = ft_strjoin(prefix, "/");
	if (prev == NULL)
		return (NULL);
	return (ft_strjoin(prev, cmd));
}

void	execve_relative_path(char **cmd_args, char **env)
{
	size_t	i;
	char	**paths;
	char	*cmd_path;

	if (!cmd_args)
		return ;
	paths = get_paths(env);
	i = 0;
	while (paths && paths[i])
	{
		cmd_path = join_dir_cmd(paths[i], cmd_args[0]);
		if (cmd_path == NULL && free_split(paths) == EXIT_SUCCESS)
			return ;
		if (access(cmd_path, X_OK) == 0)
		{
			free_split(paths);
			execve(cmd_path, cmd_args, env);
			free(cmd_path);
			exit(EXIT_FAILURE);
		}
		//write(2, "hello\n", 6);
		free(cmd_path);
		i++;
	}
	free_split(paths);
	write(2, "command not found\n", 19);
	exit(EXIT_FAILURE);
}

