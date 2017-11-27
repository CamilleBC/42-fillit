/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:54:39 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/27 10:27:16 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fillit.h"

t_bool	get_solutionsize(t_tetri *tetri, uint32_t *min_size,
		uint32_t *max_size);
t_bool	place_tetri(t_tetri *tetri, t_map *map, uint32_t x, uint32_t y);

#endif
