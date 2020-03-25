/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:51:59 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 19:17:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SAMPLES 				8

# define HEIGHT					550
# define WIDTH					600

# define THREAD					16

# define H_MAIN					600
# define W_MAIN					400

# define ZERO					0.0, 0.0, 0.0
# define FALSE					0
# define TRUE					1
# define CONTINUE				0
# define STOP					1

# define SETUP					0
# define RENDER					1

# define MAIN					0
# define RENDER 				1

# define OBJ_TYPE				6

# define SPHERE					0
# define PLANE					1
# define CYLINDER				2
# define CONE					3
# define BOX					4
# define CAMERA					5

# define DIFF					0
# define SPEC					1
# define REFR					2

# define MAX_WIN	 			50

# define F_GREY					0xd1d1d1
# define F_BLUE					0x0000FF
# define F_RED					0xFF0000
# define F_GREEN				0x00FF00
# define F_WHITE				0xFFFFFF
# define F_BLACK				0x000000

# define REFRACTIVE_INDEX_OUT	1.0
# define REFRACTIVE_INDEX_IN	1.5
# define PI 					3.14159265358979323846
# define EPSILON_SPHERE			1e-4
# define GAMMA 					2.2
# define T_MIN					0.01
# define T_MAX 					1e20

typedef int 					BOOL;

#endif