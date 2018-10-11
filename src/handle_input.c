/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:59:14 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/11 19:10:55 by ljoly            ###   ########.fr       */
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
	t_algo		a;

	a.a = 0;
	if (!flags->input)
	{
		flags->size = 0;
		flags->input = ft_strdup("");
	}
	get_env(&e, flags);
	get_format(&e);
	build_meta(&e, flags);
	if (flags->algo == MD5)
	{
		a = hash_md5(e.meta_block, e.blocks);
		print_md5(a, flags, arg);
	}
	else if (flags->algo == SHA256 || flags->algo == SHA224)
	{
		a = hash_sha2(e.meta_block, e.blocks, flags->algo);
		flags->algo == SHA256 ? print_sha256(a, flags, arg) :
		print_sha224(a, flags, arg);
	}
	free_memory(&e, flags);
	flags->hashes++;
}
