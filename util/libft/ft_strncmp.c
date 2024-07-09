/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:27:19 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/04/16 12:30:06 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	unsigned int	i;

	if (n == 0)
		return (0);
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 1;
	while (*s1_ptr != '\0' && *s2_ptr != '\0' && i < n)
	{
		if (*s1_ptr != *s2_ptr)
		{
			break ;
		}
		s1_ptr++;
		s2_ptr++;
		i++;
	}
	return (*s1_ptr - *s2_ptr);
}
