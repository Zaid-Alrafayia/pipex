/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 03:04:40 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/09/01 03:12:17 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	if (!s3 && !s4)
		return (0);
	while (i < n && s3[i] == s4[i])
		i++;
	if (i == n)
		return (0);
	return (s3[i] - s4[i]);
}
