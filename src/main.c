/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:56 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/26 21:10:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	handle_md5(t_arg arg)
{
	ft_md5(arg.input);
}

static void		init_arg(t_arg *arg)
{
	arg->md5 = FALSE;
	arg->p = FALSE;
	arg->q = FALSE;
	arg->r = FALSE;
	arg->s = FALSE;
	arg->input = NULL;
}

int			main(int argc, char **argv)
{
	t_arg	arg;	

	init_arg(&arg);
	*argv++;
	handle_args(START, *argv, &arg);
	while (*argv)
	{
		handle_args(USE, **argv, &arg);
		*argv++;
	}
	if (arg.md5)
	{
		handle_md5(arg);
	}
	else
	{
		// handle_sha256
	}
	return (0);
}