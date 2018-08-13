/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:52:39 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:34:52 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rotator.h>

int		loop_events(t_rotator *r)
{
	r->d += 1;
	if (r->d >= 45)
		r->d = 0;
	r->color += 2;
	if (r->color > 1536)
		r->color %= 1536;
	if (r->erase)
	{
		mlx_destroy_image(r->mlx, r->img->ptr);
		free(r->img);
		r->img = init_img(r->mlx);
	}
	render(r);
	return (0);
}

int		main(void)
{
	t_rotator	*r;

	r = init_rotator();
	render(r);
	mlx_loop_hook(r->mlx, loop_events, r);
	mlx_hook(r->win, 2, 0, handle_keys, r);
	mlx_loop(r->mlx);
	return (0);
}
