/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:00:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/08/02 16:17:27 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// TODO: dev
static int	fill_cmd_args(char ***cmd_args, char **argv)
{
	if (!cmd_args && !argv)
		perror("just debug\n");
	return (EXIT_SUCCESS);
}

static void	init_pipex(t_pipex **data, int argc, char **argv, char **env)
{
	size_t	i;

	if (argc != 5)
		ft_exit(NULL, "init_pipex : must be 5.");
	*data = (t_pipex *)malloc(sizeof(t_pipex));
	if (!(*data))
		ft_exit(NULL, "init_pipex : data is NULL.");
	(*data)->childs = (pid_t *)malloc(2 * sizeof(pid_t));
	if (!(*data)->childs)
		ft_exit(*data, "init_pipex : data->childs is NULL.");
	i = 0;
	while (i < 2)
		(*data)->childs[i++] = 0;
	(*data)->env = env;
	// TODO: remove it;
	(*data)->cmd_args = NULL;
	if (fill_cmd_args((*data)->cmd_args, argv) != EXIT_SUCCESS)
		ft_exit(*data, "init_pipex : fill_cmd_args is failure.");
	(*data)->status = 0;
}

// STEPS:
int	main(int argc, char **argv, char **env)
{
	t_pipex	*data;

	init_pipex(&data, argc, argv, env);
	ft_cleanup(data);
	return (EXIT_SUCCESS);
}
