/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:49:27 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/23 20:42:08 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

int		run_cmd(char *cmd_path, char **split_cmd, char **envp);
void	free_arr(char **arr);
char	*get_path(char *envp[]);
char	*check_path(char *cmd, char *envp[]);
char	**cmd_split(char *cmd);

#endif // !PIPEX_H
