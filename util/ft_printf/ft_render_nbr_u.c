/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_nbr_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:41:07 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 15:15:48 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	render_nbr_u(unsigned int ui)
{
	int	result;

	result = 0;
	if (ui >= 10)
		result += render_nbr_u(ui / 10);
	result += render_char((ui % 10) + '0');
	return (result);
}
