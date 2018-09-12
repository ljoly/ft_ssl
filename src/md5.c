/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/12 19:19:16 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void     get_format(t_env *e)
{
    // add bitsize of len
    e->input_bitsize += 64;
    //
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

void ft_md5(char *s)
{
    t_env       e;
    uint32_t    message[16];

    e.input = s;
    e.input_bitsize = ft_strlen(s) * 8;
    ft_printf("input len = %zu\n", ft_strlen(s));
    ft_printf("input bitsize = %d\n", e.input_bitsize);
    get_format(&e);
    message[0] = s[0];
}
