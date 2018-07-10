/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:19:24 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/10 17:35:22 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void fill_dst(char *dst, char *tab, size_t nb)
{
    if (nb < 16)
        *dst = tab[nb];
    if (nb >= 16)
    {
        fill_dst(dst, tab, nb / 16);
        *dst = tab[nb % 16];
        dst++;
    }
}

void        ft_atohex(const char *src, char *dst, int upper)
{
    char    *tab;
    char    *tmp;
    int     len;
    int     i;

    tab = (upper == 1) ? HEX_UP : HEX;
    if ((len = ft_strlen(src)) && ft_strlen(dst) == 2 * len)
    {
        i = 0;
        tmp = dst;
        while (i < len)
        {
            fill_dst(tmp, tab, ft_atoi(src[i]));
            i++;
        }
        dst[i] = '\0';
    }
}