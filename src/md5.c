/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 19:54:17 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print(t_algo32 a, t_flags *flags, char *arg, char *input)
{
	if (flags->p)
		ft_printf("%s", input);
	if (flags->q || flags->p || (!flags->q && !flags->p && !flags->s &&
		!flags->file_open))
	{
		ft_printf("%.8x%.8x%.8x%.8x\n", a.a0, a.b0, a.c0, a.d0);
	}
	else if (flags->r)
	{
		if (flags->s)
			ft_printf("%.8x%.8x%.8x%.8x \"%s\"\n", a.a0, a.b0, a.c0, a.d0, arg);
		else
			ft_printf("%.8x%.8x%.8x%.8x %s\n", a.a0, a.b0, a.c0, a.d0, arg);
	}
	else if (flags->s)
	{
		ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", arg, a.a0, a.b0, a.c0,
			a.d0);
	}
	else
		ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", arg, a.a0, a.b0, a.c0, a.d0);
	flags->s = FALSE;
}

static void		initialize(t_algo32 *m, t_bool loop)
{
	if (!loop)
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

static void		define_vars(t_algo32 *m, uint32_t *meta, uint32_t block_index)
{
	m->f += m->a + g_sine[m->loop] + meta[m->g + block_index * 16];
	m->a = m->d;
	m->d = m->c;
	m->c = m->b;
	m->b += left_rotate(m->f, g_shift[m->loop]);
}

static void		main_loop(t_algo32 *m, uint32_t *meta, uint32_t block_index)
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

void			md5(t_env *e, t_flags *flags, char *arg)
{
	t_algo32	m;
	uint32_t	i;

	get_format_512(e);
	build_meta_512(e);
	initialize(&m, FALSE);
	i = 0;
	while (i < e->blocks)
	{
		initialize(&m, TRUE);
		main_loop(&m, e->meta_512, i);
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
	print(m, flags, arg, e->input);
	free(e->meta_512);
}
