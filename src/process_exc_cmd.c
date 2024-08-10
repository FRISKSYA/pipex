/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exc_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:42:45 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 17:23:24 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	is_full_path(const char *path)
{
	if (!path)
		return (false);
	if (
		(ft_strncmp(path, "~/", 2) == 0)
		|| (ft_strncmp(path, "/", 1) == 0)
		|| (ft_strncmp(path, "../", 3) == 0)
		|| (ft_strncmp(path, "./", 2) == 0)
	)
		return (true);
	else
		return (false);
}

// TODO: dev
void	execve_relative_path(char **cmd_args, char **env)
{
	if (access(cmd_args[0], X_OK) != 0)
		return ;
	execve(cmd_args[0], cmd_args, env);
}

void	execve_full_path(char **cmd_args, char **env)
{
	if (access(cmd_args[0], X_OK) != 0)
		return ;
	execve(cmd_args[0], cmd_args, env);
}
