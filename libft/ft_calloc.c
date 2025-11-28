/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:30:07 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/09/02 14:18:49 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*arr;

	if (n == 0 || size == 0)
		return (NULL);
	arr = malloc(n * size);
	if (!arr)
		return (0);
	ft_bzero(arr, n * size);
	return (arr);
}
