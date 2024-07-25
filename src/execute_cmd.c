/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:32:11 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/24 19:36:10 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	exec_cmd_start(t_pipex *data, int *pipe_fd)
{
	close(pipe_fd[0]);
	close(STDOUT_FILENO);
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		ft_exit(data, "dup2 : exec_cmd_start, pipe_fd[1]");
	close(pipe_fd[1]);
	if (dup2(data->in_fd, STDIN_FILENO) < 0)
		ft_exit(data, "dup2 : exec_cmd_start, in_fd");
	close(data->in_fd);
	execve(data->cmd_args[0][0], data->cmd_args[0], data->env);
	ft_exit(data, "execve : exec_cmd_start");
}

static void	exec_cmd_end(t_pipex *data, int *pipe_fd)
{
	close(pipe_fd[1]);
	close(STDIN_FILENO);
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		ft_exit(data, "dup2 : exec_cmd_end. pipe_fd[0]");
	close(pipe_fd[0]);
	if (dup2(data->out_fd, STDOUT_FILENO) < 0)
		ft_exit(data, "dup2 : exec_cmd_end, out_fd");
	close(data->out_fd);
	execve(data->cmd_args[1][0], data->cmd_args[1], data->env);
	ft_exit(data, "execve : exec_cmd_start");
}

void	execute_cmd(t_pipex *data, size_t i, int *pipe_fd)
{
	if (i == 0)
		exec_cmd_start(data, pipe_fd);
	else if (i == 1)
		exec_cmd_end(data, pipe_fd);
	exit(EXIT_SUCCESS);
}
