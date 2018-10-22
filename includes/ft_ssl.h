/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:03:23 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/22 13:30:08 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "parser.h"
# include "hash.h"

/*
** tables used to build the message digest
*/
const uint32_t	g_sine[64];
const uint32_t	g_shift[64];
const uint32_t	g_cube[64];
const uint64_t	g_cube64[80];

typedef struct	s_env
{
	char		*input;
	size_t		input_len;
	size_t		padding_bitsize;
	size_t		input_bitsize;
	size_t		blocks;
	uint32_t	*meta_512;
	u_int64_t	*meta_1024;
	char		*output;
}				t_env;

typedef struct	s_hash
{
	char		*name;
	void		(*hash)(t_env *e, t_flags *f, char *arg);
}				t_hash;

t_hash			g_hash;

void			handle_prompt(t_flags *flags);
void			handle_input(char *input, t_flags *flags);
void			get_format_512(t_env *e);
void			get_format_1024(t_env *e);
void			build_meta_512(t_env *e);
void			build_meta_1024(t_env *e);
void			md5(t_env *e, t_flags *f, char *arg);
void			sha224(t_env *e, t_flags *f, char *arg);
void			sha256(t_env *e, t_flags *f, char *arg);
void			sha384(t_env *e, t_flags *f, char *arg);
void			sha512(t_env *e, t_flags *f, char *arg);

#endif
