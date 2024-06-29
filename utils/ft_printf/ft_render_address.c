/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:38:20 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 17:04:02 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	render_hex_ptr(unsigned long long int uli)
{
	int	result;

	result = 0;
	if (uli >= 0x10)
		result += render_hex_ptr(uli / 0x10);
	if (uli % 0x10 < 10)
		result += render_char((uli % 0x10) + '0');
	else
		result += render_char((uli % 0x10) - 10 + 'a');
	return (result);
}

int	render_address(void *ptr)
{
	unsigned long long int	uli;
	int						result;

	result = 0;
	result += render_str("0x");
	uli = (unsigned long long int)(uintptr_t)ptr;
	result += render_hex_ptr(uli);
	return (result);
}
//#include <stdio.h>
//int	main(void)
//{
//	int	x = 42;
//	printf("%d",render_address(&x));
//	printf("\n");
//	printf("%d",printf("%p", &x));
//	printf("\n");
//	render_address(NULL);
//	printf("\n%p", NULL);
//	return (0);
//}
