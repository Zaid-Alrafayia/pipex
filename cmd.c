/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:35:56 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/31 16:44:53 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <unistd.h>

int	run_cmd(char *cmd_path, char **split_cmd, char **envp)
{
	return (execve(cmd_path, split_cmd, envp));
}

void	error_cmd(char **arr)
{
	if (arr && arr[0])
	{
		ft_putstr_fd("command not found:  ", 2);
		ft_putendl_fd(arr[0], 2);
		free_arr(arr);
	}
	else
	{
		ft_putendl_fd("command not found", 2);
	}
	exit(127);
}

void	error_exit(t_pipex *px, char *msg, int code)
{
	close(px->infd);
	close(px->outfd);
	perror(msg);
	exit(code);
}

char	**cmd_split(char *cmd)
{
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	return (split_cmd);
}
