/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:48:48 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/25 10:27:33 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	char_c;
	size_t	index;

	char_c = (char)c;
	if (char_c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	index = ft_strlen(s);
	while (index > 0)
	{
		index--;
		if (s[index] == char_c)
			return ((char *)(s + index));
	}
	return (NULL);
}
