/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere		sphere(int t, double r, t_vec p, t_vec d, t_vec e, t_vec f, int reflect)
{
	t_sphere sphere;

	sphere.t = t;
	sphere.r = r;
	sphere.p = p;
	sphere.d = d;
	sphere.e = e;
	sphere.f = f;
	sphere.reflect = reflect;
	return (sphere);
}