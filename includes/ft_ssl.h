/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:03:23 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/20 17:46:17 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "error.h"

# define INIT_A 0x67452301
# define INIT_B 0xEFCDAB89
# define INIT_C 0x98BADCFE
# define INIT_D 0x10325476

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

typedef struct  s_md5
{
    uint32_t         a;
    uint32_t         a0;
    uint32_t         b;
    uint32_t         b0;
    uint32_t         c;
    uint32_t         c0;
    uint32_t         d;
    uint32_t         d0;
    uint32_t         f;
    uint32_t         g;
}               t_md5;

void		    ft_md5(char *s);
void            get_format(t_env *e);
void            build_meta(t_env *e);

uint32_t	    f_f(uint32_t b, uint32_t c, uint32_t d);
uint32_t	    f_g(uint32_t b, uint32_t c, uint32_t d);
uint32_t		f_h(uint32_t b, uint32_t c, uint32_t d);
uint32_t		f_i(uint32_t b, uint32_t c, uint32_t d);

#endif