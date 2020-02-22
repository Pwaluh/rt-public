/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 18:05:22 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_pixel_vector(t_rtv1 *rtv1, int x, int y, t_vec *v)
{
	t_win *win;
	unsigned int i;

	win = &rtv1->image;
	i = (int)(x * 4 + win->size_line * y);
	if (x <= rtv1->scene.width)
		if (y <= rtv1->scene.height)
		{
			win->data_ptr[i] = (char)to_byte(v->x, GAMMA);
			win->data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			win->data_ptr[i + 2] = (char)to_byte(v->z, GAMMA);
		}
}