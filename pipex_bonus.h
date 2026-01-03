/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:49:27 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/01 02:01:44 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infd;
	int		outfd;
	int		fd[2];
	int		argc;
	int		prev_fd;
	char	**argv;
	char	**envp;
	int		here_doc;
}			t_pipex;
// file_check.c
void		access_file(t_pipex *px);

// cmd.c
int			run_cmd(char *cmd_path, char **split_cmd, char **envp);
void		error_exit(char *msg, int code);
char		**cmd_split(char *cmd);
void		error_cmd(char **arr);

// env_checker.c
char		*get_path(char *envp[]);
void		free_arr(char **arr);
char		*check_path(t_pipex *px, char *cmd);

// process.c
void		child_process(t_pipex *px, int i);
#endif // !PIPEX_H
