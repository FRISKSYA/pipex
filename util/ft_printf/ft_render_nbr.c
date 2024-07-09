/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:48:49 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 15:15:56 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	render_nbr(int i)
{
	int		result;
	long	li;

	li = (long)i;
	result = 0;
	if (li < 0)
	{
		result += render_char('-');
		li *= -1;
	}
	if (li >= 10)
		result += render_nbr(li / 10);
	result += render_char((li % 10) + '0');
	return (result);
}
