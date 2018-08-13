/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:20:58 by shomami           #+#    #+#             */
/*   Updated: 2018/03/02 01:07:26 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char*)s + len);
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		else
			s++;
	}
	return (NULL);
}
