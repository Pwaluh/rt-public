/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/17 22:07:15 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_window(char **av, t_win *win)
{
	win->mlx_ptr = mlx_init();
	if (!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, av[1])))
		return (EXIT_FAILURE);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->data_ptr = mlx_get_data_addr(win->img_ptr,
			&(win->bits_per_pixel),
			&(win->size_line),
			&(win->endian));
	mlx_hook(win->win_ptr, 2, 1L << 2, key, win);
	mlx_expose_hook(win->win_ptr, expose_hook, win);
	mlx_loop(win->mlx_ptr);
	return (EXIT_SUCCESS);
}

int		key(int keycode, t_win *win)
{
	if (keycode == 53)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	erase(win);
	return (EXIT_SUCCESS);
}

void	erase(t_win *win)
{
	ft_bzero(win->data_ptr, HEIGHT * WIDTH * 4);
	expose_hook(win);
}

int		expose_hook(t_win *win)
{
	rtv1(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

void	put_pixel(t_win *win, int x, int y, t_vec *v)
{
	unsigned int i;

	i = (int)(x * 4 + win->size_line * y);
	if ((unsigned int)x < WIDTH && (unsigned int)x > 0)
		if ((unsigned int)y < HEIGHT && (unsigned int)y > 0)
		{
			//ft_printf("%d %d %d\n", to_byte(v->x, GAMMA), to_byte(v->y, GAMMA), to_byte(v->z, GAMMA));
			win->data_ptr[i] = (char)to_byte(v->x, GAMMA);
			win->data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			win->data_ptr[i + 2] = (char)to_byte(v->z, GAMMA);
		}
}
