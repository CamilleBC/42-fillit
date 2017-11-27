/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:50:21 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/27 10:35:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "map.h"

/*
** DEBUG
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	*itoa(int value, char *result, int base)
{
	char	*ptr;
	char	*ptr1;
	char	tmp_char;
	int tmp_value;

	ptr = result;
	ptr1 = result;
	if (base < 2 || base > 36) { *result = '\0'; return result; }
	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789\
			abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}

static int	print_padleftzeroes(const char *s, size_t width)
{
	size_t n = strlen(s);
	if(width < n)
		return -1;
	while(width > n)
	{
		putchar('0');
		width--;
	}
	fputs(s, stdout);
	putchar('\n');
	return 0;
}

int			main(void)
{
	t_tetri		tetri;
	t_map		map;
	uint32_t	*map_ptr;
	uint32_t	map_data[8] = {
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000,
		0b01000000};
	char		binary[33];
	int			i1;
	int			i2;
	int			i3;

	tetri.tetriminos[0] = 0b0001;
	tetri.tetriminos[1] = 0b0011;
	tetri.tetriminos[2] = 0b0010;
	tetri.tetriminos[3] = 0b0000;
	tetri.length = 3;
	tetri.width = 2;
	map_ptr = map_data;
	map.map = &map_ptr;
	map.size = 8;
	printf("Empty map:\n");
	i1 = 0;
	while (i1 < 8)
	{
		itoa((*map.map)[i1], binary, 2);
		print_padleftzeroes(binary, 8);
		i1++;
	}
	printf("Tetriminos:\n");
	i2 = 0;
	while (i2 < 4)
	{
		itoa(tetri.tetriminos[i2], binary, 2);
		print_padleftzeroes(binary, 4);
		i2++;
	}
	place_tetri(&tetri, &map, 0, 0);
	printf("Filled map:\n");
	i3 = 0;
	while (i3 < 8)
	{
		itoa((*map.map)[i3], binary, 2);
		print_padleftzeroes(binary, 8);
		i3++;
	}
	return (0);
}
