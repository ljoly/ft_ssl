/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:19:15 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 22:54:48 by ljoly            ###   ########.fr       */
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

uint64_t	swap_bytes_64bit(uint64_t val)
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
	return (val << 32) | (val >> 32);
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

uint64_t	right_rotate64(uint64_t x, uint64_t c)
{
	return ((x >> c) | (x << (64 - c)));
}
