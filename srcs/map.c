/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:53:32 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/27 12:48:14 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*
** TODO: Delete max-size ?
** We add the total length and width of all tetriminos. Whichever is the biggest
** is our max_size. Don't know if it is useful.
** By multiplying the number of elements by 4, we get the minimal surface,
** and then by squarng it, we get the sides' size.
*/

t_bool	get_map_minsize(t_tetri *tetri, t_map *map)
{
	uint32_t	elements;

	elements = 0;
	map->size = 0;
	if (tetri == NULL)
		return (FAILURE);
	while (tetri->next != NULL)
	{
		tetri = tetri->next;
		++elements;
	}
	map->size = ft_sqrt(elements << 2);
	return (SUCCESS);
}

/*
** We AND the map with the tetri.
** We need to offset the check because we are trying to place in the top-left
** corner.
** We get 1 only if there is something on the map already.
** If so, we return a failure.
*/

t_bool	check_map(t_tetri tetri, t_map map)
{
	uint32_t	i;
	uint32_t	map_offset;

	i = 0;
	map_offset = map.size - tetri.width - tetri.x;
	while ((tetri.y + i) < (tetri.y + tetri.length))
	{
		if ((*map.map)[tetri.y + i] & (tetri.tetriminos[i] << map_offset))
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}

/*
** We XOR the map with the tetri.
** We need to offset the check because we are trying to place in the top-left
** corner.
** We get 1 if there is the piece and nothing on the map.
** We get 1 if there is nothing for the piece but something on the map.
** Else we have 0.
*/

t_bool	set_map(t_tetri tetri, t_map *map)
{
	uint32_t	i;
	uint32_t	map_offset;

	if (check_map(tetri, *map) != SUCCESS)
		return (FAILURE);
	i = 0;
	map_offset = map->size - tetri.width - tetri.x;
	while ((tetri.y + i) < (tetri.y + tetri.length))
	{
		(*map->map)[tetri.y + i] = (*map->map)[tetri.y + i]
								^ (tetri.tetriminos[i] << map_offset);
		++i;
	}
	return (SUCCESS);
}

void	unset_map(t_tetri tetri, t_map *map)
{
	uint32_t	i;
	uint32_t	map_offset;

	i = 0;
	map_offset = map->size - tetri.width - tetri.x;
	while ((tetri.y + i) < (tetri.y + tetri.length))
	{
		(*map->map)[tetri.y + i] = (*map->map)[tetri.y + i]
								^ (tetri.tetriminos[i] << map_offset);
		++i;
	}
}
