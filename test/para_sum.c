/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_sum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:30:55 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/06/29 17:16:29 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	int	arr[] = {1, 2, 3 , 4, 1, 2, 7};
	int	arrSize = sizeof(arr) / sizeof(int);
	int	start, end;
	int	fd[2];

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);

	int	id = fork();
	if (id == -1)
		return (EXIT_FAILURE);

	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	int	sum = 0;
	int	i;

	for (i = start; i < end; i++)
		sum += arr[i];
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return (EXIT_FAILURE);
		close(fd[1]);
		printf("Caluculated partial sum: %d\n", sum);
	}
	else
	{
		if (wait(NULL) < 0)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		
		int	sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
			return (EXIT_FAILURE);
		close(fd[0]);
		printf("Caluculated partial sum: %d\n", sum);

		int	totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		
	}
	return (EXIT_SUCCESS);
}
