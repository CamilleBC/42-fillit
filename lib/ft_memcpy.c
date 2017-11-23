/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:52:24 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/14 16:20:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*byte_dst;
	unsigned char	*byte_src;

	byte_dst = (unsigned char *)dst;
	byte_src = (unsigned char *)src;
	while (n > 0)
	{
		--n;
		byte_dst[n] = byte_src[n];
	}
	return (dst);
}
