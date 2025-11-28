/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:42:55 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/13 17:24:39 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	print_unum(unsigned int n, int fd)
{
	char	buff[12];
	int		i;
	int		size;

	size = num_len(n);
	i = size;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	buff[i--] = '\0';
	while (n != 0)
	{
		buff[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	ft_putstr_fd(buff, fd);
	return (size);
}
