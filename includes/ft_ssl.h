/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:03:23 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/18 14:26:41 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "error.h"

# define A 0x67452301
# define B 0xEFCDAB89
# define C 0x98BADCFE
# define D 0x10325476

// tables used to build the message digest
uint32_t        g_T[64];
uint32_t        g_s[64];

typedef struct  s_env
{
    char        *input;
    size_t      input_len;
    uint32_t    padding_bitsize;
    uint32_t    input_bitsize;
    size_t      blocks;
    uint32_t    *meta_block;
}				t_env;

void		    ft_md5(char *s);

uint32_t	    f_f(uint32_t b, uint32_t c, uint32_t d);
uint32_t	    f_g(uint32_t b, uint32_t c, uint32_t d);
uint32_t		f_h(uint32_t b, uint32_t c, uint32_t d);
uint32_t		f_i(uint32_t b, uint32_t c, uint32_t d);

#endif