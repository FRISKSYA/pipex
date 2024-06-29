/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:19:39 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/19 11:00:16 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static void	*ft_rev_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = n;
	while (index > 0)
	{
		index--;
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	uintptr_t	p_dst;
	uintptr_t	p_src;

	p_dst = (uintptr_t)dst;
	p_src = (uintptr_t)src;
	if (p_dst == p_src)
		return (dst);
	else if (p_dst > p_src && p_dst <= (p_src + len))
		return (ft_rev_memcpy(dst, src, len));
	else
		return (ft_memcpy(dst, src, len));
}
