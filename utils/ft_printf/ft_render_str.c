/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:33:05 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 15:44:55 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	render_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (render_str("(null)"));
	while (*str)
	{
		i += render_char(*str);
		str++;
	}
	return (i);
}
