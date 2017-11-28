/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:50:21 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/28 17:08:52 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "map.h"
#include "algorithm.h"

char	*itoa(int value, char *result, int base)
{
	char	*ptr;
	char	*ptr1;
	char	tmp_char;
	int		tmp_value;

	ptr = result;
	ptr1 = result;
	if (base < 2 || base > 36)
	{
		*result = '\0';
		return (result);
	}
	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789\
			abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
	}
	while (value);
	if (tmp_value < 0)
		*ptr++ = '-';
	*ptr-- = '\0';
	while (ptr1 < ptr)
	{
		tmp_char = *ptr;
		*ptr-- = *ptr1;
		*ptr1++ = tmp_char;
	}
	return (result);
}

static int	print_padleftzeroes(const char *s, size_t width)
{
	size_t n;

	n = strlen(s);
	if (width < n)
		return (-1);
	while (width > n)
	{
		putchar('0');
		width--;
	}
	fputs(s, stdout);
	putchar('\n');
	return (0);
}

void	print_map(t_map map)
{
	uint32_t	i;
	char		binary[33];

	printf("Map:\n");
	i = 0;
	while (i < map.size)
	{
		itoa(map.map[i], binary, 2);
		print_padleftzeroes(binary, map.size);
		++i;
	}
	printf("\n");
}

static void	print_tetriminos(t_tetri *tetri)
{
	uint32_t	i;
	uint32_t	j;
	char		binary[33];

	i = 1;
	while (tetri != NULL)
	{
		j = 0;
		printf("Tetriminos %02d:\n", i);
		while (j < 4)
		{
			itoa(tetri->tetriminos[j], binary, 2);
			print_padleftzeroes(binary, 4);
			++j;
		}
		printf("\n");
		++i;
		tetri = tetri->next;
	}
}

int			main(void)
{
	t_tetri		tetri1;
	t_tetri		tetri2;
	t_tetri		tetri3;
	t_tetri		tetri4;
	t_map		map;
	int			i1;

	tetri1.tetriminos[0] = 0b0001;
	tetri1.tetriminos[1] = 0b0011;
	tetri1.tetriminos[2] = 0b0010;
	tetri1.tetriminos[3] = 0b0000;
	tetri1.length = 3;
	tetri1.width = 2;
	tetri1.x = 0;
	tetri1.y = 0;
	tetri1.prev = NULL;
	tetri1.next = &tetri2;

	tetri2.tetriminos[0] = 0b0001;
	tetri2.tetriminos[1] = 0b0111;
	tetri2.tetriminos[2] = 0b0000;
	tetri2.tetriminos[3] = 0b0000;
	tetri2.length = 2;
	tetri2.width = 3;
	tetri2.x = 0;
	tetri2.y = 0;
	tetri2.prev = &tetri1;
	tetri2.next = &tetri3;

	tetri3.tetriminos[0] = 0b0001;
	tetri3.tetriminos[1] = 0b0111;
	tetri3.tetriminos[2] = 0b0000;
	tetri3.tetriminos[3] = 0b0000;
	tetri3.length = 2;
	tetri3.width = 3;
	tetri3.x = 0;
	tetri3.y = 0;
	tetri3.prev = &tetri2;
	tetri3.next = &tetri4;
	
	tetri4.tetriminos[0] = 0b0001;
	tetri4.tetriminos[1] = 0b0111;
	tetri4.tetriminos[2] = 0b0000;
	tetri4.tetriminos[3] = 0b0000;
	tetri4.length = 2;
	tetri4.width = 3;
	tetri4.x = 0;
	tetri4.y = 0;
	tetri4.prev = &tetri3;
	tetri4.next = NULL;

	// DEBUG
	system("clear");
	print_tetriminos(&tetri1);
	sleep(4);
	system("clear");
	// DEBUG

	map.map = NULL;
	map.size = get_map_minsize(&tetri1);
	while (1)
	{
		printf("Size = %d\n", map.size);
		create_map(&map);
		if (solve_map(&tetri1, &map) == SUCCESS)
		{
			free(map.map);
			break ;
		}
		map.size += 1;
	}
	return (SUCCESS);
}
