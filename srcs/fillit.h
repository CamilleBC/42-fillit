/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille Baillat <cbaillat@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:10:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/04 11:39:50 by Camille Bai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
#include "../lib/libft.h"

/*
** DEBUG
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define SUCCESS	(t_bool)0
# define FAILURE	(t_bool)1
# define TETRI_SIZE	(uint8_t)4
# define SEP		(char)'\n'

typedef struct		s_tetri
{
	uint32_t		tetriminos[4];
	uint8_t			rank;
	uint8_t			length;
	uint8_t			width;
	uint8_t			x;
	uint8_t			y;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	uint32_t		*map;
	uint8_t			size;
}					t_map;

typedef uint8_t		t_bool;

// DEBUG:
void	debug_map(t_map map);
char	*itoa_base(int value, char *result, int base);
void	print_tetriminos(t_tetri *tetri);

#endif
