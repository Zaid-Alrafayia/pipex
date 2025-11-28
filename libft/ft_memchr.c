/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:42:26 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/09/01 02:40:07 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c1;

	i = 0;
	c1 = (unsigned char) c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == c1)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
