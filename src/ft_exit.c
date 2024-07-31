/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:10:12 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/31 14:23:47 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// NOTE: error_msg ex)
// "{function name} : {...sub info}"
void	ft_exit(t_pipex *data, char *error_msg)
{
	int	status;

	status = 0;
	if (data == NULL)
	{
		perror(error_msg);
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(data->status))
		status = WEXITSTATUS(data->status);
	ft_cleanup(data);
	perror(error_msg);
	if (status)
		exit(status);
	else
		exit(EXIT_FAILURE);
}

