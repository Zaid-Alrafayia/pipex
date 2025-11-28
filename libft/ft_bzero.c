/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa < zaalrafa@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:14:37 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/31 16:40:16 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}
