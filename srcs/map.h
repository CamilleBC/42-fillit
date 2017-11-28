/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:54:39 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/28 16:55:27 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fillit.h"

t_bool		check_map(t_tetri tetri, t_map map, uint32_t x, uint32_t y);
t_bool		create_map(t_map *map);
uint32_t	get_map_minsize(t_tetri *tetri);
t_bool		place_on_map(t_tetri tetri, t_map *map, uint32_t x, uint32_t y);
void		unset_map(t_tetri tetri, t_map *map);

#endif
