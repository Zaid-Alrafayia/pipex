/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:35:30 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/13 17:39:16 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int	point_conv(unsigned long num)
{
	char	*arr;
	int		j;

	j = num_len(num);
	if (num == 0)
		return (write(1, "(nil)", 5));
	arr = (char *)malloc((j + 1) * sizeof(char));
	if (!arr)
		return (0);
	arr[j--] = '\0';
	ft_putstr_fd("0x", 1);
	while (num != 0)
	{
		if (num % 16 < 10)
			arr[j] = (num % 16 + '0');
		else if (num % 16 >= 10)
			arr[j] = (num % 16 + 'a' - 10);
		num = num / 16;
		j--;
	}
	ft_putstr_fd(arr, 1);
	j = ft_strlen(arr);
	free(arr);
	return (j + 2);
}
