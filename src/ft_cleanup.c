/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:35:02 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/25 11:14:07 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	free_cmd_args(char ***cmd_args)
{
	size_t	i;
	size_t	j;

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

int	ft_cleanup(t_pipex *data)
{
	if (data && data->cmd_args && data->cmd_args[0])
		free_cmd_args(data->cmd_args);
	if (data && data->cmd_args)
		free(data->cmd_args);
	if (data)
		free(data);
	return (EXIT_SUCCESS);
}
