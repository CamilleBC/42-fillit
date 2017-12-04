/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:31:04 by tifuret           #+#    #+#             */
/*   Updated: 2017/11/30 16:31:06 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Utility function to get min-max values for get_piece.
*/

void    get_min_max(char *str, t_point *min, t_point *max)
{
    int i;

    i = 0;
    while (i < 20)
    {
        if (str[i] == '#')
        {
            if (i / 5 < min->y)
                min->y = i / 5;
            if (i / 5 > max->y)
                max->y = i / 5;
            if (i % 5 < min->x)
                min->x = i % 5;
            if (i % 5 > max->x)
                max->x = i % 5;
        }
        i++;
    }
}

/*
** Reads a piece from a valid chunk, allocates a structure and populates it.
*/

t_tetri    *get_piece(char *str, char piece)
{
    t_point        *min;
    t_point        *max;
    t_tetri        *tetri;
    char           **pos;
    int            i;

    min = new_point(3, 3);
    max = new_point(0, 0);
    i = 0;
    get_min_max(str, min, max);
    pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
    while (i < max->y - min->y + 1)
    {
        pos[i] = ft_strnew(max->x - min->x + 1);
        ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
        i++;
    }
    tetri = tetris_new(pos, max->x - min->x + 1, max->y - min->y + 1, piece);
    ft_memdel((void **)&min);
    ft_memdel((void **)&max);
    return (tetri);
}

/*
** Checks connection counts, if we have 6 or 8 connections, the tetrimino is
** valid. Otherwise, our tetrimino is not contiguous.
*/

int        check_connection(char *str)
{
    int block;
    int i;

    block = 0;
    i = 0;
    while (i < 20)
    {
        if (str[i] == '#')
        {
            if ((i + 1) < 20 && str[i + 1] == '#')
                block++;
            if ((i - 1) >= 0 && str[i - 1] == '#')
                block++;
            if ((i + 5) < 20 && str[i + 5] == '#')
                block++;
            if ((i - 5) >= 0 && str[i - 5] == '#')
                block++;
        }
        i++;
    }
    return (block == 6 || block == 8);
}

/*
** Checks character counts and that chunk format is valid.
*/

int        check_counts(char *str, int count)
{
    int i;
    int block;

    block = 0;
    i = 0;
    while (i < 20)
    {
        if (i % 5 < 4)
        {
            if (!(str[i] == '#' || str[i] == '.'))
                return (1);
            if (str[i] == '#' && ++block > 4)
                return (1);
        }
        else if (str[i] != '\n')
            return (1);
        i++;
    }
    if (count == 21 && str[20] != '\n')
        return (1);
    if (!check_connection(str))
        return (1);
    return (0);
}

/*
** Read tetriminos from fd and put them in a list.
** We use 21 sized reads to read piece by piece since there are
** 4 lines made of 4 chars (+ newline) = 20 chars + newline = 21 chars
*/

t_list    *reading_tetri(int fd)
{
    char    *buf;
    int     i;
    char    piece;
    t_list  *list;
    t_tetri *tetris;

    buf = ft_strnew(21);
    list = NULL;
    piece = 'A';
    while ((i = read(fd, buf, 21)) >= 20)
    {
        if (check_counts(buf, i) == 1 || (tetri = get_piece(buf, piece++)) == NULL)
        {
            ft_memdel((void **)&buf);
            return (free_list(list));
        }
        ft_lstadd(&list, ft_lstnew(tetri, sizeof(t_tetri)));
        ft_memdel((void **)&tetri);
    }
    ft_m  emdel((void **)&buf);
    if (i != 0)
        return (free_list(list));
    ft_lstrev(&list);
    return (list);
}
