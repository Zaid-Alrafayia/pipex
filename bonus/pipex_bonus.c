/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:10:25 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/10 15:25:10 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex_bonus.h"

void	pipe_loop(t_pipex *px, int i)
{
	int	pid;

	while (i < px->argc - 1)
	{
		if (i < px->argc - 2)
		{
			if (pipe(px->fd) == -1)
				error_exit(px, "pipex", 2);
		}
		pid = fork();
		if (pid == 0)
			child_process(px, i);
		close(px->prev_fd);
		if (i < px->argc - 2)
		{
			close(px->fd[1]);
			px->prev_fd = px->fd[0];
		}
		i++;
	}
}

void	pipex(t_pipex *px)
{
	int	i;
	int	start;

	if (px->here_doc)
		start = 3;
	else
		start = 2;
	i = start;
	px->prev_fd = px->infd;
	pipe_loop(px, i);
	close(px->outfd);
	i = start;
	while (i++ < px->argc - 1)
		wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc <= 5)
	{
		ft_putendl_fd("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
		return (1);
	}
	if (!ft_strncmp(argv[1], "here_doc", 10))
		px.here_doc = 1;
	else
		px.here_doc = 0;
	px.argc = argc;
	px.argv = argv;
	px.envp = envp;
	if (!*argv[1] || !*argv[2] || !*argv[3] || !*argv[4] || !*argv[4])
	{
		ft_putendl_fd("Usage: ./pipex infile cmd1 cmd2 outfile", 2);
		return (1);
	}
	access_file(&px);
	pipex(&px);
	return (0);
}
