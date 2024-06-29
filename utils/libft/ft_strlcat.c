/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:38:46 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/21 14:28:53 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(
		char *dst,
		const char *src,
		size_t dstsize
		)
{
	size_t	max_cpy;
	size_t	index;
	size_t	output;
	size_t	i_dst;

	if (dstsize == 0)
		return (ft_strlen(src));
	output = ft_strlen(dst) + ft_strlen(src);
	i_dst = ft_strlen(dst);
	max_cpy = dstsize - 1;
	index = 0;
	while (index <= max_cpy && src[index] && i_dst < dstsize - 1)
	{
		dst[i_dst] = src[index];
		index++;
		i_dst++;
	}
	dst[i_dst] = '\0';
	if (i_dst >= dstsize)
		return (ft_strlen(src) + dstsize);
	else
		return (output);
}
