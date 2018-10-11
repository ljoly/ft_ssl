/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:11:57 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/11 14:54:41 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		initialize_vars(t_algo *m, t_name algo)
{
	if (algo == SHA256)
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
	else if (algo == SHA224)
	{
		m->a0 = 0xc1059ed8;
		m->b0 = 0x367cd507;
		m->c0 = 0x3070dd17;
		m->d0 = 0xf70e5939;
		m->e0 = 0xffc00b31;
		m->f0 = 0x68581511;
		m->g0 = 0x64f98fa7;
		m->h0 = 0xbefa4fa4;
	}
}

static void		initialize_loop(t_algo *m)
{
	m->a = m->a0;
	m->b = m->b0;
	m->c = m->c0;
	m->d = m->d0;
	m->e = m->e0;
	m->f = m->f0;
	m->g = m->g0;
	m->h = m->h0;
}

static void		schedule_array(uint32_t *meta, t_algo *m, uint32_t block_index)
{
	uint32_t	i;

	ft_memcpy(m->w, &meta[block_index * 16], 16 * sizeof(uint32_t));
	i = 16;
	while (i < 64)
	{
		m->s0 = right_rotate(m->w[i - 15], 7) ^ right_rotate(m->w[i - 15], 18)
			^ (m->w[i - 15] >> 3);
		m->s1 = right_rotate(m->w[i - 2], 17) ^ right_rotate(m->w[i - 2], 19)
			^ (m->w[i - 2] >> 10);
		m->w[i] = m->w[i - 16] + m->s0 + m->w[i - 7] + m->s1;
		i++;
	}
}

static void		main_loop(t_algo *m)
{
	uint32_t	i;

	i = 0;
	while (i < 64)
	{
		m->t1 = right_rotate(m->e, 6) ^ right_rotate(m->e, 11)
			^ right_rotate(m->e, 25);
		m->ch = (m->e & m->f) ^ (~m->e & m->g);
		m->temp1 = m->h + m->t1 + m->ch + g_cube[i] + m->w[i];
		m->t0 = right_rotate(m->a, 2) ^ right_rotate(m->a, 13)
			^ right_rotate(m->a, 22);
		m->maj = (m->a & m->b) ^ (m->a & m->c) ^ (m->b & m->c);
		m->temp2 = m->t0 + m->maj;
		m->h = m->g;
		m->g = m->f;
		m->f = m->e;
		m->e = m->d + m->temp1;
		m->d = m->c;
		m->c = m->b;
		m->b = m->a;
		m->a = m->temp1 + m->temp2;
		i++;
	}
}

t_algo			hash_sha2(uint32_t *meta, size_t blocks, t_name algo)
{
	t_algo		m;
	uint32_t	j;

	initialize_vars(&m, algo);
	j = 0;
	while (j < blocks)
	{
		schedule_array(meta, &m, j);
		initialize_loop(&m);
		main_loop(&m);
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