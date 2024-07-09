/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:00:01 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/05/15 15:57:04 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

//main
int		ft_printf(const char *fmt, ...);
int		ft_render(const char **fmt, va_list *ap);

//renders
int		render_char(int c);
int		render_str(char *str);
int		render_address(void *ptr);
int		render_nbr(int i);
int		render_nbr_u(unsigned int ui);
int		render_nbr_lower_x(int i);
int		render_nbr_upper_x(int i);

#endif
