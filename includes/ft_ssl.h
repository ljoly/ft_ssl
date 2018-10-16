/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:03:23 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/15 14:45:45 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "parser.h"
# include "error.h"

/*
** tables used to build the message digest
*/
const uint32_t	g_sine[64];
const uint32_t	g_shift[64];
const uint32_t	g_cube[64];

typedef struct	s_env
{
	char		*input;
	size_t		input_len;
	size_t		padding_bitsize;
	size_t		input_bitsize;
	size_t		blocks;
	uint32_t	*meta_block;
	char		*output;
}				t_env;

typedef struct	s_algo
{
	uint32_t	loop;
	uint32_t	w[64];
	uint32_t	a;
	uint32_t	a0;
	uint32_t	b;
	uint32_t	b0;
	uint32_t	c;
	uint32_t	c0;
	uint32_t	d;
	uint32_t	d0;
	uint32_t	e;
	uint32_t	e0;
	uint32_t	f;
	uint32_t	f0;
	uint32_t	g;
	uint32_t	g0;
	uint32_t	h;
	uint32_t	h0;
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	t0;
	uint32_t	t1;
	uint32_t	ch;
	uint32_t	temp1;
	uint32_t	temp2;
	uint32_t	maj;
}				t_algo;

void			handle_input(char *input, t_flags *flags);
void			get_format(t_env *e);
void			build_meta(t_env *e, t_flags *flags);
t_algo			hash_md5(uint32_t *meta, size_t blocks);
t_algo			hash_sha2(uint32_t *meta, size_t blocks, t_name algo);

uint32_t		swap_bytes_32bit(uint32_t value);
uint32_t		left_rotate(uint32_t x, uint32_t c);
uint32_t		right_rotate(uint32_t x, uint32_t c);

void			print_md5(t_algo a, t_flags *flags, char *arg);
void			print_sha256(t_algo a, t_flags *flags, char *arg);
void			print_sha224(t_algo a, t_flags *flags, char *arg);

#endif
