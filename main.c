/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:48:47 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/23 22:49:04 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	fork_cmd(char **split_cmd1, char **split_cmd2, char **envp, char **argv)
{
	int		fid;
	int		fd[2];
	int		infd;
	char	*path_cmd1;
	char	*path_cmd2;
	int		pid;
	int		outfd;

	path_cmd1 = check_path(split_cmd1[0], envp);
	path_cmd2 = check_path(split_cmd2[0], envp);
	infd = open(argv[1], O_RDONLY);
	outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipe(fd);
	fid = fork();
	if (fid == 0)
	{
		close(fd[0]);
		dup2(infd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(infd);
		close(outfd);
		run_cmd(path_cmd1, split_cmd1, envp);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfd, STDOUT_FILENO);
		close(infd);
		close(outfd);
		run_cmd(path_cmd2, split_cmd2, envp);
	}
	close(infd);
	close(outfd);
	close(fd[0]);
	close(fd[1]);
	waitpid(fid, NULL, 0);
	waitpid(pid, NULL, 0);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**split_cmd1;
	char	**split_cmd2;

	if (argc == 5)
	{
		split_cmd1 = cmd_split(argv[2]);
		split_cmd2 = cmd_split(argv[3]);
		fork_cmd(split_cmd1, split_cmd2, envp, argv);
	}
	return (0);
}
