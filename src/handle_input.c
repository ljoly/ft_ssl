/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:59:14 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/17 20:18:12 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		free_memory(t_env *e, t_flags *flags)
{
	free(e->meta_block);
	free(flags->input);
	flags->input = NULL;
}

static void		get_env(t_env *e, t_flags *flags)
{
	e->input = flags->input;
	e->input_len = flags->size;
	e->input_bitsize = e->input_len * 8;
}

void			handle_input(char *arg, t_flags *flags)
{
	t_env		e;

	if (!flags->input)
	{
		flags->size = 0;
		flags->input = ft_strdup("");
	}
	get_env(&e, flags);
	get_format(&e);
	build_meta(&e, flags);
	g_hash.hash(e.meta_block, e.blocks, flags, arg);
	// if (flags->algo == MD5)
	// {
	// 	hash_md5(e.meta_block, e.blocks, flags, arg);
	// }
	// else if (flags->algo == SHA256 || flags->algo == SHA224)
	// {
	// 	;
	// 	flags->algo == SHA256 ? hash_sha256(e.meta_block, e.blocks, flags, arg) :
	// 	hash_sha224(e.meta_block, e.blocks, flags, arg);
	// }
	free_memory(&e, flags);
	flags->hashes++;
}
