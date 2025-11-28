/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:13:46 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:18:32 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(small);
	i = 0;
	if (*small == '\0')
	{
		return ((char *)big);
	}
	while (big[i] && ((i + j) <= len))
	{
		if (ft_strncmp(&big[i], small, j) == 0)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
