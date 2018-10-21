/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_meta_512.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:50:41 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 20:47:06 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		add_size(t_env *e)
{
	size_t		size;
	size_t		index;

	size = 0;
	if (e->input_bitsize)
	{
		size = e->input_bitsize - 64;
	}
	index = e->blocks * 16 - 2;
	if (ft_strequ("md5", g_hash.name))
	{
		e->meta_512[index + 1] = (size >> 32) & 0xffffffff;
		e->meta_512[index] = size & 0xffffffff;
	}
	else
	{
		e->meta_512[index] = (size >> 32) & 0xffffffff;
		e->meta_512[index + 1] = size & 0xffffffff;
	}
}

static void		add_padding(t_env *e)
{
	uint32_t	pad;
	size_t		last_bytes;
	size_t		index;

	last_bytes = e->input_len % 4;
	index = e->input_len / 4;
	pad = 0x00000080;
	if (last_bytes == 1)
		pad = 0x00008000;
	else if (last_bytes == 2)
		pad = 0x00800000;
	else if (last_bytes == 3)
		pad = 0x80000000;
	else if (last_bytes == 4)
	{
		index++;
	}
	e->meta_512[index] = e->meta_512[index] | pad;
}

void			build_meta_512(t_env *e)
{
	size_t		i;

	if (!(e->meta_512 = (uint32_t*)ft_memalloc(sizeof(uint32_t) *
		e->blocks * 16)))
	{
		err_sys(MALLOC);
	}
	ft_memcpy(e->meta_512, e->input, e->input_len);
	add_padding(e);
	if (!ft_strequ("md5", g_hash.name))
	{
		i = 0;
		while (i < e->blocks * 16)
		{
			e->meta_512[i] = swap_bytes_32bit(e->meta_512[i]);
			i++;
		}
	}
	add_size(e);
}
