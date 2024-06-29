/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memorymap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:37:55 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/27 18:43:35 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

extern char	**environ;

int	data0;
int	data1 = 10;

int	main(int argc, char *argv[])
{
	char	c;

	(void)argc;
	printf("environ:\t%p\n", environ);
	printf("argv:\t\t%p\n", argv);
	printf("stack:\t\t%p\n", &c);
	printf("bss:\t\t%p\n", &data0);
	printf("data:\t\t%p\n", &data1);

	return (EXIT_SUCCESS);
}
