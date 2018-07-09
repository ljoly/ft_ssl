/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:13:19 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/09 20:21:27 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char *add_padding(char *padded_msg, int size)
{
    int i;
    int pad;
    char *padding;

    pad = 448 - size % 512;
    if (pad <= 0)
        pad += 512;
    padding = NULL;
    printf("size = %d\n", size);
    printf("len = %d\n", pad);
    if (!(padding = (char *)ft_memalloc(sizeof(char) * pad)))
        ft_err(MALLOC);
    padding[0] = '1';
    i = 1;
    while (i < pad)
    {
        padding[i] = '0';
        i++;
    }
    printf("padding = %s\n%zu\n", padding, ft_strlen(padding));
    return (padded_msg);
}

// if problem exit(1)
void ft_md5(char *s)
{
    char *padded_msg;
    int bitsize;

    padded_msg = NULL;
    bitsize = ft_strlen(s) * 8;
    padded_msg = add_padding(padded_msg, bitsize);
    // pre_processing(bitsize);
}
