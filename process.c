/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:51:45 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/31 16:45:50 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

static void	close_fd(t_pipex *px, int a)
{
	close(px->fd[0]);
	close(px->fd[1]);
	if (a)
	{
		close(px->infd);
		close(px->outfd);
	}
}

void	child_process(t_pipex *px, int i)
{
	char	*cmd_pt;
	char	**split_cmd;

	split_cmd = cmd_split(px->argv[i]);
	if (!split_cmd)
	{
		close_fd(px, 0);
		error_exit(px, "cmd split error", 2);
	}
	cmd_pt = cmd_path(px, split_cmd[0]);
	if (i == 2)
	{
		close(px->fd[0]);
		dup2(px->infd, STDIN_FILENO);
		dup2(px->fd[1], STDOUT_FILENO);
	}
	else
	{
		close(px->fd[1]);
		dup2(px->fd[0], STDIN_FILENO);
		dup2(px->outfd, STDOUT_FILENO);
	}
	close_fd(px, 1);
	execve(cmd_pt, split_cmd, px->envp);
	exit(1);
}
