/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:58:19 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 19:50:40 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	loading_text(t_render *render)
{
	float 	pourcent;
	char 	*s;

	pourcent = 100 * render->y / (HEIGHT - 1);
	ft_printf("\r%us %d%%", render->samples, (int)pourcent);
	s = ft_itoa((int)pourcent);
	mlx_string_put(render->win.mlx_ptr, render->win.win_ptr, 10, 4, F_BLACK, s);
}
