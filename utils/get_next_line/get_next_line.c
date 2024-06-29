/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:29:06 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/26 15:29:12 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_free(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		return (NULL);
	}
	return (NULL);
}

static int	prepare_t_str(t_string *t_str)
{
	t_str->str = NULL;
	t_str->len = 0;
	t_str->capa = 0;
	return (SUCCESS);
}

static int	ft_init_buf(t_buf *buf)
{
	ft_memset(buf->buf, 0, BUFFER_SIZE);
	buf->n = 0;
	buf->bufp = buf->buf;
	return (SUCCESS);
}

char	*get_next_line(int fd)
{
	t_string		t_str;
	char			c;
	static t_buf	buf;

	if (fd < 0)
		return (NULL);
	prepare_t_str(&t_str);
	while (1)
	{
		c = ft_getchar_fd(fd, &buf);
		if (c == READ_ERROR || c == EOF)
		{
			ft_init_buf(&buf);
			if (c == READ_ERROR)
				return (ft_free(&t_str.str));
			break ;
		}
		if (MALLOC_ERROR == ft_fillchar(&t_str, c))
			return (ft_free(&t_str.str));
		if (c == '\n')
			break ;
	}
	if (t_str.len > 0 && SUCCESS == ft_fillchar(&t_str, '\0'))
		return (t_str.str);
	return (ft_free(&t_str.str));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		printf("SUCCESS\n");
// 	}
// 	close(fd);
// 	printf("2nd start\n");
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		printf("SUCCESS\n");
// 	}
// 	return (0);
// }
