/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:33:46 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/22 16:51:52 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char		*g_fmt = "%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx\n";

static void		print(t_algo64 a, t_flags *flags, char *arg, char *input)
{
	if (flags->p)
		ft_printf("%s", input);
	if (flags->q || flags->p || (!flags->q && !flags->p && !flags->s &&
		!flags->file_open))
		ft_printf("%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx\n", a.a0,
			a.b0, a.c0, a.d0, a.e0, a.f0, a.g0, a.h0);
	else if (flags->r)
	{
		if (flags->s)
			ft_printf("%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx \"%s\"\n",
				a.a0, a.b0, a.c0, a.d0, a.e0, a.f0, a.g0, a.h0, arg);
		else
			ft_printf("%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx %s\n", a.a0,
				a.b0, a.c0, a.d0, a.e0, a.f0, a.g0, a.h0, arg);
	}
	else if (flags->s)
		ft_printf("SHA512 (\"%s\") = ",
			arg, g_fmt, a.a0, a.b0, a.c0, a.d0, a.e0, a.f0, a.g0, a.h0);
	else
		ft_printf("SHA512 (%s) = %.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx%.8lx\n",
			arg, a.a0, a.b0, a.c0, a.d0, a.e0, a.f0, a.g0, a.h0);
	flags->s = FALSE;
}

static void		initialize(t_algo64 *m, t_bool loop)
{
	if (!loop)
	{
		m->a0 = 0x6a09e667f3bcc908;
		m->b0 = 0xbb67ae8584caa73b;
		m->c0 = 0x3c6ef372fe94f82b;
		m->d0 = 0xa54ff53a5f1d36f1;
		m->e0 = 0x510e527fade682d1;
		m->f0 = 0x9b05688c2b3e6c1f;
		m->g0 = 0x1f83d9abfb41bd6b;
		m->h0 = 0x5be0cd19137e2179;
	}
	else
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
}

static void		schedule_array(uint64_t *meta, t_algo64 *m, uint64_t block)
{
	uint64_t	i;

	ft_memcpy(m->w, &meta[block * 16], 16 * sizeof(uint64_t));
	i = 16;
	while (i < 80)
	{
		m->s0 = right_rotate64(m->w[i - 15], 1)
			^ right_rotate64(m->w[i - 15], 8) ^ (m->w[i - 15] >> 7);
		m->s1 = right_rotate64(m->w[i - 2], 19)
			^ right_rotate64(m->w[i - 2], 61) ^ (m->w[i - 2] >> 6);
		m->w[i] = m->w[i - 16] + m->s0 + m->w[i - 7] + m->s1;
		i++;
	}
}

static void		main_loop(t_algo64 *m)
{
	uint64_t	i;

	i = 0;
	while (i < 80)
	{
		m->t1 = right_rotate64(m->e, 14) ^ right_rotate64(m->e, 18)
			^ right_rotate64(m->e, 41);
		m->ch = (m->e & m->f) ^ (~m->e & m->g);
		m->temp1 = m->h + m->t1 + m->ch + g_cube64[i] + m->w[i];
		m->t0 = right_rotate64(m->a, 28) ^ right_rotate64(m->a, 34)
			^ right_rotate64(m->a, 39);
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

void			sha512(t_env *e, t_flags *flags, char *arg)
{
	t_algo64	m;
	uint64_t	j;

	get_format_1024(e);
	build_meta_1024(e);
	initialize(&m, FALSE);
	j = 0;
	while (j < e->blocks)
	{
		schedule_array(e->meta_1024, &m, j);
		initialize(&m, TRUE);
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
	print(m, flags, arg, e->input);
	free(e->meta_1024);
}
