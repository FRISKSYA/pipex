/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:10:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 19:32:26 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_render(const char **fmt, va_list *ap)
{
	int	i;

	i = 0;
	(*fmt)++;
	if (**fmt == 'c')
		i += render_char(va_arg(*ap, int));
	else if (**fmt == 's')
		i += render_str(va_arg(*ap, char *));
	else if (**fmt == 'p')
		i += render_address(va_arg(*ap, void *));
	else if (**fmt == 'd' || **fmt == 'i')
		i += render_nbr(va_arg(*ap, int));
	else if (**fmt == 'u')
		i += render_nbr_u(va_arg(*ap, unsigned int));
	else if (**fmt == 'x')
		i += render_nbr_lower_x(va_arg(*ap, int));
	else if (**fmt == 'X')
		i += render_nbr_upper_x(va_arg(*ap, int));
	else if (**fmt == '%')
		i += render_char('%');
	else
		i = -1;
	(*fmt)++;
	return (i);
}
