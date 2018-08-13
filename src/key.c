/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:27 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:14:18 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rotator.h>
#include <stdio.h>

int		handle_keys(int key, t_rotator *r)
{
	(void)r;
	if (key == 53)
	{
	//	free_all(fdf);
		exit(0);
	}
	if (key == 49)
		r->erase = (r->erase) ? 0 : 1;
	return (0);
}
