/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_meta_1024.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:21:06 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 23:04:20 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		add_size(t_env *e)
{
	size_t		size;

	size = 0;
	if (e->input_bitsize)
	{
		size = e->input_bitsize - 128;
	}
    e->meta_1024[e->blocks * 16 - 1] = size;
}

static void		add_padding(t_env *e)
{
	uint64_t	pad;
	size_t		last_bytes;
	size_t		index;

	last_bytes = e->input_len % 8;
	index = e->input_len / 8;
	pad = 0x0000000000000080;
	if (last_bytes == 1)
		pad = 0x0000000000008000;
	else if (last_bytes == 2)
		pad = 0x0000000000800000;
	else if (last_bytes == 3)
		pad = 0x0000000080000000;
    else if (last_bytes == 4)
		pad = 0x0000008000000000;
	else if (last_bytes == 5)
		pad = 0x0000800000000000;
    else if (last_bytes == 6)
		pad = 0x0080000000000000;
    else if (last_bytes == 7)
		pad = 0x8000000000000000;
    else if (last_bytes == 8)
	{
		index++;
	}
	e->meta_1024[index] = e->meta_1024[index] | pad;
}

void			build_meta_1024(t_env *e)
{
	size_t		i;

	if (!(e->meta_1024 = (uint64_t*)ft_memalloc(sizeof(uint64_t) *
		e->blocks * 16)))
	{
		err_sys(MALLOC);
	}
	ft_memcpy(e->meta_1024, e->input, e->input_len);
	add_padding(e);
	i = 0;
	while (i < e->blocks * 16)
	{
		e->meta_1024[i] = swap_bytes_64bit(e->meta_1024[i]);
		i++;
	}
	add_size(e);
}