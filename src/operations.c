/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:38:52 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/09 18:31:25 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t f_i(uint32_t b, uint32_t c, uint32_t d)
{
    return (c ^ (b | ~d));
}

uint32_t f_h(uint32_t b, uint32_t c, uint32_t d)
{
    return (b ^ c ^ d);
}

uint32_t f_g(uint32_t b, uint32_t c, uint32_t d)
{
    return ((b & d) | (c & ~d));
}

uint32_t f_f(uint32_t b, uint32_t c, uint32_t d)
{
    return ((b & c) | (~B & d));
}