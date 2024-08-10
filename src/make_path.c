/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:30:51 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/10 18:48:15 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	is_home_path(const char *path)
{
	if (!path)
		return (false);
	if (ft_strncmp(path, "~/", 2) == 0)
		return (true);
	else
		return (false);
}

char	*join_dir_cmd(char *prefix, char *cmd)
{
	char	*prev;
	char	*cmd_path;

	prev = ft_strjoin(prefix, "/");
	if (prev == NULL)
		return (NULL);
	cmd_path = ft_strjoin(prev, cmd);
	free(prev);
	return (cmd_path);
}

// FIXME:  "HOME=" = 5 char
// FIXME:  "~/" = 2 char
void	replace_home_path(char **path, char **env)
{
	size_t	i;
	char	*home;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		home = ft_strnstr(env[i], "HOME=", 5);
		if (home)
		{
			home = home + 5;
			tmp = *path;
			tmp = tmp + 2;
			*path = join_dir_cmd(home, tmp);
			tmp = tmp - 2;
			free(tmp);
			return ;
		}
		i++;
	}
}

bool	is_full_path(const char *path)
{
	if (!path)
		return (false);
	if (
		(ft_strncmp(path, "/", 1) == 0)
		|| (ft_strncmp(path, "../", 3) == 0)
		|| (ft_strncmp(path, "./", 2) == 0)
	)
		return (true);
	else
		return (false);
}
