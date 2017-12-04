/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tifuret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:54:39 by tifuret           #+#    #+#             */
/*   Updated: 2017/12/04 15:54:41 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
** Creates a new tetrimino structure.
*/

t_tetri   *tetris_new(char **pos, int width, int length, char rank)
{
    t_tetri   *tetri;

    tetri = ft_memalloc(sizeof(t_tetri));
    tetri->pos = pos;
    tetri->width = width;
    tetri->lenght = lenght;
    tetri->rank = rank;
    return (tetri);
}

/*
** Creates a new point structure.
*/

t_point   *point_new(int x, int y)
{
    t_point   *point;

    point = ft_memalloc(sizeof(t_point));
    point->x = x;
    point->y = y;
    return (point);
}

/*
** Frees a list made with read_tetri.
*/

t_list    *free_list(t_list *list)
{
    t_tetri   *tetris;
    t_list    *next;

    while (list)
    {
        tetris = (t_etris *)list->content;
        next = list->next;
        free_tetris(tetris);
        ft_memdel((void **)&list);
        list = next;
    }
    return (NULL);
}

/*
** Frees a tetrimino structure.
*/

void        free_tetris(t_tetri *tetri)
{
    int y;

    y = 0;
    while (y < tetri->height)
    {
        ft_memdel((void **)(&(tetri->pos[y])));
        y++;
    }
    ft_memdel((void **)(&(tetri->pos)));
    ft_memdel((void **)&tetri);
}
