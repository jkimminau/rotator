/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 19:53:03 by shomami           #+#    #+#             */
/*   Updated: 2018/03/09 19:32:38 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int number;

	number = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = -n;
	}
	if (number >= 10)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd((number % 10) + '0', fd);
}
