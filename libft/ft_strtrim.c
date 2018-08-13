/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 22:43:30 by shomami           #+#    #+#             */
/*   Updated: 2018/03/08 01:03:30 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		end;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = 0;
	end = 0;
	while (s[i])
	{
		while (s[i] && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			end = i++;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
	}
	return (ft_strndup(s, (size_t)end + 1));
}
