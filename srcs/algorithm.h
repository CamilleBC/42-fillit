/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:46:19 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/28 13:42:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "fillit.h"
# include "map.h"

t_bool	place_tetri(t_tetri *tetri, t_map *map, uint32_t x, uint32_t y);
t_bool	solve_map(t_tetri *tetris, t_map *map);

#endif
