/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/10 12:24:29 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void static initialize(t_algo *m)
{
    m->a0 = 0x67452301;
    m->b0 = 0xEFCDAB89;
    m->c0 = 0x98BADCFE;
    m->d0 = 0x10325476;
}

t_algo			hash_md5(uint32_t *meta, size_t blocks)
{
    t_algo      m;
    uint32_t    i;
    uint32_t    j;

	// i = 0;
	// while (i < 16)
	// {
	// 	printf("%d: %x\n", i, meta[i]);
	// 	i++;
	// }
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
    m.a0 = swap_bytes_32bit(m.a0);
    m.b0 = swap_bytes_32bit(m.b0);
    m.c0 = swap_bytes_32bit(m.c0);
    m.d0 = swap_bytes_32bit(m.d0);
    return (m);
}
