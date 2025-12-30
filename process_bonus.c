/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:56:16 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/30 01:24:10 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	child_one(int *fd, int *filed, char **envp, char *argv)
{
	char	**split_cmd1;
	char	*path_cmd1;

	split_cmd1 = cmd_split(argv);
	path_cmd1 = check_path(split_cmd1[0], envp);
	if (!path_cmd1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(split_cmd1[0], 2);
		exit(127);
		free(path_cmd1);
		free_arr(split_cmd1);
	}
	close(fd[0]);
	dup2(filed[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(filed[0]);
	close(fd[1]);
	close(filed[1]);
	run_cmd(path_cmd1, split_cmd1, envp);
	exit(1);
}

void	child_middle(int *fd, int *filed, char **envp, char *argv)
{
	char	**split_cmd1;
	char	*path_cmd1;

	split_cmd1 = cmd_split(argv);
	path_cmd1 = check_path(split_cmd1[0], envp);
	if (!path_cmd1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(split_cmd1[0], 2);
		exit(127);
		free(path_cmd1);
		free_arr(split_cmd1);
	}
	close(fd[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(filed[0]);
	close(fd[1]);
	close(filed[1]);
	run_cmd(path_cmd1, split_cmd1, envp);
	exit(1);
}

void	child_two(int *fd, int *filed, char **envp, char *argv)
{
	char	**split_cmd2;
	char	*path_cmd2;

	split_cmd2 = cmd_split(argv);
	path_cmd2 = check_path(split_cmd2[0], envp);
	if (!path_cmd2)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(split_cmd2[0], 2);
		exit(127);
		free_arr(split_cmd2);
		free(path_cmd2);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(filed[1], STDOUT_FILENO);
	close(filed[0]);
	close(fd[0]);
	close(filed[1]);
	run_cmd(path_cmd2, split_cmd2, envp);
	exit(1);
}
