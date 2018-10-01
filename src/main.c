/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:56 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 17:47:19 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		init_flags(t_flags *flags)
{
	flags->md5 = FALSE;
	flags->sha256 = FALSE;
	flags->p = FALSE;
	flags->q = FALSE;
	flags->r = FALSE;
	flags->s = FALSE;
	flags->file_open = FALSE;
	flags->error = FALSE;
	flags->input = NULL;
	flags->hashes = 0;
}

static void		handle_input(t_flags *flags)
{
	ft_putendl("HANDLE");
	if (flags->md5)
	{
		ft_md5(flags->input);
	}
	else if (flags->sha256)
	{
		ft_putendl("HANDLE SHA256");
	}
	flags->hashes++;
	flags->input = NULL;
}

int				main(int argc, char **argv)
{
	int			i;
	t_flags		flags;	

	if (argc > 1)
		handle_args(START, argv[1], &flags);
	else
		err_usage(NOT_A_HASH, &flags);
	i = 1;
	init_flags(&flags);
	while (i < argc)
	{
		ft_putendl(argv[i]);
		handle_args(USE, argv[i], &flags);
		if (flags.input)
		{
			handle_input(&flags);
		}
		i++;
	}
	handle_args(END, NULL, &flags);
	if (flags.input)
		handle_input(&flags);
	if (flags.error)
	{
		return (1);
	}
 	return (0);
}