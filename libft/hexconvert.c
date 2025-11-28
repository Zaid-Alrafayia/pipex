/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexconvert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 00:55:17 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/13 18:17:04 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned int num)
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

static char	hex_char(unsigned int num, char deli)
{
	if (num % 16 < 10)
		return (num % 16 + '0');
	else if (num % 16 >= 10 && deli == 'X')
		return (num % 16 + 'A' - 10);
	else
		return (num % 16 + 'a' - 10);
}

int	hex_convert(char deli, unsigned int num)
{
	char	*arr;
	int		j;
	int		len;

	if (num == 0)
		return (write(1, "0", 1));
	len = num_len(num);
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	j = 0;
	while (num != 0)
	{
		arr[j] = hex_char(num, deli);
		num = num / 16;
		j++;
	}
	arr[j] = '\0';
	while (--j >= 0)
		write(1, &arr[j], 1);
	free(arr);
	return (len);
}
