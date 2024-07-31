/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:03:19 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/25 15:52:03 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// libs
# include "../util/ft_printf/ft_printf.h"
# include "../util/libft/libft.h"
# include "../util/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>

# define NUM_CMD 2

typedef enum	s_syserror
{
	EXEC_FAILURE = 126,
}				t_syserror;

typedef struct	s_pipex
{
	pid_t	childs[2];
	int		in_fd;
	int		out_fd;
	char	**env;
	char	***cmd_args;
	int		status;
	size_t	num_cmd;
}				t_pipex;

// main
void	init_pipex(int argc, char **argv, char **env, t_pipex *data);
void	execute_cmd(t_pipex *data, size_t i, int *pipe_fd);
int		ft_cleanup(t_pipex *data);

// sub
void	ft_exit(t_pipex *data, char *error_msg);

#endif
