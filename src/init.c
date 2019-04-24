/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:24 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:14:22 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rotator.h>

void free_all(t_rotator *r)
{
	mlx_destroy_window(r->mlx, r->win);
	mlx_destroy_image(r->mlx, r->img->ptr);
	free(r->img);
	// while (fdf->map->len)
	// 	free(fdf->map->points[--fdf->map->len]);
	// free(fdf->map->points);
	// free(fdf->map);
	// free(fdf->cam);
	mlx_del(r->mlx);
	free(r);
}

t_point new_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_img *init_img(void *mlx)
{
	t_img *img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	if (!(img->ptr = mlx_new_image(mlx, WID, LEN)))
		return (0);
	img->data_addr = mlx_get_data_addr(img->ptr, &img->bpp,
									   &img->line_size, &img->endian);
	img->bpp /= 8;
	return (img);
}

t_rotator *init_rotator(void)
{
	t_rotator *r;

	if (!(r = (t_rotator *)malloc(sizeof(t_rotator))))
		return (0);
	r->mlx = mlx_init();
	r->win = mlx_new_window(r->mlx, WID, LEN, "Rotator");
	r->img = init_img(r->mlx);
	r->len = sqrt(pow(WID / 2, 2) + pow(LEN / 2, 2));
	r->d = 0;
	r->mouse = new_point(WID / 2, LEN / 2);
	r->p = new_point(r->mouse.x, r->mouse.y);
	r->color = 0;
	r->erase = 0;
	r->frames = 0;
	r->fps = 0;
	r->time = time(NULL);
	return (r);
}
