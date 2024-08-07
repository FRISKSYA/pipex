/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:38:08 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/27 16:21:11 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	return (
		c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' '
	);
}

int	ft_atoi(const char *str)
{
	size_t	index;
	size_t	is_mi;
	long	result;

	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
		is_mi = 1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	result = 0;
	while (ft_isdigit(str[index]) && str[index])
	{
		if (is_mi != 1 && result > (LONG_MAX - (str[index] - '0')) / 10)
			return ((int)LONG_MAX);
		else if (is_mi == 1 && - result < (LONG_MIN + (str[index] - '0')) / 10)
			return ((int)LONG_MIN);
		result = 10 * result + (str[index] - '0');
		index++;
	}
	if (is_mi == 1)
		return ((int)-1 * result);
	else
		return ((int)result);
}
