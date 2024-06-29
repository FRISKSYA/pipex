/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:18:42 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/28 13:24:18 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

extern char **environ;

int	main(int argc, char **argv)
{
	(void)argc;
	argv++;

	execve(argv[0], argv, environ);

	return (EXIT_FAILURE);
}
