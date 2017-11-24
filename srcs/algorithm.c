/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:39:35 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/24 15:14:55 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	get_solutionsize(t_tetri *tetri, uint32_t *min_size,
		uint32_t *max_size)
{
	uint32_t	elements;
	uint32_t	max_width;
	uint32_t	max_length;

	elements = 0;
	*min_size = 0;
	*max_size = 0;
	max_length = 0;
	max_width = 0;
	if (tetri == NULL)
		return (FAILURE);
	while (tetri->next != NULL)
	{
		++elements;
		max_length += tetri->length;
		max_width += tetri->width;
	}
	*max_size = (max_length > max_width) ? max_length : max_width;
	*min_size = elements << 2;
	return (SUCCESS);
}

/*
** We AND the map with the tetri.
** We get 1 only if there is something on the map already.
** If so, we return a failure.
*/

static t_bool	check_map(t_tetri *tetri, t_map map, uint32_t x, uint32_t y)
{
	uint32_t i;

	i = 0;
	while ((y + i) < (y + tetri->length))
	{
		if (tetri->tetriminos[i] & ((*map)[y+i] << x))
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}

/*
** We XOR the map with the tetri.
** We get 1 if there is the piece and nothing on the map.
** We get 1 if there is nothing for the piece but something on the map.
** Else we have 0.
*/

t_bool	place_tetri(t_tetri *tetri, t_map map, uint32_t x, uint32_t y)
{
	uint32_t i;
	uint32_t map_offset;

	if (check_map(tetri, map, x, y) != SUCCESS)
			return (FAILURE);
	i = 0;
	while ((y + i) < (y + tetri->length))
	{
		map_offset = (*map)[y + i] << x;
		map_offset ^= tetri->tetriminos[i];
		++i;
	}
	return (SUCCESS);
}
