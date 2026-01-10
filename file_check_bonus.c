/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:31:03 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/12/30 21:11:55 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "pipex_bonus.h"
#include <fcntl.h>

void	lim_handler(t_pipex *px)
{
	char	*str;
	size_t	len;
	int		fd[2];

	if (pipe(fd) == -1)
		error_exit(px, "pipe", 1);
	len = ft_strlen(px->argv[2]);
	while (1)
	{
		ft_printf("here_doc> ");
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_strncmp(str, px->argv[2], len) == 0 && str[len] == '\n')
		{
			free(str);
			break ;
		}
		write(fd[1], str, ft_strlen(str));
		free(str);
	}
	close(fd[1]);
	px->infd = fd[0];
}

void	access_file(t_pipex *px)
{
	if (px->here_doc)
	{
		lim_handler(px);
		px->outfd = open(px->argv[px->argc - 1], O_WRONLY | O_CREAT | O_APPEND,
				0644);
	}
	else
	{
		px->infd = open(px->argv[1], O_RDONLY);
		px->outfd = open(px->argv[px->argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				0644);
	}
	if (px->outfd < 0 || px->infd < 0)
		error_exit(px, "file", 1);
}
