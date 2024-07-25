/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:10:12 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/23 19:05:38 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exit(t_pipex *data, char *error_msg)
{
	ft_cleanup(data);
	perror(error_msg);
	exit(EXIT_FAILURE);
}
