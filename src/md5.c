/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/20 17:47:26 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static uint32_t left_rotate(uint32_t x, uint32_t c)
{
    return ((x << c) | (x >> (32-c)));
}

void static initialize(t_md5 *m)
{
    m->a0 = INIT_A;
    m->b0 = INIT_B;
    m->c0 = INIT_C;
    m->d0 = INIT_D;
}

void static hash_meta(uint32_t *meta, size_t blocks)
{
    t_md5 m;
    uint32_t i;
    uint32_t j;

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
            m.f += m.a + g_T[i] + meta[m.g + j * 16];
            m.a = m.d;
            m.d = m.c;
            m.c = m.b;
            m.b += left_rotate(m.f, g_s[i]);
            i++;
            printf("A = %u B = %u C = %u D = %u\n", m.a, m.b, m.c, m.d);
        }
        m.a0 += m.a;
        m.b0 += m.b;
        m.c0 += m.c;
        m.d0 += m.d;
        j++;
    }
    printf("%.8x%.8x%.8x%.8x\n", m.a0, m.b0, m.c0, m.d0);
}

void static print(t_env e)
{
    size_t i;

    i = 0;
    while (i < e.blocks * 16)
    {
        printf("%u\n", e.meta_block[i]);
        i++;
    }
}

void ft_md5(char *input)
{
    t_env e;

    e.input = input;
    e.input_len = ft_strlen(input);
    e.input_bitsize = e.input_len * 8;
    ft_printf("input len = %zu\n", ft_strlen(input));
    ft_printf("input bitsize = %d\n", e.input_bitsize);
    get_format(&e);
    build_meta(&e);
    print(e);
    hash_meta(e.meta_block, e.blocks);
}
