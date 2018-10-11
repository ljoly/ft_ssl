/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/11 12:43:09 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		initialize(t_algo *m, t_bool init)
{
	if (init)
	{
		m->a0 = 0x67452301;
		m->b0 = 0xEFCDAB89;
		m->c0 = 0x98BADCFE;
		m->d0 = 0x10325476;
	}
	else
	{
		m->loop = 0;
		m->a = m->a0;
		m->b = m->b0;
		m->c = m->c0;
		m->d = m->d0;
	}
}

static void		define_vars(t_algo *m, uint32_t *meta, uint32_t block_index)
{
	m->f += m->a + g_sine[m->loop] + meta[m->g + block_index * 16];
	m->a = m->d;
	m->d = m->c;
	m->c = m->b;
	m->b += left_rotate(m->f, g_shift[m->loop]);
}

static void		main_loop(t_algo *m, uint32_t *meta, uint32_t block_index)
{
	while (m->loop < 64)
	{
		if (m->loop <= 15)
		{
			m->f = ((m->b & m->c) | (~m->b & m->d));
			m->g = m->loop;
		}
		else if (m->loop >= 16 && m->loop <= 31)
		{
			m->f = ((m->b & m->d) | (m->c & ~m->d));
			m->g = (5 * m->loop + 1) % 16;
		}
		else if (m->loop >= 32 && m->loop <= 47)
		{
			m->f = (m->b ^ m->c ^ m->d);
			m->g = (3 * m->loop + 5) % 16;
		}
		else if (m->loop >= 48 && m->loop <= 63)
		{
			m->f = (m->c ^ (m->b | ~m->d));
			m->g = (7 * m->loop) % 16;
		}
		define_vars(m, meta, block_index);
		m->loop++;
	}
}

t_algo			hash_md5(uint32_t *meta, size_t blocks)
{
	t_algo		m;
	uint32_t	i;

	initialize(&m, TRUE);
	i = 0;
	while (i < blocks)
	{
		initialize(&m, FALSE);
		main_loop(&m, meta, i);
		m.a0 += m.a;
		m.b0 += m.b;
		m.c0 += m.c;
		m.d0 += m.d;
		i++;
	}
	m.a0 = swap_bytes_32bit(m.a0);
	m.b0 = swap_bytes_32bit(m.b0);
	m.c0 = swap_bytes_32bit(m.c0);
	m.d0 = swap_bytes_32bit(m.d0);
	return (m);
}
