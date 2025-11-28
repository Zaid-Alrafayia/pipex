/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:13:36 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/28 15:08:42 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*assign_digits(char *str, long num, int len, int isneg)
{
	if (num == 0)
	{
		str[--len] = '0';
	}
	while (num > 0)
	{
		str[--len] = num % 10 + '0';
		num /= 10;
	}
	if (isneg)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		isneg;
	char	*str;
	long	num;
	int		len;

	num = n;
	isneg = 0;
	if (num < 0)
	{
		isneg = 1;
		num = -num;
	}
	len = digit_count(num) + isneg;
	str = (char *) malloc((len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	assign_digits(str, num, len, isneg);
	return (str);
}
