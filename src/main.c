/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:56 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/10 20:47:19 by ljoly            ###   ########.fr       */
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
	flags->size = 0;
	flags->hashes = 0;
}

static void		handle_input(char *arg, t_flags *flags)
{
	handle_hash(arg, flags);
	free(flags->input);
	flags->input = NULL;
}

int				main(int argc, char **argv)
{
	int			i;
	t_flags		flags;

	init_flags(&flags);
	(argc > 1) ? handle_args(START, argv[1], &flags) :
		err_usage(NOT_A_HASH, &flags);
	i = 1;
	while (i < argc)
	{
		handle_args(USE, argv[i], &flags);
		if (flags.input && !flags.error)
			handle_input(argv[i], &flags);
		flags.error = FALSE;
		i++;
	}
	handle_args(END, NULL, &flags);
	if (flags.input)
		handle_input(argv[i], &flags);
	return (flags.error_seen);
}
