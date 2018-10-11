/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:29:36 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/11 14:45:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		handle_hash(char *arg, t_flags *flags)
{
	t_env	e;
	t_algo	a;

	e.input = flags->input;
	e.input_len = flags->size;
	e.input_bitsize = e.input_len * 8;
	get_format(&e);
	build_meta(&e, flags);
	a.a = 0;
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
	free(e.meta_block);
	flags->hashes++;
}
