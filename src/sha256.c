/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:33:26 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/10 18:04:31 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void static		initialize(t_algo *m, t_bool first_init)
{
	if (first_init)
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
	else {
		m->a = m->a0;
        m->b = m->b0;
        m->c = m->c0;
        m->d = m->d0;
		m->e = m->e0;
		m->f = m->f0;
		m->g = m->g0;
		m->h = m->h0;
	}
}

t_algo			hash_256(uint32_t *meta, size_t blocks)
{
	uint32_t	w[64];
    t_algo      m;
    uint32_t    i;
    uint32_t    j;
	uint32_t	len;

    initialize(&m, TRUE);
    j = 0;
	// ft_printf("BLOCKS = %zu\n", blocks);
    while (j < blocks)
    {
		// ft_printf("\nBLOCK %u:\n\n", j);

		// copy the first 16 indexes of meta into w[64];
        ft_memcpy(w, &meta[j * 16], 16 * sizeof(uint32_t));
		i = 0;
		len = (j == blocks - 1) ? 14 : 16;
		while (i < len)
		{
			w[i] = swap_bytes_32bit(w[i]);
			i++;
		}
		i = 0;
		while (i < 16)
		{
			// printf("%.8x\n", w[i]);
			i++;
		}
        i = 16;
        while (i < 64)
        {
			m.s0 = right_rotate(w[i-15], 7) ^ right_rotate(w[i-15], 18) ^ (w[i-15] >> 3);
			m.s1 = right_rotate(w[i-2], 17) ^ right_rotate(w[i-2], 19) ^ (w[i-2] >> 10);
			w[i] = w[i-16] + m.s0 + w[i-7] + m.s1;
			// printf("%.8x\n", w[i]);
            i++;
		}
		initialize(&m, FALSE);
        i = 0;
		while (i < 64)
		{
			m.t1 = right_rotate(m.e, 6) ^ right_rotate(m.e, 11) ^ right_rotate(m.e, 25);
			m.ch = (m.e & m.f) ^ (~m.e & m.g);
			m.temp1 = m.h + m.t1 + m.ch + g_cube[i] + w[i];
			m.t0 = right_rotate(m.a, 2) ^ right_rotate(m.a, 13) ^ right_rotate(m.a, 22);
			m.maj = (m.a & m.b) ^ (m.a & m.c) ^ (m.b & m.c);
			m.temp2 = m.t0 + m.maj;
			
			m.h = m.g;
			m.g = m.f;
			m.f = m.e;
			m.e = m.d + m.temp1;
			m.d = m.c;
			m.c = m.b;
			m.b = m.a;
			m.a = m.temp1 + m.temp2;

			i++;
		}
		m.a0 += m.a;
		m.b0 += m.b;
		m.c0 += m.c;
		m.d0 += m.d;
		m.e0 += m.e;
		m.f0 += m.f;
		m.g0 += m.g;
		m.h0 += m.h;
		
		j++;
    }
	return (m);
}
