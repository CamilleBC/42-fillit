/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:10:55 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 15:18:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SUCCESS	0
#define FAILURE	1

#include "unistd.h"

//debug
#include <stdio.h>

typedef struct	s_tetri
{
	char	*tetriminos;
	char	rank;
	int		test;
}				t_tetri;
