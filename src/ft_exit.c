/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:23:00 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 22:01:28 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	print_command_not_found(char *cmd)
{
	char	*msg;

	msg = ft_strjoin(cmd, " : command not found\n");
	if (!msg)
		return ;
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
}

void	cleanup_cmd_args(char ***cmd_args)
{
	size_t	i;
	size_t	j;

	if (!cmd_args)
		return ;
	else
	{
		i = 0;
		while (cmd_args[i])
		{
			j = 0;
			while (cmd_args[i][j])
			{
				free(cmd_args[i][j]);
				j++;
			}
			free(cmd_args[i]);
			i++;
		}
	}
	free(cmd_args);
}

void	ft_cleanup(t_pipex *data)
{
	if (data && data->cmd_args)
		cleanup_cmd_args(data->cmd_args);
	if (data && data->childs)
		free(data->childs);
	if (data && data->pipe_fd[0])
		close(data->pipe_fd[0]);
	if (data && data->pipe_fd[1])
		close(data->pipe_fd[1]);
	if (data)
		free(data);
}

// FIXME: exit($?) must be change
// TODO: data->status fill a value of error code if exit.
void	ft_exit(t_pipex *data, char *error_msg)
{
	int	status;

	if (!data && !error_msg)
		exit(EXIT_FAILURE);
	if (!data && error_msg)
	{
		perror(error_msg);
		exit(EXIT_FAILURE);
	}
	status = data->status;
	ft_cleanup(data);
	if (error_msg)
		perror(error_msg);
	exit(status);
}
