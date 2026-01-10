/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:06:42 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/10 15:25:02 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex_bonus.h"

int	has_path(char *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*cmd_path(t_pipex *px, char *cmd)
{
	char	*path;

	if (has_path(cmd))
	{
		if (access(cmd, F_OK | X_OK) == -1)
			return (NULL);
		path = cmd;
	}
	else
		path = check_path(px, cmd);
	return (path);
}
