/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:51:47 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 14:49:23 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rotator.h>

int			color_select(int color, int num)
{
	color += num;
	color %= 1536;
	if (color >= 0 && color < 256)
		color = 0xFF0000 + (color << 8);
	else if (color >= 256 && color < 512)
		color = 0xFFFF00 - ((color % 256) << 16);
	else if (color >= 512 && color < 768)
		color = 0x00FF00 + ((color % 256));
	else if (color >= 512 && color < 1024)
		color = 0x00FFFF - ((color % 256) << 8);
	else if (color >= 512 && color < 1280)
		color = 0x0000FF + ((color % 256) << 16);
	else if (color >= 512 && color < 1536)
		color = 0xFF00FF - ((color % 256));
	return (color);
}
