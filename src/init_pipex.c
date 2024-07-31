/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:37:18 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/31 14:22:23 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	fill_cmd_args(char **argv, t_pipex *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_cmd)
	{
		data->cmd_args[i] = ft_split(argv[i + 2], ' ');
		if (data->cmd_args[i] == NULL)
			ft_exit(data, "malloc : data->cmd_args[i]");
		i++;
	}
	data->cmd_args[i] = NULL;
}

void	init_pipex(int argc, char **argv, char **env, t_pipex *data)
{
	int	in_fd;
	int	out_fd;

	data->num_cmd = argc - 3;
	data->env = env;
	data->cmd_args = (char ***)malloc((data->num_cmd + 1) * sizeof(char **));
	if (data->cmd_args == NULL)
		ft_exit(data, "malloc : data->cmd_args");
	fill_cmd_args(argv, data);
	in_fd = open(argv[1], O_RDONLY);
	data->in_fd = in_fd;
	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data->out_fd = out_fd;
	data->status = 0;
}
