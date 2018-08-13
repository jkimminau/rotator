/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 20:49:35 by shomami           #+#    #+#             */
/*   Updated: 2018/03/07 23:57:58 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	num;
	char			*str;
	int				sign;

	if (n == 0 || n == -0)
		return ((str = ft_strdup("0")));
	i = ft_numlen(n);
	num = 0;
	sign = n < 0 ? 1 : 0;
	if (!(str = (char *)malloc(sizeof(char) * (i + sign + 1))))
		return (NULL);
	str[i + sign] = '\0';
	str[0] = n < 0 ? '-' : 0;
	n = n < 0 ? -n : n;
	num = n;
	while (num)
	{
		str[(i - 1) + sign] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (str);
}
