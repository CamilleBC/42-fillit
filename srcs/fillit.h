/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:10:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 13:09:27 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define TETRI_STRING	(uint8_t)21
# define SUCCESS		(t_bool)0
# define FAILURE		(t_bool)1
# define TETRI_SIZE		(uint8_t)4
# define SEP			(char)'\n'

typedef struct    s_point
{
    int						x;
    int						y;
}                t_point;

typedef struct		s_tetri
{
	uint32_t		tetriminos[4];
	char			rank;
	uint8_t			length;
	uint8_t			width;
	uint8_t			x;
	uint8_t			y;
}					t_tetri;

typedef struct		s_map
{
	uint32_t		*map;
	uint8_t			size;
}					t_map;

typedef uint8_t		t_bool;

#endif
