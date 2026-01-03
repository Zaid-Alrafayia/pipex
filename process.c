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

void	child_process(t_pipex *px, int i)
{
	char	*cmd_path;
	char	**split_cmd;

	split_cmd = cmd_split(px->argv[i]);
	cmd_path = check_path(px, split_cmd[0]);
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
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->infd);
	close(px->outfd);
	execve(cmd_path, split_cmd, px->envp);
	exit(1);
}
