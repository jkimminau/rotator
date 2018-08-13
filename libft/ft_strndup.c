/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:14:32 by shomami           #+#    #+#             */
/*   Updated: 2018/03/09 21:12:40 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(cpy, str, len);
	cpy[len] = '\0';
	return (cpy);
}
