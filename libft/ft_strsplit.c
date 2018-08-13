/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 21:47:37 by shomami           #+#    #+#             */
/*   Updated: 2018/03/09 21:13:51 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char c)
{
	int		words;

	words = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
			words++;
		while (*str != c && *str)
			str++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		letters;
	int		current;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	current = 0;
	while (words--)
	{
		while (*s == c && *s)
			s++;
		letters = 0;
		while (s[letters] != c && s[letters])
			letters++;
		arr[current++] = ft_strndup(s, letters);
		s += letters;
	}
	arr[current] = NULL;
	return (arr);
}
