/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/03 18:56:49 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static uint32_t reverse_bits(uint32_t value)
{
    return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
        (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

static uint32_t left_rotate(uint32_t x, uint32_t c)
{
    return ((x << c) | (x >> (32-c)));
}

void static initialize(t_algo *m)
{
    m->a0 = INIT_A;
    m->b0 = INIT_B;
    m->c0 = INIT_C;
    m->d0 = INIT_D;
}

static t_algo   hash_meta(uint32_t *meta, size_t blocks)
{
    t_algo      m;
    uint32_t    i;
    uint32_t    j;

    initialize(&m);
    j = 0;
    while (j < blocks)
    {
        m.a = m.a0;
        m.b = m.b0;
        m.c = m.c0;
        m.d = m.d0;
        i = 0;
        while (i < 64)
        {
            if (i <= 15)
            {
                m.f = ((m.b & m.c) | (~m.b & m.d));
                m.g = i;
            }
            else if (i >= 16 && i <= 31)
            {
                m.f = ((m.b & m.d) | (m.c & ~m.d));
                m.g = (5 * i + 1) % 16;
            }
            else if (i >= 32 && i <= 47)
            {
                m.f = (m.b ^ m.c ^ m.d);
                m.g = (3 * i + 5) % 16;
            }
            else if (i >= 48 && i <= 63)
            {
                m.f = (m.c ^ (m.b | ~m.d));
                m.g = (7 * i) % 16;
            }
            m.f += m.a + g_sine[i] + meta[m.g + j * 16];
            m.a = m.d;
            m.d = m.c;
            m.c = m.b;
            m.b += left_rotate(m.f, g_shift[i]);
            i++;
        }
        m.a0 += m.a;
        m.b0 += m.b;
        m.c0 += m.c;
        m.d0 += m.d;
        j++;
    }
    m.a0 = reverse_bits(m.a0);
    m.b0 = reverse_bits(m.b0);
    m.c0 = reverse_bits(m.c0);
    m.d0 = reverse_bits(m.d0);
    return (m);
}

t_algo      ft_md5(char *input)
{
    t_env   e;
    t_algo  m;

    e.input = input;
    e.input_len = ft_strlen(input);
    e.input_bitsize = e.input_len * 8;
    get_format(&e);
    build_meta(&e);
    m = hash_meta(e.meta_block, e.blocks);
    return (m);
}
