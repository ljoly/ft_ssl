/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:50:41 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 17:35:27 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void     add_size(t_env *e)
{
    size_t      size;
    size_t      index;

    size = 0;
    if (e->input_bitsize)
        size = e->input_bitsize - 64;
    index = e->blocks * 16 - 2;
    e->meta_block[index + 1] = (size >> 32) & 0xffffffff;
    e->meta_block[index] = size & 0xffffffff;
}

static void     add_padding(t_env *e, size_t len_buff, size_t index_meta)
{
    uint32_t    pad;

    pad = 0x00000080;
    if (len_buff == 1)
        pad = 0x00008000;
    else if (len_buff == 2)
        pad = 0x00800000;
    else if (len_buff == 3)
        pad = 0x80000000;
    else if (len_buff == 4)
    {
        index_meta++;
    }
    e->meta_block[index_meta] = e->meta_block[index_meta] | pad;
    ft_printf("%.8x indexmeta = %zu\n", e->meta_block[index_meta], index_meta);
}

void            build_meta(t_env *e)
{
    size_t      i;
    size_t      j;
    size_t      k;
    char        buff[5];

    if (!(e->meta_block = (uint32_t*)ft_memalloc(sizeof(uint32_t) * e->blocks * 16)))
        err_sys(MALLOC);
    i = 0;
    k = 0;
    while (i < e->input_len)
    {
        j = 0;
        while (i < e->input_len && j < 4)
        {
            buff[j] = e->input[i];
            j++;
            i++;
        }
        buff[j] = '\0';
        ft_memcpy(&e->meta_block[k], buff, ft_strlen(buff));
        k++;
    }
    if (k)
        k--;
    add_padding(e, ft_strlen(buff), k);
    add_size(e);
}