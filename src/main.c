/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:56 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/02 21:12:07 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		init_flags(t_flags *flags)
{
	flags->p = FALSE;
	flags->q = FALSE;
	flags->r = FALSE;
	flags->s = FALSE;
	flags->file_open = FALSE;
	flags->stdin_open = FALSE;
	flags->error = FALSE;
	flags->error_seen = FALSE;
	flags->input = NULL;
	flags->hashes = 0;
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
		handle_args(USE, argv[i], &flags);
		if (flags.input && !flags.error)
		{
			handle_input(argv[i], &flags);
		}
		if (flags.input)
		{
			free(flags.input);
			flags.input = NULL;
		}
		i++;
	}
	if (flags.input)
		ft_putendl("HHAHAHHAA");
	handle_args(END, NULL, &flags);
	if (flags.input)
		ft_putendl("BABABABABA");
	if (flags.input && !flags.error)
	{
		ft_putendl("LOLOLOLOL");
		ft_printf("INPUT = %s\n", flags.input);
		handle_input(argv[i], &flags);
	}
	if (flags.error_seen)
	{
		return (1);
	}
 	return (0);
}
