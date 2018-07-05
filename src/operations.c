/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:38:52 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/05 19:09:45 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int32_t f_i(int32_t b, int32_t c, int32_t d)
{
    return (c ^ (b | ~d));
}

int32_t f_h(int32_t b, int32_t c, int32_t d)
{
    return (b ^ c ^ d);
}

int32_t f_g(int32_t b, int32_t c, int32_t d)
{
    return ((b & d) | (c & ~d));
}

int32_t f_f(int32_t b, int32_t c, int32_t d)
{
    return ((b & c) | (~B & d));
}