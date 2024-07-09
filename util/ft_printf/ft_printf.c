/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:09:31 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 18:19:26 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;

	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			i += ft_render(&fmt, &ap);
		else
		{
			i += render_char(*fmt);
			fmt++;
		}
	}
	va_end(ap);
	return (i);
}
