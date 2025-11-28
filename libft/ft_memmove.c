/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:06:13 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/09/01 02:56:39 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (!s && !d)
		return (NULL);
	if (s > d)
	{
		i = 0;
		while (n > i)
		{
			d[i] = s[i];
			i++;
		}
		return (d);
	}
	i = n;
	while (0 < i)
	{
		i--;
		d[i] = s[i];
	}
	return (d);
}
