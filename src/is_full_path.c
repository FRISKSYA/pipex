/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:49:00 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/01 13:04:57 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	is_full_path(const char *path)
{
	if (!path)
		return (false);
	if (
		(ft_strncmp(path, "~/", 2) == 0)
		|| (ft_strncmp(path, "/", 1) == 0)
		|| (ft_strncmp(path, "../", 3) == 0)
		|| (ft_strncmp(path, "./", 2) == 0)
	)
		return (true);
	else
		return (false);
}
