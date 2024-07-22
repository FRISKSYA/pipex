/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:11:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/07/09 20:13:05 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

extern char	**environ;

int	main(void)
{
	char	*argv[2];

	argv[0] = "/bin/ls";
	argv[1] = NULL;

	execve(argv[0], argv, environ);
	
	return (EXIT_FAILURE);
}
