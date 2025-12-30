/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:30:23 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/23 20:45:54 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

char	*get_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]))
			&& (envp[i][0] == 'P'))
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*check_path(char *cmd, char *envp[])
{
	char	*paths;
	char	**arr;
	char	*search_path;
	int		i;
	char	*tmp;

	i = 0;
	paths = get_path(envp);
	arr = ft_split(paths, ':');
	while (arr[i])
	{
		tmp = ft_strjoin(arr[i], "/");
		search_path = ft_strjoin(tmp, cmd);
		if (access(search_path, F_OK | X_OK) != -1)
		{
			free(tmp);
			free_arr(arr);
			return (search_path);
		}
		i++;
		free(tmp);
		free(search_path);
	}
	free_arr(arr);
	return (NULL);
}
