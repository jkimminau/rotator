/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 00:39:29 by shomami           #+#    #+#             */
/*   Updated: 2018/03/02 01:04:20 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	if (!*needle)
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		i = 0;
		while (haystack[i] && needle[i] == haystack[i])
			i++;
		if (needle[i] == 0 && len >= i - 1)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
