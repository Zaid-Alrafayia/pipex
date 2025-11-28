/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:39:21 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/13 14:36:21 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int num)
{
	int	count;

	count = 0;
	if (num < 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	print_num(int n, int fd)
{
	char	buff[12];
	int		i;
	int		size;

	size = num_len(n);
	i = size;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	buff[i--] = '\0';
	if (n < 0)
		buff[0] = '-';
	while (n != 0)
	{
		buff[i] = ft_abs(n % 10) + 48;
		n /= 10;
		i--;
	}
	ft_putstr_fd(buff, fd);
	return (size);
}
