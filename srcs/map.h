/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:54:39 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/27 12:41:23 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fillit.h"

t_bool	check_map(t_tetri tetri, t_map map);
t_bool	get_solutionsize(t_tetri *tetri, uint32_t *min_size,
		uint32_t *max_size);
t_bool	set_map(t_tetri tetri, t_map *map);
void	unset_map(t_tetri tetri, t_map *map);

#endif
