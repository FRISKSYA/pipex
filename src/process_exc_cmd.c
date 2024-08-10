/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_exc_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:42:45 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 15:05:11 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	exec_cmd(t_pipex *data, size_t i)
{
	if (is_full_path((const char *)data->cmd_args[i][0]))
		execve_full_path(data->cmd_args[i], data->env);
	else
		execve_relative_path(data->cmd_args[i], data->env);
}

void	do_cmd(t_pipex *data, size_t i)
{
	if (i == 0)
	{
		open_files_1(data);
		ctl_fds_1(data);
		exec_cmd(data, i);
	}
	else if (i == 1)
	{
		open_files_2(data);
		ctl_fds_2(data);
		exec_cmd(data, i);
	}
}
