/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:59:22 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/30 15:25:02 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		else
			set++;
	}
	return (0);
}

static char	*get_empty_str(void)
{
	return (ft_strdup(""));
}

static char	*ft_alloc_strtrim(char const *s1, size_t i_head, size_t i_tail)
{
	char	*str;
	size_t	i_str;

	str = (char *)malloc((i_tail - i_head + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i_str = 0;
	while (i_tail != 0 && i_head <= i_tail)
	{
		str[i_str] = s1[i_head];
		i_str++;
		i_head++;
	}
	str[i_str] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_head;
	size_t	i_tail;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i_head = 0;
	if (ft_strlen(s1) == 0)
		return (get_empty_str());
	else
		i_tail = ft_strlen(s1) - 1;
	while (i_head < i_tail && ft_isset(s1[i_head], set) == 1)
		i_head++;
	while (i_tail >= i_head && ft_isset(s1[i_tail], set) == 1)
		i_tail--;
	str = ft_alloc_strtrim(s1, i_head, i_tail);
	return (str);
}
