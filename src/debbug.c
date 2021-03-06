/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 19:38:28 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		loading_text(t_scene *scene, int y)
{
	ft_printf("\r%3.0f%%", 100.0 * y / (scene->height - 1));
}

char		*stamp(void)
{
	time_t		now;
	char		*stamp;
	int			i;

	i = -1;
	now = time(NULL);
	stamp = ctime(&now);
	stamp[ft_strlen(stamp) - 1] = '\0';
	while (stamp[++i])
		if (stamp[i] == ' ')
			stamp[i] = '-';
	if (stamp[8] == '-')
		stamp[8] = '0';
	ft_strcat(stamp, ".ppm");
	return (stamp);
}

void		timer(int time)
{
	int		second;
	int		minute;
	int		hour;

	second = 0;
	minute = 0;
	hour = 0;
	while (time)
		if (time > 60 * 60)
		{
			hour++;
			time -= 60 * 60;
		}
		else if (time > 60)
		{
			minute++;
			time -= 60;
		}
		else
		{
			second++;
			time--;
		}
	ft_printf(" -> %.2d:%.2d:%.2d", hour, minute, second);
}

void		printr(t_ray *r)
{
	ft_printf("o: [%f %f %f]\nd: [%f %f %f]\n", r->origin.x,
												r->origin.y,
												r->origin.z,
												r->direction.x,
												r->direction.y,
												r->direction.z);
}

void		printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
