/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/19 15:55:39 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

// static uint32_t reverse_bits(uint32_t value)
// {
//     return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
//         (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
// }

void static     print(t_env e)
{
    size_t         i;

    i = 0;
    while (i < e.blocks * 16)
    {
        printf("%u\n", e.meta_block[i]);
        i++;
    }
}

void ft_md5(char *input)
{
    t_env       e;

    e.input = input;
    e.input_len = ft_strlen(input);
    e.input_bitsize = e.input_len * 8;
    ft_printf("input len = %zu\n", ft_strlen(input));
    ft_printf("input bitsize = %d\n", e.input_bitsize);
    get_format(&e);
    build_meta(&e);
    print(e);
}
