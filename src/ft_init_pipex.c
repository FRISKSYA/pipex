/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:25:40 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/08 19:11:09 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_init_pipex(t_pipex *data)
{
	data->in_fd = INT_MIN;
	data->out_fd = INT_MIN;
	data->here_doc = false;
	data->is_invalid_infile = true;
	data->cmd_paths = NULL;
	data->cmd_args = NULL;
}
