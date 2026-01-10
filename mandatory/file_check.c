/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:31:03 by zaalrafa          #+#    #+#             */
/*   Updated: 2026/01/10 15:23:51 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

void	access_file(t_pipex *px)
{
	px->infd = open(px->argv[1], O_RDONLY);
	px->outfd = open(px->argv[px->argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (px->outfd < 0 || px->infd < 0)
		error_exit(px, "file", 1);
}
