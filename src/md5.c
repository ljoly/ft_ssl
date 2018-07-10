/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/10 17:54:02 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

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

static void     ft_atohex(const char *src, char *dst, int upper)
{
    char        *tab;
    char        *tmp;
    size_t      len;
    size_t      i;

    tab = (upper == 1) ? HEX_UP : HEX;
    printf("src = %zu\ndst = %zu\n", ft_strlen(src), ft_strlen(dst));
    // if ((len = ft_strlen(src)) && ft_strlen(dst) == 2 * len)
    // {
        len = ft_strlen(src);
        i = 0;
        tmp = dst;
        while (i < len)
        {
            fill_dst(tmp, tab, ft_atoi(&src[i]));
    printf("%s\n", tmp);
            
            i++;
        }
        dst[i] = '\0';
    printf("%s\n", tmp);
    
    // }
}

static void add_padding(t_env *e)
{
    size_t size;

    size = 2 * ft_strlen(e->input) + 1;
    if (!(e->padded_msg = (char *)ft_memalloc(sizeof(char) * size)))
        ft_err(MALLOC);
    ft_atohex(e->input, e->padded_msg, FALSE);
}

static char *get_padding(int size)
{
    int i;
    int pad;
    char *padding;

    pad = 512;
    if (size % 512 != 0)
    {
        pad = 448 - size % 512;
        if (pad <= 0)
            pad += 512;
    }
    padding = NULL;
    if (!(padding = (char *)ft_memalloc(sizeof(char) * pad)))
        ft_err(MALLOC);
    padding[0] = '1';
    i = 1;
    while (i < pad)
    {
        padding[i] = '0';
        i++;
    }
    return (padding);
}

void ft_md5(char *s)
{
    t_env e;

    e.input = s;
    e.bin_padding = NULL;
    e.bitsize = ft_strlen(s) * 8;
    e.bin_padding = get_padding(e.bitsize);
    // printf("padding = %s\n%zu\n", e.bin_padding, ft_strlen(e.bin_padding));
    add_padding(&e);
}
