/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:18:42 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/09 20:13:40 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

extern char **environ;

int	main(int argc, char **argv)
{
	(void)argc;
	argv++;

	execve(argv[0], argv, environ);

	return (EXIT_FAILURE);
}
