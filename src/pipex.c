/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:00:52 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/08 19:16:54 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*data;

	data = (t_pipex *)malloc(sizeof(t_pipex));
	if (data == NULL)
		ft_exit("MALLOC_ERROR");
	ft_init_pipex(data);
	if (ft_check_args(argc, argv) == ARGS_ERROR)
		ft_exit("ARGS_ERROR");
	// ft_parse_cmds();
	// ft_parse_args();
	// while (cmds)
	//	ft_exec();
	ft_cleanup(data);
	ft_printf("hello\n");
	return (EXIT_SUCCESS);
}
