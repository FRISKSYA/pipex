/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:57:32 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/09 20:14:09 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	close(0);
	if (dup2(fd, 0) < 0)
	{
		perror("dup2");
		close(fd);
		exit(EXIT_FAILURE);
	}

	execlp("wc", "wc", NULL);
	return (EXIT_SUCCESS);
}
