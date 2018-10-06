/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 16:54:24 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/06 18:43:51 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print(t_algo a, t_flags *flags, char *arg, char *algo)
{
	if (flags->q || flags->p || (!flags->q && !flags->p && !flags->s && !flags->file_open))
	{
    	ft_printf("%.8x%.8x%.8x%.8x\n", a.a0, a.b0, a.c0, a.d0);		
	}
	else if (flags->r)
	{
		if (flags->s)
    		ft_printf("%.8x%.8x%.8x%.8x \"%s\"\n", a.a0, a.b0, a.c0, a.d0, arg);
		else
    		ft_printf("%.8x%.8x%.8x%.8x %s\n", a.a0, a.b0, a.c0, a.d0, arg);				
	}
	else if (flags->s)
	{
    	ft_printf("%s (\"%s\") = %.8x%.8x%.8x%.8x\n", algo, arg, a.a0, a.b0, a.c0, a.d0);
	}
    else
        ft_printf("%s (%s) = %.8x%.8x%.8x%.8x\n", algo, arg, a.a0, a.b0, a.c0, a.d0);
	flags->s = FALSE;
}

void		handle_input(char *arg, t_flags *flags)
{
	t_algo		a;

	if (flags->algo == MD5)
	{
		a = ft_md5(flags->input, flags->size);
		print(a, flags, arg, "MD5");
	}
	else if (flags->algo == SHA256)
	{
		a = ft_sha256(flags->input);
		print(a, flags, arg, "SHA256");
	}
	flags->hashes++;
}