/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:17:21 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/09/01 03:25:40 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	j;
	size_t	src_size;

	src_size = ft_strlen(src);
	i = 0;
	dest_len = ft_strlen(dest);
	j = dest_len;
	if (size == 0)
		return (src_size);
	if (size <= dest_len)
		return (size + src_size);
	while ((dest_len < size - 1) && src[i] != '\0')
	{
		dest[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (j + src_size);
}
