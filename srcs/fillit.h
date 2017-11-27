/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:10:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/27 12:03:26 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft.h"

# define SUCCESS	(t_bool)0
# define FAILURE	(t_bool)1
# define SEP		(char)'\n'

typedef struct		s_tetri
{
	uint32_t		tetriminos[4];
	char			rank;
	uint8_t			length;
	uint8_t			width;
	uint8_t			x;
	uint8_t			y;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

typedef struct		s_map
{
	uint32_t		**map;
	uint8_t			size;
}					t_map;

typedef uint8_t		t_bool;

#endif
