/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:32:03 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/26 15:32:17 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE > 99999999 || BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be (0 < BUFFER_SIZE < 99999999)"
# endif

typedef enum s_error
{
	SUCCESS = 0,
	READ_ERROR = -56,
	MALLOC_ERROR = -66,
}			t_error;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	char	*bufp;
	int		n;
}			t_buf;

// main
char	*get_next_line(int fd);

// getter & filler
int		ft_getchar_fd(int fd, t_buf *buf);
int		ft_fillchar(t_string *t_str, char c);

// utils
void	*ft_memset(void *b, int c, size_t len);

#endif
