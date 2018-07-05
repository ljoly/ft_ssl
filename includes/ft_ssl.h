/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:03:23 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/05 19:11:02 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"

# define A 0x67452301
# define B 0xEFCDAB89
# define C 0x98BADCFE
# define D 0x10325476

void		ft_md5(char *str);

int32_t		f_f(int32_t b, int32_t c, int32_t d);
int32_t		f_g(int32_t b, int32_t c, int32_t d);
int32_t		f_h(int32_t b, int32_t c, int32_t d);
int32_t		f_i(int32_t b, int32_t c, int32_t d);

#endif