/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shomami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:29:40 by shomami           #+#    #+#             */
/*   Updated: 2018/08/02 15:14:06 by shomami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WID 1000
# define LEN 800
# define THREADS 8

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}		t_point;

typedef struct	s_img
{
	void		*ptr;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
}		t_img;

typedef struct	s_rotator
{
	void		*mlx;
	void		*win;
	t_img		*img;
	int		len;
	double		d;
	int		color;
	int		erase;
}		t_rotator;

typedef struct	s_thread
{
	pthread_t	tid;
	int		i;
	t_rotator	*r;
}		t_thread;

void			free_all(t_rotator *r);
t_point			new_point(int x, int y);
t_img			*init_img(void *mlx);
t_rotator		*init_rotator();
int			handle_keys(int key, t_rotator *r);
void			img_pixel_put(t_img *img, int x, int y, int color);
void			*draw(void *arg);
void			render(t_rotator *r);
int			color_select(int color, int num);

#endif
