/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:10:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/24 11:14:43 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include "lib/libft.h"

# define SUCCESS	(t_bool)0
# define FAILURE	(t_bool)1
# define SEP		(char)'\n'

typedef struct	s_tetri
{
	char			*tetriminos;
	char			rank;
	uint8_t			length;
	uint8_t			width;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}				t_tetri;

typedef uint8_t	t_bool;
typedef char	t_map;

#endif
