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

static int        sizecheck(char *str)
{
    int hash;
    int len;
    int height;
    int i;

    hash = 0;
    len = 0;
    height = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '.' || str[i] == '#')
            len++;
        if (str[i] == '#')
            hash++;
        if (str[i] == '\n')
        {
            if (len != 4 || i > 19)
                return (0);
            height++;
            len = 0;
        }
        if (str[i + 1] == '\0' && len == 4)
            height++;
        i++;
    }
    if (height != 4 || hash != 4)
        return (0);
    return (1);
}

int                tetriminocheck(char *str)
{
    if (sizecheck(str))
        return (1);
    return (0);
}
