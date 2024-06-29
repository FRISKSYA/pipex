/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_nbr_upper_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:08:00 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 16:00:36 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	render_nbr_upper_x(int i)
{
	int				result;
	unsigned int	ui;

	ui = (unsigned int)i;
	result = 0;
	if (ui >= 0x10)
		result += render_nbr_upper_x(ui / 0x10);
	if (ui % 0x10 < 10)
		result += render_char((ui % 0x10) + '0');
	else
		result += render_char((ui % 0x10) - 10 + 'A');
	return (result);
}
//#include <stdio.h>
//int	main(void)
//{
//	int	i;
//
//	i = 1;
//	printf("%X\n", i);
//	render_nbr_upper_x(i);
//	printf("\n");
//
//	i = 0;
//	printf("%X\n", i);
//	render_nbr_upper_x(i);
//	printf("\n");
//
//	i = -1;
//	printf("%X\n", i);
//	render_nbr_upper_x(i);
//	printf("\n");
//
//	i = 2147483647;
//	printf("%X\n", i);
//	render_nbr_upper_x(i);
//	printf("\n");
//
//	i = -2147483648;
//	printf("%X\n", i);
//	render_nbr_upper_x(i);
//	printf("\n");
//	return (0);
//}
