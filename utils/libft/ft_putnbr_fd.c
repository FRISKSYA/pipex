/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:35:21 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/22 18:51:29 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	ln = (long)n;
	if (ln < 0)
		ft_putchar_fd('-', fd);
	if (ln / 10 != 0)
	{
		if (ln < 0)
			ft_putnbr_fd((ln / 10) * -1, fd);
		else
			ft_putnbr_fd(ln / 10, fd);
	}
	if (ln < 0)
		c = (((ln % 10) * -1) + '0');
	else
		c = (ln % 10 + '0');
	ft_putchar_fd(c, fd);
}
