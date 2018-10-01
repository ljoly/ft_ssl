/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:52:05 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 17:25:11 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void     get_format(t_env *e)
{
    if (e->input_bitsize)
        e->input_bitsize += 64;
    e->blocks = 1 + e->input_bitsize / 512;
    ft_printf("blocks = %d\n", e->blocks);
    e->padding_bitsize = e->blocks * 512 - e->input_bitsize % 512;
    ft_printf("padding size = %d\n", e->padding_bitsize);
    if (e->blocks > 1)
    {
        e->padding_bitsize -= 512 * (e->blocks - 1);
    }
    ft_printf("padding size = %d\n", e->padding_bitsize);
}