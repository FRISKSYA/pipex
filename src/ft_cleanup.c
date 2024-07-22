/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:35:02 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/22 15:10:08 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	free_cmd_args(t_pipex *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->cmd_args[i])
	{
		j = 0;
		while (data->cmd_args[i][j])
		{
			free(data->cmd_args[i][j]);
			j++;
		}
		free(data->cmd_args[i]);
		i++;
	}
	free(data->cmd_args);
}

int	ft_cleanup(t_pipex *data)
{
	free_cmd_args(data);
	free(data);
	return (EXIT_SUCCESS);
}
