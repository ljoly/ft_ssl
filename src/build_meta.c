/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:50:41 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/20 16:56:33 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

// static uint32_t reverse_bits(uint32_t value)
// {
//     return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
//         (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
// }

static void     add_size(t_env *e)
{
    size_t      size;
    size_t      index;

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
}

void            build_meta(t_env *e)
{
    size_t      i;
    size_t      j;
    size_t      k;
    char        buff[5];

    e->meta_block = (uint32_t*)ft_memalloc(sizeof(uint32_t) * e->blocks * 16);
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
    add_padding(e, ft_strlen(buff), k - 1);
    add_size(e);
}
