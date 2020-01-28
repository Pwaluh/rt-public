/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/28 18:53:15 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		specular_reflect(t_vec *d, t_vec *n, t_vec *dest)
{
	t_vec a;

	nmulti(n, 2.0 * dot(n, d), &a);
	sub(d, &a, dest);
}

t_vec		specular_transmit(t_vec *d, t_vec *n, double n_out, double n_in, double *pr, unsigned short xseed[3])
{
	t_vec	d_re;
	BOOL	out_to_in;
	t_vec	nl;
	double	nn;
	double	cos_theta;
	double	cos2_phi;
	t_vec 	a;
	t_vec	b;
	t_vec	d_tr;
	double 	c;
	double	re;
	double	p_re;
	double	tr;
	double	p_tr;

	specular_reflect(d, n, &d_re);
	out_to_in = (dot(n, d) < 0) ? TRUE : FALSE;
	if (out_to_in)
		nl = *n;
	else
		minus(n, &nl);
	nn = out_to_in ? n_out / n_in : n_in / n_out;
	cos_theta = dot(d, &nl);
	cos2_phi = 1.0 - nn * nn * (1.0 - cos_theta * cos_theta);
	if (0.0 > cos2_phi)
	{
		*pr = 1.0;
		return (d_re);
	}
	nmulti(d, nn, &a);
	nmulti(&nl, (nn * cos_theta + sqrt(cos2_phi)), &a);
	sub(&a, &b, &d_tr);
	norm(&d_tr);
	c = 1.0 - (out_to_in ? -cos_theta : dot(&d_tr, n));
	re = schlick_reflectance(n_out, n_in, c);
	p_re = 0.25 + 0.5 * re;
	if (erand48(xseed) < p_re)
	{
		*pr = (re / p_re);
		return (d_re);
	}
	else
	{
		tr = 1.0 - re;
		p_tr = 1.0 - p_re;
		*pr = (tr / p_tr);
		return (d_tr);
	}
}

t_vec	hemisphere_ray(t_radiance *radiance, t_vec w, unsigned short seed, float alpha)
{
	double	phi;
	double	sint;
	double	cost;
	t_vec	u;
	t_vec	v;
	t_vec 	d;
	t_vec 	z;
	t_vec	tmp;
	t_vec	a;
	t_vec	b;
	t_vec	c;
	t_vec	ep;
	t_vec	res;

	z = vecp(0.00424, 1, 0.00764);
	phi = 2.0 * M_PI_F * rand_ri(&seed);
	cost = pow((1.0 - rand_ri(&seed)), 1.0 / (alpha + 1.0));
	sint = sqrt(1.0 - cost * cost);
	cross(&z, &w, &tmp);
	u = *norm(&tmp);
	cross(&w, &u, &v);
	nmulti(&u, sint, &a);
	nmulti_(&a, cos(phi));
	nmulti(&v, sin(phi), &b);
	nmulti_(&b, sint);
	nmulti(&w, cost, &c);
	sum(&a, &b, &ep);
	sum(&ep, &c, &res);
	d = *norm(&res);
	if (dot(radiance->n, &d) < 0.0)
	{
		nmulti(&u, -(sint * cos(phi)), &a);
		nmulti_(&a, cos(phi));
		nmulti(&v, sin(phi), &b);
		nmulti_(&b, sint);
		nmulti(&w, cost, &c);
		sub(&a, &b, &ep);
		sum(&ep, &c, &res);
		d = *norm(&res);
	}
	return (d);
}
