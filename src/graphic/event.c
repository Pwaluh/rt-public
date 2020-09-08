/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/07 18:59:51 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void 	hook(t_rtv1 *rtv1)
{
	t_win *main;
	t_win *setting;
	t_win *image;

	main = &rtv1->main;
	setting = &rtv1->setting;
	image = &rtv1->image[rtv1->id_win];
	mlx_hook(main->win_ptr, 2, 1L << 2, key, rtv1);
	// mlx_hook(image->win_ptr, 2, 1L << 2, exit_hook, rtv1);
	mlx_hook(main->win_ptr, 6, (1L << 6), hover, rtv1);
	mlx_mouse_hook(main->win_ptr, mouse, rtv1);
}

int		exit_hook(int keycode, t_rtv1 *rtv1)
{
	t_win *win;

	win = &rtv1->image[rtv1->id_win];
	if (keycode == 53)
	{
		mlx_destroy_window(rtv1->mlx_ptr, win->win_ptr);
		exit(0);
	}
	return (EXIT_SUCCESS);
}

int 	hover(int x, int y, t_rtv1 *rtv1)
{
	if (is_hover(x, y, &rtv1->sprite.setup, 90, 181, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.retry, 181, 272, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.save, 272, 362, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.display, 362, 453, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.render, 453, 544, 0, 80))
		put_setup(rtv1);
	return (EXIT_SUCCESS);
}

int 	hover_setting(int x, int y, t_rtv1 *rtv1)
{
	if (is_hover(x, y, &rtv1->sprite.close_setting, 0, 92, 0, 80))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.sample, 92, 183, 0, 80))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.format, 183, 276, 0, 80))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x8, 0, 276, 79, 122))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x20, 0, 276, 122, 164))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x200, 0, 276, 164, 207))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x500, 0, 276, 207, 251))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x1000, 0, 276, 251, 294))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x5000, 0, 276, 294, 340))
		put_setting(rtv1);
	return (EXIT_SUCCESS);
}

int 	is_hover(int x, int y, t_button *button, int xmin, int xmax, int ymin, int ymax)
{
	BOOL		tmp;

	tmp = button->is_hover;
	button->is_hover = (x > xmin && x < xmax && y > ymin && y < ymax) ? TRUE : FALSE;
 	return ((tmp != button->is_hover) ? TRUE : FALSE);
}
