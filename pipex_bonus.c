/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:48:47 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/30 01:32:24 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <sys/wait.h>

void	pipe_loop(int *fd, int *filed, char **argv, char **envp)
{
	int	i;
	int	pid1;
	int	pid2;
	int	pid;

	i = 2;
	pid1 = fork();
	if (pid1 == 0)
		child_one(fd, filed, envp, argv[2]);
	printf("child_one executed\n");
	while (i < filed[2] - 2)
	{
		if (pipe(fd) == -1)
			error_exit("pipe", 1);
		pid = fork();
		if (pid == 0)
			child_middle(fd, filed, envp, argv[i]);
		printf("child_%d executed\n", i);
		i++;
	}
	pid2 = fork();
	if (pid2 == 0)
		child_two(fd, filed, envp, argv[i]);
	printf("child_two executed\n");
	waitpid(pid2, NULL, 0);
}

void	pipex(char **envp, char **argv, int argc)
{
	int	fd[2];
	int	filed[3];

	filed[0] = open(argv[1], O_RDONLY);
	filed[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (filed[0] < 0 || filed[1] < 0)
		error_exit("file", 1);
	if (pipe(fd) == -1)
		error_exit("pipe", 1);
	filed[2] = argc;
	pipe_loop(fd, filed, argv, envp);
	close(filed[0]);
	close(filed[1]);
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc >= 5)
	{
		pipex(envp, argv, argc);
	}
	return (0);
}
