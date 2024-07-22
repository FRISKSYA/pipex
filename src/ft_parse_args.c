/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:59:36 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/22 14:59:02 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// TODO: parse cmd_args to (char ***)t_pipex.cmd_args
int	ft_parse_args(int argc, char **argv, t_pipex *data)
{
	int		i;
	
	(void)argc;
	(void)argv;
	data->cmd_args = (char ***)malloc(3 * sizeof(char **));
	if (data->cmd_args == NULL)
		ft_exit("MALLOC_ERROR");
	data->cmd_args[2] = NULL;
	data->cmd_args[0] = ft_split(argv[2], ' ');
	data->cmd_args[1] = ft_split(argv[3], ' ');
	i = 0;
	while (data->cmd_args[0][i])
	{
		ft_printf("args[0][%d] : %s\n", i, data->cmd_args[0][i]);
		i++;
	}
	i = 0; 
	while (data->cmd_args[1][i])
	{
		ft_printf("args[1][%d] : %s\n", i, data->cmd_args[1][i]);
		i++;
	}
	return (0);
}
