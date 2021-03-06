/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/21 19:50:56 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_pixel_vector(t_rtv1 *rtv1, int x, int y, t_vec *v)
{
	t_win	*win;
	size_t	i;

	win = &rtv1->image[rtv1->id_win_to_print];
	i = (x * win->bits_per_pixel / 8) + (y * win->size_line);
	if (x < rtv1->scene.width)
	{
		if (y < rtv1->scene.height)
		{
			win->data_ptr[i + 2] = (char)to_byte(v->x, GAMMA);
			win->data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			win->data_ptr[i] = (char)to_byte(v->z, GAMMA);
		}
	}
}

t_vec	get_pixel_vector(t_texture *texture, int x, int y, int type)
{
	size_t	i;
	t_vec	dest;

	vec(0.0, 0.0, 0.0, &dest);
	if (type == TEXTURE && x < texture->width && y < texture->height)
	{
		if (x < 0 || y < 0)
			return (dest);
		i = ((x * texture->bits_per_pixel) / 8) + (y * texture->size_line);
		dest.x = (unsigned char)(texture->data[i + 2]) / 255.0;
		dest.y = (unsigned char)(texture->data[i + 1]) / 255.0;
		dest.z = (unsigned char)(texture->data[i]) / 255.0;
	}
	else if (type == ENVIRONMENT)
	{
		i = ((x * texture->bits_per_pixel) / 8) + (y * texture->size_line);
		dest.x = (unsigned char)(texture->data[i + 2]) / 255.0;
		dest.y = (unsigned char)(texture->data[i + 1]) / 255.0;
		dest.z = (unsigned char)(texture->data[i]) / 255.0;
	}
	return (dest);
}
