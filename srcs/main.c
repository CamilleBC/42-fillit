/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:50:21 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/24 17:08:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "algorithm.h"
#include "../lib/libft.h"
// DEBUG
#include <stdio.h>
#include <stdlib.h>

char* itoa(int value, char* result, int base) {
// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789\
			abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );

// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}

int	main(void)
{
	t_tetri		tetri;
	t_map		map;
	uint32_t	*map_ptr;
	uint32_t	map_data[8] = {0};
	char		binary[33];
	int			i1;
	int			i2;

	tetri.tetriminos[0] = 0b0100;
	tetri.tetriminos[1] = 0b1100;
	tetri.tetriminos[2] = 0b1000;
	tetri.tetriminos[3] = 0b0000;
	tetri.length = 3;
	tetri.width = 2;
	map_ptr = map_data;
	map = &map_ptr;

	printf("Empty map:\n");
	i1 = 0;
	while (i1 < 8)
	{
		itoa((*map)[i1], binary, 2);
		printf("%s\n", binary);
		i1++;
	}
	place_tetri(&tetri, map, 1, 1);
	printf("Filled map:\n");
	i2 = 0;
	while (i2 < 8)
	{
		itoa((*map)[i1], binary, 2);
		printf("%s\n", binary);
		i2++;
	}
	return (0);
}
