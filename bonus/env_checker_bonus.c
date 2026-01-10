/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:30:23 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/10 15:24:48 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex_bonus.h"
#include <unistd.h>

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

char	*search_func(char *search_path, char **arr, char *cmd)
{
	int		j;
	char	*tmp;

	j = 0;
	while (arr[j])
	{
		tmp = ft_strjoin(arr[j], "/");
		search_path = ft_strjoin(tmp, cmd);
		if (access(search_path, F_OK | X_OK) != -1)
		{
			free(tmp);
			free_arr(arr);
			return (search_path);
		}
		j++;
		free(tmp);
		free(search_path);
	}
	return (NULL);
}

char	*check_path(t_pipex *px, char *cmd)
{
	char	*paths;
	char	**arr;
	char	*search_path;

	search_path = NULL;
	paths = get_path(px->envp);
	if (!paths)
		return (NULL);
	arr = ft_split(paths, ':');
	if (!arr)
	{
		close_fd(px, 0);
		return (NULL);
	}
	search_path = search_func(search_path, arr, cmd);
	if (search_path)
		return (search_path);
	free_arr(arr);
	return (NULL);
}
