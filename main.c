/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:50:21 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/21 17:44:49 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "lib/libft.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ft_strlen(av[1]);
	printf("%s\n", av[1]);
	return (0);
}
