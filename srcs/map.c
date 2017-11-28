/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:53:32 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/28 17:07:01 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*
** By multiplying the number of elements by 4, we get the minimal surface,
** and then by squarng it, we get the sides' size.
*/

uint32_t	get_map_minsize(t_tetri *tetri)
{
	uint32_t	elements;

	elements = 1;
	if (tetri == NULL)
		return (FAILURE);
	while (tetri->next != NULL)
	{
		tetri = tetri->next;
		++elements;
	}
	printf("elements = %d\n", elements);
	return (ft_sqrt(elements << 2));
}

t_bool		create_map(t_map *map)
{
	uint32_t	i;

	if (map->map != NULL)
		free(map->map);
	if ((map->map = (uint32_t *)malloc(sizeof(map->map) * map->size))
			== NULL)
		return (FAILURE);
	i = 0;
	while (i < map->size)
	{
		map->map[i] = 0;
		i++;
	}
	return (SUCCESS);
}

/*
** We AND the map with the tetri.
** We need to offset the check because we are trying to place in the top-left
** corner.
** We get 1 only if there is something on the map already.
** If so, we return a failure.
*/

t_bool		check_map(t_tetri tetri, t_map map, uint32_t x, uint32_t y)
{
	uint32_t	i;
	uint32_t	map_offset;

	i = 0;
	map_offset = map.size - tetri.width - x;
	while (i < tetri.length)
	{
		if (map.map[y + i] & (tetri.tetriminos[i] << map_offset))
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

t_bool		place_on_map(t_tetri tetri, t_map *map, uint32_t x, uint32_t y)
{
	uint32_t	i;
	uint32_t	map_offset;

	i = 0;
	map_offset = map->size - tetri.width - x;
	while (i < tetri.length)
	{
		map->map[y + i] ^= tetri.tetriminos[i] << map_offset;
		++i;
	}
	return (SUCCESS);
}
