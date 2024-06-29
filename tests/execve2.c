/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:18:42 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/28 13:29:29 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

extern char **environ;

int	main(void)
{
	char	*argv[3];

	argv[0] = "/bin/ls";
	argv[1] = "/";
	argv[2] = NULL;

	execve(argv[0], argv, environ);

	return (EXIT_FAILURE);
}
