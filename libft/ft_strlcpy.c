/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:01:58 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:17:30 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(src);
	i = 0;
	if (n == 0)
	{
		return (size);
	}
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (size);
}
