/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille Baillat <cbaillat@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:39:35 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/04 16:07:40 by Camille Bai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

/*
** 1- try to place tetris inside the smallest map, everytime using the up-left
** corner
** 3- The first solution found has to be the one with all the pieces in the top
** left corner.
** 2- If there are no solution, return failure.
**
** x + width <= to size because if we have a width of 2, it can go in a map
** size 2
*/

t_bool	solve_map(t_tetri *tetris, t_map *map)
{
	uint32_t	x;
	uint32_t	y;

	if (tetris == NULL)
		return (SUCCESS);
	y = 0;
	while (y + tetris->length <= map->size)
	{
		x = 0;
		while (x + tetris->width <= map->size)
		{
			if (check_map(*tetris, *map, x, y) == SUCCESS)
			{
				// ft_putstr("\nPLACING...\n");
				place_on_map(tetris, map, x, y);
				if (solve_map(tetris->next, map) == SUCCESS)
					return (SUCCESS);
				else
				{
					// ft_putstr("\nREMOVING...\n");
					place_on_map(tetris, map, x, y);
				}
			}
			++x;
		}
		++y;
	}
	return (FAILURE);
}
