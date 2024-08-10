/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:33:34 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 18:30:12 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ctl_fds_1(t_pipex *data, int in_fd)
{
	close(data->pipe_fd[0]);
	close(STDOUT_FILENO);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) < 0)
		ft_exit(data, "ctl_fds_1 : dup2");
	close(data->pipe_fd[1]);
	if (dup2(in_fd, STDIN_FILENO) < 0)
		ft_exit(data, "ctl_fds_1 : dup2");
	close(in_fd);
}

static void	ctl_fds_2(t_pipex *data, int out_fd)
{
	close(data->pipe_fd[1]);
	close(STDIN_FILENO);
	if (dup2(data->pipe_fd[0], STDIN_FILENO) < 0)
		ft_exit(data, "ctl_fds_2 : dup2");
	close(data->pipe_fd[0]);
	if (dup2(out_fd, STDOUT_FILENO) < 0)
		ft_exit(data, "ctl_fds_2 : dup2");
	close(out_fd);
}

static void	exec_cmd(t_pipex *data, size_t i)
{
	// TODO: extend "~" func
	if (is_home_path((const char *)data->cmd_args[i][0]))
		replace_home_path(&data->cmd_args[i][0], data->env);
	if (is_full_path((const char *)data->cmd_args[i][0]))
		execve_full_path(data->cmd_args[i], data->env);
	else
		execve_relative_path(data->cmd_args[i], data->env);
	print_command_not_found(data->cmd_args[i][0]);
	ft_exit(data, NULL);
}

static void	do_cmd(t_pipex *data, size_t i)
{
	int	in_fd;
	int	out_fd;

	if (i == 0)
	{
		in_fd = open(data->argv[1], O_RDONLY);
		if (in_fd < 0)
			ft_exit(data, "do_cmd : open");
		ctl_fds_1(data, in_fd);
		exec_cmd(data, i);
	}
	else if (i == 1)
	{
		out_fd = open(data->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (out_fd < 0)
			ft_exit(data, "do_cmd : open");
		ctl_fds_2(data, out_fd);
		exec_cmd(data, i);
	}
}

// FIXME: "i < 2" is bad.
void	execute_cmd(t_pipex *data)
{
	size_t	i;

	i = 0;
	while (i < 2)
	{
		data->childs[i] = fork();
		if (data->childs[i] < 0)
			ft_exit(data, "excute_cmd : fork");
		if (data->childs[i] == 0)
			do_cmd(data, i);
		i++;
	}
}
