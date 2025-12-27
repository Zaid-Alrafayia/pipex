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
#include <unistd.h>

// int	fork_cmd(char *path_cmd1, char *path_cmd2, char **envp, char *input)
//{
//	int	fid;
//	int	fd[2];
//	int	afd;
//
//	afd = open(input, O_RDONLY);
//	if (pipe(fd) == -1)
//	{
//		perror("pipe error");
//		return (0);
//	}
//	fid = fork();
//	if (fid == 0)
//	{
//		close(fd[0]);
//		dup2(afd, fd[1]);
//		write(fd[1], &afd, 4);
//		ft_printf("%s\n", get_next_line(afd));
//		ft_printf("fid = 0\n");
//		run_cmd(path_cmd2, envp);
//
//	}
//	else
//	{
//		ft_printf("%s\n", get_next_line(fd[1]));
//		ft_printf("fid = 1\n");
//		run_cmd(path_cmd1, envp);
//		pipe(fd);
//	}
//	return (0);
//}

int	main(int argc, char *argv[], char *envp[])
{
	char	*path_cmd1;
	char	*path_cmd2;
	char	**split_cmd;
	int		fd[2];

	if (argc >= 2)
	{
		path_cmd1 = check_path(argv[2], envp);
		path_cmd2 = check_path(argv[3], envp);
		split_cmd = cmd_split(argv[2]);
		// fork_cmd(path_cmd1, path_cmd2, envp, argv[1]);
		run_cmd(path_cmd1, split_cmd, envp);
		free(path_cmd1);
	}
	return (0);
}
