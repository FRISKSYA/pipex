/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:34:06 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/27 16:23:45 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;

	if (count > 0 && size > SIZE_MAX / count)
		return (NULL);
	output = (void *)malloc(count * size);
	if (output == NULL)
		return (NULL);
	return (ft_memset(output, 0, count * size));
}
