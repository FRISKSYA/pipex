/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:03:19 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 22:12:33 by kfukuhar         ###   ########.fr       */
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

typedef enum s_exit_status
{
	CMD_NO_PERMISSION = 126,
	CMD_NOT_FOUND = 127,
}			t_exit_status;

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
int		execve_full_path(char **cmd_args, char **env);
void	execve_relative_path(char **cmd_args, char **env);

// support funcs;
bool	is_home_path(const char *path);
char	*join_dir_cmd(char *prefix, char *cmd);
void	replace_home_path(char **path, char **env);
bool	is_full_path(const char *path);
void	print_command_not_found(char *cmd);

// exit funcs
void	ft_cleanup(t_pipex *data);
void	ft_exit(t_pipex *data, char *error_msg);
void	cleanup_cmd_args(char ***cmd_args);

#endif
