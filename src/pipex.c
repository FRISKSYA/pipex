/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:00:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/22 15:05:15 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
//	// TODO: remove it.
//	while (env[i])
//	{
//		if (ft_strnstr(env[i], "PATH", 4))
//			ft_printf("env[%d] : %s\n", i, env[i]);
//		i++;
//	}

// TODO: compare with bash, its probably need not to exit.
// STEPS:
//	1: init_pipex
//	2: parse_args
//	3: execute cmds
//	4: cleanup_pipex
int	main(int argc, char **argv) //, const char ** const env)
{
	t_pipex	*data;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (data == NULL)
		ft_exit("MALLOC_ERROR");
	ft_init_pipex(data);
	if (ft_check_args(argc, argv, data) == ARGS_ERROR)
		ft_exit("ARGS_ERROR");
	ft_parse_args(argc, argv, data);
	// while (cmds)
	//	ft_exec();
	ft_cleanup(data);
	return (EXIT_SUCCESS);
}
