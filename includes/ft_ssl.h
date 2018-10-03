/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:03:23 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/03 19:41:32 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "parser.h"
# include "error.h"

/*
** tables used to build the message digest
*/
uint32_t		g_sine[64];
uint32_t		g_shift[64];

typedef struct	s_env
{
	char		*input;
	size_t		input_len;
	uint32_t	padding_bitsize;
	uint32_t	input_bitsize;
	size_t		blocks;
	uint32_t	*meta_block;
	char		*output;
}				t_env;

typedef struct	s_algo
{
	uint32_t	a;
	uint32_t	a0;
	uint32_t	b;
	uint32_t	b0;
	uint32_t	c;
	uint32_t	c0;
	uint32_t	d;
	uint32_t	d0;
	uint32_t	e;
	uint32_t	e0;
	uint32_t	f;
	uint32_t	f0;
	uint32_t	g;
	uint32_t	g0;
	uint32_t	h;
	uint32_t	h0;
}				t_algo;

void			handle_input(char *arg, t_flags *flags);
t_algo			ft_md5(char *input);
t_algo			ft_sha256(char *input);
void			get_format(t_env *e);
void			build_meta(t_env *e);

#endif
