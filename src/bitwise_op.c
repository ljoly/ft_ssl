/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:19:15 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/10 20:01:40 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** convert data from little endianness to big
*/

uint32_t	swap_bytes_32bit(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

/*
** rotations used in md5 and sha2 algorithms
*/

uint32_t	left_rotate(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

uint32_t	right_rotate(uint32_t x, uint32_t c)
{
	return ((x >> c) | (x << (32 - c)));
}
