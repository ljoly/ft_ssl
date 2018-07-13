/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/12 19:15:17 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void add_padding(t_env *e)
{
    // add 64-bit size
    ft_printf("msg = %s\n", e->padded_msg);
}

static char *get_padding(int size)
{
    int i;
    int pad;
    char *padding;

    pad = 512;
    if (size % 512 != 0)
    {
        pad = 448 - size % 512;
        if (pad <= 0)
            pad += 512;
    }
    padding = NULL;
    if (!(padding = (char *)ft_memalloc(sizeof(char) * pad)))
        ft_err(MALLOC);
    padding[0] = '1';
    i = 1;
    while (i < pad)
    {
        padding[i] = '0';
        i++;
    }
    return (padding);
}

void ft_md5(char *s)
{
    t_env e;


    e.input = s;
    // input to hex    
    if (!(e.padded_msg = ft_atohex(e.input, FALSE)))
        ft_err(MALLOC);
    e.input_bitsize = ft_strlen(s) * 8;
    // get binary padding
    e.padding = get_padding(e.input_bitsize);

    ft_printf("padding = %s\n", e.padding);
    ft_printf("padding size = %zu\n", ft_strlen(e.padding));
    add_padding(&e);
}
