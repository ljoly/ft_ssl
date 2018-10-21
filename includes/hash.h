/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:47:35 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 20:27:47 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include "stdint.h"

typedef struct	s_algo32
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
}				t_algo32;

typedef struct	s_algo64
{
	uint64_t	loop;
	uint64_t	w[80];
	uint64_t	a;
	uint64_t	a0;
	uint64_t	b;
	uint64_t	b0;
	uint64_t	c;
	uint64_t	c0;
	uint64_t	d;
	uint64_t	d0;
	uint64_t	e;
	uint64_t	e0;
	uint64_t	f;
	uint64_t	f0;
	uint64_t	g;
	uint64_t	g0;
	uint64_t	h;
	uint64_t	h0;
	uint64_t	s0;
	uint64_t	s1;
	uint64_t	t0;
	uint64_t	t1;
	uint64_t	ch;
	uint64_t	temp1;
	uint64_t	temp2;
	uint64_t	maj;
}				t_algo64;

uint32_t		swap_bytes_32bit(uint32_t val);
uint64_t		swap_bytes_64bit(uint64_t val);
uint32_t		left_rotate(uint32_t x, uint32_t c);
uint32_t		right_rotate(uint32_t x, uint32_t c);
uint64_t		right_rotate64(uint64_t x, uint64_t c);

#endif
