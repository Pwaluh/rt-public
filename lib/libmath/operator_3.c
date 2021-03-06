/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:14:35 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 17:19:07 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void		multin(double n, t_vec *v1, t_vec *dest)
{
	vec(n * v1->x, n * v1->y, n * v1->z, dest);
}

void		nmulti_(t_vec *v1, double n)
{
	v1->x *= n;
	v1->y *= n;
	v1->z *= n;
}

void		divide(t_vec *v1, t_vec *v2, t_vec *dest)
{
	vec(v1->x / v2->x, v1->y / v2->y, v1->z / v2->z, dest);
}

void		ndivide(t_vec *v1, double n, t_vec *dest)
{
	double a;

	a = 1.0 / n;
	vec(v1->x * a, v1->y * a, v1->z * a, dest);
}

void		divide3(double a, t_vec *v, t_vec *dest)
{
	vec(a / v->x, a / v->y, a / v->z, dest);
}
