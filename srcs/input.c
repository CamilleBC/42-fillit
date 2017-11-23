/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:46:37 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 19:11:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./lib/libft.h"

#define RAW_TETRIMINOS 21

t_tetri	*ft_readtetriminos(int file_des)
{
	t_tetri	*tetriminos;
	char	tetriminos_raw[RAW_TETRIMINOS + 1];
	uint64_t	index;

	while (read(file_des, tetriminos_raw, 21))
	{
		;
	}
	return (tetriminos);
}
