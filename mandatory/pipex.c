/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:10:25 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/10 15:24:21 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"
#include <sys/wait.h>
#include <unistd.h>

void	pipex(t_pipex *px)
{
	int	pid1;
	int	pid2;

	if (pipe(px->fd) == -1)
		error_exit(px, "pipex", 2);
	pid1 = fork();
	if (pid1 == 0)
		child_process(px, 2);
	pid2 = fork();
	if (pid2 == 0)
		child_process(px, 3);
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->outfd);
	close(px->infd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
		return (1);
	}
	px.argc = argc;
	px.argv = argv;
	px.envp = envp;
	access_file(&px);
	pipex(&px);
	return (0);
}
