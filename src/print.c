/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:45:30 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/11 14:20:21 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		print_sha224(t_algo a, t_flags *flags, char *arg)
{
	if (flags->q || flags->p || (!flags->q && !flags->p && !flags->s &&
		!flags->file_open))
	{
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", a.a0, a.b0, a.c0, a.d0,
			a.e0, a.f0, a.g0);
	}
	else if (flags->r)
	{
		if (flags->s)
			ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x \"%s\"\n", a.a0, a.b0,
				a.c0, a.d0, a.e0, a.f0, a.g0, arg);
		else
			ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x %s\n", a.a0, a.b0, a.c0,
				a.d0, a.e0, a.f0, a.g0, arg);
	}
	else if (flags->s)
	{
		ft_printf("SHA224 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
			arg, a.a0, a.b0, a.c0, a.d0, a.e0, a.f0, a.g0);
	}
	else
		ft_printf("SHA224 (%s) = %.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", arg,
			a.a0, a.b0, a.c0, a.d0, a.e0, a.f0, a.g0);
	flags->s = FALSE;
}

void		print_sha256(t_algo a, t_flags *flags, char *arg)
{
	if (flags->q || flags->p || (!flags->q && !flags->p && !flags->s &&
		!flags->file_open))
	{
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", a.a0, a.b0, a.c0, a.d0,
			a.e0, a.f0, a.g0, a.h0);
	}
	else if (flags->r)
	{
		if (flags->s)
			ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x \"%s\"\n", a.a0, a.b0,
				a.c0, a.d0, a.e0, a.f0, a.g0, a.h0, arg);
		else
			ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x %s\n", a.a0, a.b0, a.c0,
				a.d0, a.e0, a.f0, a.g0, a.h0, arg);
	}
	else if (flags->s)
	{
		ft_printf("SHA256 (\"%s\") = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n",
			arg, a.a0, a.b0, a.c0, a.d0, a.e0, a.f0, a.g0, a.h0);
	}
	else
		ft_printf("SHA256 (%s) = %.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x\n", arg,
			a.a0, a.b0, a.c0, a.d0, a.e0, a.f0, a.g0, a.h0);
	flags->s = FALSE;
}

void		print_md5(t_algo a, t_flags *flags, char *arg)
{
	if (flags->q || flags->p || (!flags->q && !flags->p && !flags->s &&
		!flags->file_open))
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
		ft_printf("MD5 (\"%s\") = %.8x%.8x%.8x%.8x\n", arg, a.a0, a.b0, a.c0,
			a.d0);
	}
	else
		ft_printf("MD5 (%s) = %.8x%.8x%.8x%.8x\n", arg, a.a0, a.b0, a.c0, a.d0);
	flags->s = FALSE;
}
