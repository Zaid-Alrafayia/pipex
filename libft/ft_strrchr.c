/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 23:10:50 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/09/01 00:57:31 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	i--;
	while (s[i] && i >= 0)
	{
		if (s[i] == (char) c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
