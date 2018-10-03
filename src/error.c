/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:08:52 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/03 19:23:16 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print_err(t_bool type, t_flags *flags)
{
	if (!type)
	{
		ft_putstr_fd("Usage: ft_ssl [command opts] [-pqr] [-s string] ", 2);
		ft_putendl_fd("[files ...]", 2);
	}
	else
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(flags->input, 2);
	}
}

void			err_usage(t_usage err_code, t_flags *flags)
{
	flags->error_seen = TRUE;
	flags->error = TRUE;
	if (err_code == NOT_A_HASH)
	{
		ft_putendl_fd("Error: wrong command", 2);
		print_err(FALSE, flags);
	}
	else if (err_code == NO_STRING)
	{
		ft_putendl_fd("Error: option requires an argument -- s", 2);
		print_err(FALSE, flags);
	}
	else if (err_code == NOT_A_FILE)
	{
		print_err(TRUE, flags);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (err_code == ILLEGAL_OPTION)
	{
		print_err(TRUE, flags);
		ft_putendl_fd(": Illegal option", 2);
	}
}

void			err_sys(t_sys err_code)
{
	if (err_code == MALLOC)
		ft_putendl_fd("Error: could not malloc", 2);
	else if (err_code == READ)
	{
		ft_putendl_fd("Error: while reading", 2);
		exit(1);
	}
	exit(-1);
}