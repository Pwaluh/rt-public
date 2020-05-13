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

# define THREAD					16

# define H_MAIN					275
# define W_MAIN					300

# define BLANK					0.0, 0.0, 0.0
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

# define GAMMA 					2.2
# define T_MIN					0.01
# define T_MAX 					1e20

# define NORMAL					-1
# define RIGHT					0
# define LEFT					1
# define TOP					2
# define BOTTOM					3
# define FRONT					4
# define BACK					5


# define MINI(X, Y) 				(((X) < (Y)) ? (X) : (Y))
# define MAXI(X, Y) 				(((X) > (Y)) ? (X) : (Y))

typedef int 					BOOL;

#endif
