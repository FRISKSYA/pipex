/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:00:00 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/09 20:53:29 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// FIXME: probably dont have to exit in here.
int	ft_check_args(int argc, char **argv, t_pipex *data)
{
	int		i;
	int		flags;
	mode_t	mode;

	if (argc != 5)
		return (ARGS_ERROR);
	i = 0;
	if (access(argv[++i], F_OK | R_OK))
		data->is_invalid_infile = true;//ft_exit("INFILE_ACCESS_ERROR");
	else
		data->in_fd = open(argv[i], O_RDONLY);
	if (data->in_fd < 0)
		ft_exit("INFILE_OPEN_ERROR");
	while (i++ < argc - 2) ft_printf("%s\n", argv[i]);
	flags = O_WRONLY | O_CREAT | O_TRUNC;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (!access(argv[i], F_OK | R_OK))
	{
		data->out_fd = open(argv[i], flags, mode);
		if (!data->out_fd)
			ft_exit("OUTFILE_OPEN_ERROR");
	}
	else
		ft_exit("OUTFILE_ACCESS_ERROR");
	return (SUCCESS);
}
