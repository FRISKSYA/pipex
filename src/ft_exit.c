// TODO: Stdheader

#include "../include/pipex.h"

void	cleanup_cmd_args(char ***cmd_args)
{
	size_t	i;
	size_t	j;

	if (!cmd_args)
		return ;
	else
	{
		i = 0;
		while (cmd_args[i])
		{
			j = 0;
			while (cmd_args[i][j])
			{
				free(cmd_args[i][j]);
				j++;
			}
			free(cmd_args[i]);
			i++;
		}
	}
	free(cmd_args);
}

void	ft_cleanup(t_pipex *data)
{
	// TODO: close FDs
	if (data && data->cmd_args)
		cleanup_cmd_args(data->cmd_args);
	if (data && data->childs)
		free(data->childs);
	if (data)
		free(data);
}

void	ft_exit(t_pipex *data, char *error_msg)
{
	int	status;

	if (!data && !error_msg)
		exit(EXIT_FAILURE);
	if (!data && error_msg)
	{
		perror(error_msg);
		exit(EXIT_FAILURE);
	}
	status = data->status;
	ft_cleanup(data);
	if (error_msg)
		perror(error_msg);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(EXIT_FAILURE);
}
