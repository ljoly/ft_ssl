/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:33:26 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/04 12:38:35 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

// static uint32_t reverse_bits(uint32_t value)
// {
//     return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
//         (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
// }

// static uint32_t		right_rotate(uint32_t x, uint32_t c)
// {
//     return ((x >> c) | (x << (32-c)));
// }

void static initialize(t_algo *m)
{
	m->a0 = 0x6a09e667;
	m->b0 = 0xbb67ae85;
	m->c0 = 0x3c6ef372;
	m->d0 = 0xa54ff53a;
	m->e0 = 0x510e527f;
	m->f0 = 0x9b05688c;
	m->g0 = 0x1f83d9ab;
	m->h0 = 0x5be0cd19;
}

static t_algo   hash_meta(uint32_t *meta, size_t blocks)
{
	uint32_t	block[64];
    t_algo      m;
    uint32_t    i;
    uint32_t    j;

    initialize(&m);
    j = 0;
    while (j < blocks)
    {
		block[0] = meta[0];
		// copy the first 16 indexes of meta into block[64];

        m.a = m.a0;
        m.b = m.b0;
        m.c = m.c0;
        m.d = m.d0;
		m.e = m.e0;
		m.f = m.f0;
		m.g = m.g0;
		m.h = m.h0;
        i = 0;
    //     while (i < 64)
    //     {
    //         if (i <= 15)
    //         {
    //             m.f = ((m.b & m.c) | (~m.b & m.d));
    //             m.g = i;
    //         }
    //         else if (i >= 16 && i <= 31)
    //         {
    //             m.f = ((m.b & m.d) | (m.c & ~m.d));
    //             m.g = (5 * i + 1) % 16;
    //         }
    //         else if (i >= 32 && i <= 47)
    //         {
    //             m.f = (m.b ^ m.c ^ m.d);
    //             m.g = (3 * i + 5) % 16;
    //         }
    //         else if (i >= 48 && i <= 63)
    //         {
    //             m.f = (m.c ^ (m.b | ~m.d));
    //             m.g = (7 * i) % 16;
    //         }
    //         m.f += m.a + g_sine[i] + meta[m.g + j * 16];
    //         m.a = m.d;
    //         m.d = m.c;
    //         m.c = m.b;
    //         m.b += left_rotate(m.f, g_shift[i]);
    //         i++;
    //     }
    //     m.a0 += m.a;
    //     m.b0 += m.b;
    //     m.c0 += m.c;
    //     m.d0 += m.d;
        j++;
    }
    // m.a0 = reverse_bits(m.a0);
    // m.b0 = reverse_bits(m.b0);
    // m.c0 = reverse_bits(m.c0);
    // m.d0 = reverse_bits(m.d0);
    return (m);
}

t_algo      ft_sha256(char *input)
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
