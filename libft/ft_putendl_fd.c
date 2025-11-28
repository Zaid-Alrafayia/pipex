/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:24:31 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:12:27 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
//void	ft_putendl_fd(char *s, int fd)
//{
//	int	i;
//
//	i = 0;
//	if (!s)
//		return ;
//	while (s[i])
//	{
//		write(fd, &s[i], 1);
//		i++;
//	}
//	write(fd, "\n", 1);
//}
