/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:49:53 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/27 16:34:57 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	char	*str;
	size_t	index;

	if (s == NULL)
		return (NULL);
	size_s = ft_strlen(s);
	if (start >= size_s || len == 0)
		return (get_empty_str());
	if (len >= size_s - (size_t)start)
		str = (char *)malloc((size_s - (size_t)start + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[start] != '\0' && index < len)
		str[index++] = s[start++];
	str[index] = '\0';
	return (str);
}
