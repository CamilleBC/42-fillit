/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:23:23 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/30 21:14:22 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

/*
** We need to initialize the map with '.' and '\n' for every printed lines
*/

static void	initialize_map(char **map_ptr, uint8_t size)
{
	char	*map_string;
	size_t	i;

	ft_memset(*map_ptr, '.', (size * (size + 1)));
	i = 1;
	while (i <= size)
	{
		(*map_ptr)[(i * (size + 1)) - 1] = '\n';
		++i;
	}
}

/*
** We mask the tetri at the coordinate we need to print.
** If we get a positive number, we write the letter.
** We calculate the coordinates using the coordinates of the tetri, and add an
** offset because we write in a 1D string.
*/

static void	print_tetri(t_tetri tetri, uint8_t size, char **map_str)
{
	uint8_t		i;
	uint8_t		j;
	uint16_t	tetri_offset;
	uint16_t	map_index;

	i = 0;
	printf("%c\n\n", tetri.rank);
	while (i < tetri.length)
	{
		j = 0;
		tetri_offset = tetri.tetriminos[i] >> (TETRI_SIZE - tetri.width);
		while (j < tetri.width)
		{
			if (0x01 & (tetri_offset >> j))
			{
				map_index =  (tetri.y + i) * (size + 1) + (tetri.x + (tetri.width - j))- 1;
				(*map_str)[map_index] = 'A' + tetri.rank;
				printf("%c\n", (*map_str)[map_index]);
			}
			++j;
		}
		++i;
	}
}

/*
** We create a string that is big enough to store all the tetris, and the \n
** that we will use to print the map.
** Then we print all tetris in this string by replacing the default character by
** the corresponding rank character in the structure.
*/

void	print_map(t_map map, t_tetri *list)
{
	char	**map_ptr;
	char	*map_string;

	if (list == NULL)
		return ;
	if ((map_string = ft_strnew(map.size * (map.size + 1))) == NULL)
		return ;
	map_ptr = &map_string;
	initialize_map(map_ptr, map.size);
	printf("%snn", map_string);
	while (list->next != NULL)
	{
		print_tetri(*list, map.size, map_ptr);
		list = list->next;
	}
	//printf("%s", map_string);
	//ft_putstr(map_string);
	free(map_string);
}
