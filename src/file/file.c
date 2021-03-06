/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 11:08:58 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		file(int ac, char **av, char **file_str)
{
	char	*filename;
	int		fd;
	int		size;

	if ((ac > 1 && check(ac, av)))
		return (error("usage: ./rtv1 [file.rt]"));
	else if (ac == 1)
		filename = "scenes/default.rt";
	else
		filename = av[1];
	if ((size = get_file_size(filename)) < 0)
		return (error("./rtv1 Open fail"));
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (error("./rtv1 Open fail"));
	if ((*file_str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (error("./rtv1 Malloc error"));
	ft_bzero(*file_str, size + 1);
	if ((read(fd, *file_str, size)) == 0)
		return (error("./rtv1: File empty"));
	close(fd);
	return (EXIT_SUCCESS);
}

int		check(int ac, char **av)
{
	int i;

	i = ft_strlen(av[1]);
	if (ac && ac != 2)
		return (EXIT_FAILURE);
	if (i < 4 ||
		av[1][i - 3] != '.' ||
		av[1][i - 2] != 'r' ||
		av[1][i - 1] != 't')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
