/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:34:16 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/27 16:33:21 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size_needle;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	size_needle = ft_strlen(needle);
	while (*haystack && len >= size_needle)
	{
		if (!ft_strncmp(haystack, needle, size_needle))
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (NULL);
}
