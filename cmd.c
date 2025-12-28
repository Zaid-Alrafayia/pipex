/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:35:56 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/24 08:44:53 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex.h"

int	run_cmd(char *cmd_path, char **split_cmd, char **envp)
{
	return (execve(cmd_path, split_cmd, envp));
}

char	**cmd_split(char *cmd)
{
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	return (split_cmd);
}
