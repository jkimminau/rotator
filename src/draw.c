/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:18 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:34:16 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rotator.h>
#include <stdio.h>

void img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WID && y >= 0 && y < LEN)
		*(int *)(img->data_addr + ((x + y * WID) * img->bpp)) = color;
}

void draw_line(t_rotator *r, t_point p1, t_point p2)
{
	double d[2];
	double x;
	double y;
	double inc;

	d[0] = (p2.x - p1.x);
	d[1] = (p2.y - p1.y);
	inc = (fabs(d[0]) > fabs(d[1])) ? fabs(d[0]) : fabs(d[1]);
	x = p1.x;
	y = p1.y;
	while ((fabs(x - p2.x) >= 1 || fabs(y - p2.y) >= 1) && (x >= 0 && x < WID && y >= 0 && y < LEN))
	{
		img_pixel_put(r->img, (int)x, (int)y,
					  color_select(r->color, sqrt(pow(fabs(x - p1.x), 2) + pow(fabs(y - p1.y), 2)) / r->len * 1536));
		x += (d[0] / inc);
		y += (d[1] / inc);
	}
}

// void *draw(void *arg) //void *thread)
// {
// 	t_point p1;
// 	t_point p2;
// 	t_rotator *r;
// 	int i;

// 	r = ((t_thread *)(arg))->r;
// 	i = ((t_thread *)(arg))->i;
// 	p1.x = WID / 2;
// 	p1.y = LEN / 2;
// 	p2.x = p1.x + (r->len * sin(M_PI / 180 * (r->d + i * 45)));
// 	p2.y = p1.y - (r->len * cos(M_PI / 180 * (r->d + i * 45)));
// 	draw_line(r, p1, p2);
// 	return (NULL);
// }

void *draw(void *arg)
{
	t_rotator *r;
	t_point p;
	double x, y;

	r = ((t_thread *)(arg))->r;
	p.x = ((t_thread *)(arg))->i;
	p.y = 0;
	x = r->p.x;
	y = r->p.y;

	while (p.y < LEN)
	{
		double angle = (atan2(p.y, p.x) - atan2(0, 1)) * 180 / M_PI;
		img_pixel_put(r->img, p.x, p.y, color_select(r->color, sqrt(pow(fabs(x - p.x), 2) + pow(fabs(y - p.y), 2)) * angle));
		p.x += THREADS;
		if (p.x >= WID)
		{
			p.y += p.x / WID;
			p.x = p.x % WID;
		}
	}
	return (NULL);
}

void render(t_rotator *r)
{
	time_t tmp;
	t_thread list[THREADS];
	int i;

	i = 0;
	while (i < THREADS)
	{
		list[i].i = i;
		list[i].r = r;
		pthread_create(&(list[i]).tid, NULL, draw, &list[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(list[i++].tid, NULL);
	mlx_put_image_to_window(r->mlx, r->win, r->img->ptr, 0, 0);
	//mlx_string_put(r->mlx, r->win, 0, 0, 0, ft_itoa(r->fps));
	r->frames++;

	if ((r->time != (tmp = time(NULL))))
	{
		r->time = tmp;
		r->fps = r->frames;
		r->frames = 0;
	}
}
