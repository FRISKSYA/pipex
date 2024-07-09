/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:00 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/08 19:42:24 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

//static int	check_cmd(char *cmd);

int	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5)
		return (ARGS_ERROR);
	i = 0;
	if (access(argv[++i], F_OK | R_OK))
		ft_exit("INFILE_ACCESS_ERROR");
//	if (check_cmd(argv[++i])
//		ft_exit("CMD_ERROR");
	while (i++ < argc - 1)
		ft_printf("%s\n", argv[i]);
	return (SUCCESS);
}
