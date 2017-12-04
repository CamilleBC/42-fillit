/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille Baillat <cbaillat@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:02:39 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/04 18:32:05 by Camille Bai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "map.h"
#include "algorithm.h"
#include "output.h"

char	*itoa_base(int value, char *result, int base)
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

void	print_tetriminos(t_tetri *tetri)
{
	uint32_t	i;
	uint32_t	j;
	char		binary[33];

	i = 1;
	while (tetri != NULL)
	{
		 j = 0;
		printf("Tetriminos %02d X: %d\n", i, tetri->x);
		printf("Tetriminos %02d Y: %d\n", i, tetri->y);
		// while (j < 4)
		// {
			// itoa_base(tetri->tetriminos[j], binary, 2);
			// ft_putstr_padzeroes(binary, 4);
			// ++j;
		// }
		++i;
		tetri = tetri->next;
	}
}

void	debug_map(t_map map)
{
	uint32_t	i;
	char		binary[33];

	ft_putstr("Map:\n");
	i = 0;
	while (i < map.size)
	{
		itoa_base(map.map[i], binary, 2);
		ft_putstr_padzeroes(binary, map.size);
		++i;
	}
}

int			main(void)
{
	t_tetri		tetri1;
	t_tetri		tetri2;
	t_tetri		tetri3;
	t_tetri		tetri4;
	t_map		map;

	tetri1.tetriminos[0] = 0b0010;
	tetri1.tetriminos[1] = 0b0011;
	tetri1.tetriminos[2] = 0b0001;
	tetri1.tetriminos[3] = 0b0000;
	tetri1.rank = 0;
	tetri1.length = 3;
	tetri1.width = 2;
	tetri1.next = &tetri2;

	tetri2.tetriminos[0] = 0b0001;
	tetri2.tetriminos[1] = 0b0111;
	tetri2.tetriminos[2] = 0b0000;
	tetri2.tetriminos[3] = 0b0000;
	tetri2.rank = 1;
	tetri2.length = 2;
	tetri2.width = 3;
	tetri2.next = &tetri3;

	tetri3.tetriminos[0] = 0b0010;
	tetri3.tetriminos[1] = 0b0011;
	tetri3.tetriminos[2] = 0b0010;
	tetri3.tetriminos[3] = 0b0000;
	tetri3.rank = 2;
	tetri3.length = 3;
	tetri3.width = 2;
	tetri3.next = &tetri4;
	
	tetri4.tetriminos[0] = 0b0001;
	tetri4.tetriminos[1] = 0b0011;
	tetri4.tetriminos[2] = 0b0001;
	tetri4.tetriminos[3] = 0b0000;
	tetri4.rank = 3;
	tetri4.length = 3;
	tetri4.width = 2;
	tetri4.next = NULL;

	map.map = NULL;
	map.size = get_map_minsize(&tetri1);
	while (1)
	{
		create_map(&map);
		if (solve_map(&tetri1, &map) == SUCCESS)
			break ;
		map.size += 1;
	}
	ft_putstr("Debug:\n");
	debug_map(map);
	ft_putchar('\n');
	print_map(map, &tetri1);
	free(map.map);
	return (SUCCESS);
}

/*
// TIM

t_tetri *storepieces(char *av)
{
    t_tetri *pieces;
    char str[SIZE + 1];
    unsigned int i;
		unsigned int check;
    int fd;
    int ret;

		check = 0;
    i = 0;
    fd = open(av, O_RDONLY);
    if (fd == -1)
        return (error("error"));
    while ((ret = read(fd, str, SIZE + 1)))
    {
        str[ret - 1] = '\0';
        if (ret == 21)
            check++;
        if (!tetriminocheck(str))
            return (error("error"));
        i++;
    }
    if (i == 0 || check == i)
        return (error("error"));
    close(fd);
    return (pieces);
}

int        main(int argc, char **argv)
{
    t_tetri		*tmp;

    if (argc != 2)
        return ((int)error("usage: ./fillit target_file"));
    tmp = storepieces(argv[1]);
    if (!tmp)
        return (0);
    return (0);
}
*/
