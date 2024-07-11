/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:00:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/10 13:08:02 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, const char ** const env)
{
	t_pipex	*data;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
			ft_printf("env[%d] : %s\n", i, env[i]);
		i++;
	}
	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (data == NULL)
		ft_exit("MALLOC_ERROR");
	ft_init_pipex(data);
	if (ft_check_args(argc, argv, data) == ARGS_ERROR)
		ft_exit("ARGS_ERROR");
	// ft_parse_cmds();
	// ft_parse_args();
	// while (cmds)
	//	ft_exec();
	ft_cleanup(data);
	return (EXIT_SUCCESS);
}
