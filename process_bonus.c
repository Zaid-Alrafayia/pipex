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
#include "pipex_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	child_process(t_pipex *px, int i)
{
	char	*cmd_pt;
	char	**split_cmd;

	split_cmd = cmd_split(px->argv[i]);
	cmd_pt = cmd_path(px, split_cmd[0]);
	dup2(px->prev_fd, STDIN_FILENO);
	close(px->prev_fd);
	if (i == px->argc - 2)
		dup2(px->outfd, STDOUT_FILENO);
	else
	{
		dup2(px->fd[1], STDOUT_FILENO);
		close(px->fd[0]);
		close(px->fd[1]);
	}
	close(px->infd);
	close(px->outfd);
	execve(cmd_pt, split_cmd, px->envp);
	exit(1);
}
