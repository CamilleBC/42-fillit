/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:10:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 15:38:00 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS	0
#define FAILURE	1

#include "unistd.h"
#include "stdlib.h"

typedef struct	s_tetri
{
	char			*tetriminos;
	char			rank;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}				t_tetri;
