/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:03:19 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 14:46:52 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// libs
# include "../util/ft_printf/ft_printf.h"
# include "../util/get_next_line/get_next_line.h"
# include "../util/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	**argv;
	pid_t	*childs;
	int		pipe_fd[2];
	char	**env;
	char	***cmd_args;
	int		status;
}			t_pipex;

// execute_cmd funcs
void	execute_cmd(t_pipex *data);
void	do_cmd(t_pipex *data, size_t i);

// exit funcs
void	ft_cleanup(t_pipex *data);
void	ft_exit(t_pipex *data, char *error_msg);
void	cleanup_cmd_args(char ***cmd_args);

#endif
