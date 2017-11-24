/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:39:35 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/24 11:31:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	get_solutionsize(t_tetri *tetri, uint32_t *min_size,
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

static t_bool	place_tetri(t_tetri *tetri, t_map *map, uint32_t location)
{
	uint32_t i;

	if (tetri[i] 
}
