/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:03:23 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/12 19:08:32 by ljoly            ###   ########.fr       */
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
    int         input_bitsize;
    char        *padding;
	char        *padded_msg;
}				t_env;

void		    ft_md5(char *s);

uint32_t	    f_f(uint32_t b, uint32_t c, uint32_t d);
uint32_t	    f_g(uint32_t b, uint32_t c, uint32_t d);
uint32_t		f_h(uint32_t b, uint32_t c, uint32_t d);
uint32_t		f_i(uint32_t b, uint32_t c, uint32_t d);

#endif