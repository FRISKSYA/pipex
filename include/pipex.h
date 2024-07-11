/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:03:19 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/09 20:16:08 by kfukuhar         ###   ########.fr       */
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

typedef struct	s_pipex
{
	int		in_fd;
	int		out_fd;
	bool	here_doc;
	bool	is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}				t_pipex;

typedef enum	s_pipex_error
{
	ARGS_ERROR = -1,
}				t_pipex_error;

// main
void	ft_init_pipex(t_pipex *data);
int		ft_check_args(int argc, char **argv, t_pipex *data);
int		ft_parse_cmds(t_pipex *data);
int		ft_parse_args(t_pipex *data);
int		ft_exec(t_pipex *data);
int		ft_cleanup(t_pipex *data);

// sub
void	ft_exit(char *error_msg);

#endif
