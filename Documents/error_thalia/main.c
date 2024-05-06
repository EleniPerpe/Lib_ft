/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:18:40 by tsimitop          #+#    #+#             */
/*   Updated: 2024/04/28 15:27:24 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	status = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			handle_error("pipe");
		pid = fork();
		fork_failure(pid);
		if (pid == 0)
			child1_process(fd, argv, env);
		pid = fork();
		fork_failure(pid);
		if (pid == 0)
			child2_process(fd, argv, env);
		close_fd(fd);
		waitpid(pid, &status, 0);
		status = handle_exit(status);
	}
	else
		proper_input();
	return (status);
}

void	proper_input(void)
{
	write(1, "A\n", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
