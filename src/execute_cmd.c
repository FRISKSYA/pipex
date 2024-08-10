/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:33:34 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 14:39:46 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
