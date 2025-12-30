/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:48:47 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/30 01:32:24 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **envp, char **argv)
{
	int	fd[2];
	int	filed[2];
	int	pid1;
	int	pid2;

	filed[0] = open(argv[1], O_RDONLY);
	filed[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (filed[0] < 0 || filed[1] < 0)
		error_exit("file", 1);
	if (pipe(fd) == -1)
		error_exit("pipe", 1);
	pid1 = fork();
	if (pid1 == 0)
		child_one(fd, filed, envp, argv);
	pid2 = fork();
	if (pid2 == 0)
		child_two(fd, filed, envp, argv);
	close(filed[0]);
	close(filed[1]);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
	{
		pipex(envp, argv);
	}
	return (0);
}
