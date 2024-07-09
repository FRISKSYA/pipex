/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:24:46 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/17 12:53:13 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	size_t			index;

	uc = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == uc)
			return ((void *)((uintptr_t)s + index));
		index++;
	}
	return (NULL);
}
