/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:31:09 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/26 15:31:29 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char *)b)[index] = (unsigned char)c;
		index++;
	}
	return (b);
}

int	ft_getchar_fd(int fd, t_buf *buf)
{
	if (buf->n == 0)
	{
		buf->n = read(fd, buf->buf, BUFFER_SIZE);
		if (buf->n < 0)
			return (READ_ERROR);
		buf->bufp = buf->buf;
	}
	buf->n--;
	if (buf->n >= 0)
		return ((unsigned char)*buf->bufp++);
	else
		return (EOF);
}

static int	init_t_str(t_string **t_str)
{
	if ((*t_str)->str != NULL)
		return (SUCCESS);
	(*t_str)->str = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if ((*t_str)->str == NULL)
		return (MALLOC_ERROR);
	(*t_str)->capa = BUFFER_SIZE + 1;
	(*t_str)->len = 0;
	return (SUCCESS);
}

static int	fill_t_str(t_string **t_str, char c)
{
	(*t_str)->str[(*t_str)->len] = c;
	(*t_str)->len++;
	(*t_str)->str[(*t_str)->len] = '\0';
	return (SUCCESS);
}

int	ft_fillchar(t_string *t_str, char c)
{
	char	*str_ptr;
	size_t	i;

	if (MALLOC_ERROR == init_t_str(&t_str))
		return (MALLOC_ERROR);
	if (t_str->len + 1 >= t_str->capa)
	{
		str_ptr = t_str->str;
		t_str->capa *= 2;
		t_str->str = (char *)malloc(t_str->capa * sizeof(char));
		if (t_str->str == NULL)
		{
			free(str_ptr);
			return (MALLOC_ERROR);
		}
		i = 0;
		while (i < t_str->len)
		{
			t_str->str[i] = str_ptr[i];
			i++;
		}
		free(str_ptr);
	}
	fill_t_str(&t_str, c);
	return (SUCCESS);
}
