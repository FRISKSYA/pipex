/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:15:56 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/28 13:17:13 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

extern char	**environ;

int	main(void)
{
	char	*argv[2];

	argv[0] = "ls";
	argv[1] = NULL;

	execve("/bin/ls", argv, environ);
	return (EXIT_FAILURE);
}
