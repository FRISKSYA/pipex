/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:54:32 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/31 18:13:47 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	free_split(char **str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
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

void	execve_relative_path(char **cmd_args, char **env)
{
	char	**paths;

	paths = get_paths(env);
	if (!cmd_args)
		return ;
	// TODO: remove it. just debug.
	size_t	j;
	j = 0;
	while (paths && paths[j])
	{
		ft_printf("path[%d] : %s\n", (int)j, paths[j]);
		j++;
	}
	free_split(paths);
}

void	execve_absolute_path(char **cmd_args, char **env);
