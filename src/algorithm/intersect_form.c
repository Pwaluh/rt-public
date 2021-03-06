/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 13:41:37 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		intersect_sphere(t_obj *sphere, t_ray *ray)
{
	t_vec	oc;
	t_vec	k;
	double	tmin;

	sub(&ray->origin, &sphere->position, &oc);
	k.x = dot(&ray->direction, &ray->direction);
	k.y = 2 * dot(&oc, &ray->direction);
	k.z = dot(&oc, &oc) - sphere->radius * sphere->radius;
	tmin = quadratic(k.x, k.y, k.z);
	return (tmin);
}

double		intersect_plane(t_obj *plane, t_ray *ray)
{
	t_vec		oc;
	double		k1;
	double		k2;
	double		koef;
	double		t;

	sub(&ray->origin, &plane->position, &oc);
	koef = 1;
	t = T_MAX;
	if ((k1 = dot(&ray->direction, &plane->direction)) == 0)
		return (FALSE);
	k2 = dot(&oc, &plane->direction);
	if (k1 == k2)
		koef = -1;
	t = -k2 / k1 * koef;
	return (t);
}

double		intersect_cylinder(t_obj *cylinder, t_ray *ray)
{
	t_vec	oc;
	t_vec	k;
	double	t_min;

	sub(&ray->origin, &cylinder->position, &oc);
	k.x = dot(&ray->direction, &ray->direction)
		- pow(dot(&ray->direction, &cylinder->direction), 2);
	k.y = 2 * (dot(&ray->direction, &oc)
			- dot(&ray->direction, &cylinder->direction)
			* dot(&oc, &cylinder->direction));
	k.z = dot(&oc, &oc)
		- pow(dot(&oc, &cylinder->direction), 2)
		- cylinder->radius
		* cylinder->radius;
	t_min = check_point(&k, &ray->direction, &ray->origin, cylinder);
	return (t_min);
}

double		intersect_cone(t_obj *cone, t_ray *ray)
{
	t_vec		oc;
	t_vec		k;
	double		a;
	double		t_min;

	sub(&ray->origin, &cone->position, &oc);
	a = 1 + cone->angle * cone->angle;
	k.x = dot(&ray->direction, &ray->direction)
		- a * pow(dot(&ray->direction, &cone->direction), 2);
	k.y = 2 * (dot(&ray->direction, &oc)
		- a * dot(&ray->direction, &cone->direction)
		* dot(&oc, &cone->direction));
	k.z = dot(&oc, &oc)
		- a * pow(dot(&oc, &cone->direction), 2);
	t_min = check_point(&k, &ray->direction, &ray->origin, cone);
	return (t_min);
}
