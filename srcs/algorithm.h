/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:46:19 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/24 14:12:01 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "fillit.h"


t_bool	get_solutionsize(t_tetri *tetri, uint32_t *min_size,
		uint32_t *max_size);
t_bool	place_tetri(t_tetri *tetri, t_map map, uint32_t x, uint32_t y);

#endif
