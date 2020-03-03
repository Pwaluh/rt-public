/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/03 19:41:17 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rtv1			rtv1;
	char			*file_str;

	// // Checker
	file_str = NULL;
	rtv1.ac = ac;
	rtv1.av = av;
	if (file(ac, av, &file_str))
		return (EXIT_FAILURE);

	// Default scene
	rtv1.scene.samples = 8;
	rtv1.scene.width = 640;
	rtv1.scene.height = 480;

	// Scene
	init_scene(&rtv1, file_str);

	// Window
	rtv1.mlx_ptr = mlx_init();
	rtv1.main = window(rtv1.mlx_ptr, W_MAIN, H_MAIN, "Raytracer");
	rtv1.png = init_png(rtv1.mlx_ptr);
	rtv1.state = SETUP;
	rtv1.png.h_render = FALSE;
	rtv1.png.h_cancel = FALSE;
	rtv1.png.h_save = FALSE;
	rtv1.png.h_show = FALSE;
	rtv1.id = 0;
	put_setup(&rtv1);
	hook(&rtv1);
	mlx_loop(rtv1.mlx_ptr);
	return (0);
}

int		error(char *strerror)
{
	ft_dprintf(2, "%s\n", strerror);
	return (EXIT_FAILURE);
}
