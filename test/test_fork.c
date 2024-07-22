# include "../include/pipex.h"

int	main(void)
{
	printf("start\n");
	fork();
	printf("1\n");
	fork();
	printf("2\n");
	fork();
	printf("Hello.\n");
	wait(NULL);
	return (EXIT_SUCCESS);
}
