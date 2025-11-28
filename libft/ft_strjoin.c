/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:48:48 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:16:50 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*newstr;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *) malloc ((s1_len + s2_len + 1) * sizeof(char));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, s1, s1_len + 1);
	ft_strlcat(newstr, s2, s1_len + s2_len + 1);
	return (newstr);
}
