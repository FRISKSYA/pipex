/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:15:56 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/09 20:13:08 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

extern char	**environ;

int	main(void)
{
	char	*argv[2];

	argv[0] = "ls";
	argv[1] = NULL;

	execve("/bin/ls", argv, environ);
	return (EXIT_FAILURE);
}
