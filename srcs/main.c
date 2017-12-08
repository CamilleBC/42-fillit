/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:02:39 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 12:40:57 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "algorithm.h"
#include "input.h"
#include "map.h"
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

void	print_tetriminos(t_list *list)
{
	uint32_t	i;
	uint32_t	j;
	char		binary[33];
	t_tetri		*tetri;

	i = 1;
	tetri = (t_tetri *)list->content;
	while (list != NULL)
	{
		 j = 0;
		printf("Tetriminos %02d width: %d\n", i, tetri->width);
		printf("Tetriminos %02d length: %d\n", i, tetri->length);
		while (j < 4)
		{
			itoa_base(tetri->tetriminos[j], binary, 2);
			ft_putstr_padzeroes(binary, 4);
			++j;
		}
		++i;
		list = list->next;
		tetri = (t_tetri *)list->content;
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

int		main(int argc, char **argv)
{
    t_list		*list;
	t_map		map;


    if (argc != 2)
    {
        ft_putstr("usage: fillit input_file\n");
        return (1);
    }
    if ((list = reading_tetri(open(argv[1], O_RDONLY))) == NULL)
    {
        ft_putstr("error\n");
        return (1);
    }
	// print_tetriminos(list);
	map.map = NULL;
	map.size = get_map_minsize(list);
	while (1)
	{
		create_map(&map);
		if (solve_map(list, &map) == SUCCESS)
			break ;
		map.size += 1;
	}
	print_map(map, list);

	free(map.map);
	return (SUCCESS);
}
