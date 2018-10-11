/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:08:52 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/11 19:37:22 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		print_err(t_bool type, t_flags *flags)
{
	if (!type)
	{
		ft_putstr_fd("Usage: ft_ssl [md5|sha2] [-pqr] [-s string] ", STDERR);
		ft_putendl_fd("[files ...]", STDERR);
	}
	else
	{
		ft_putstr_fd("Error: ", STDERR);
		ft_putstr_fd(flags->input, STDERR);
	}
}

void			err_usage(t_usage err_code, t_flags *flags)
{
	flags->error_seen = TRUE;
	flags->error = TRUE;
	if (err_code == NOT_A_HASH || err_code == NO_STRING)
	{
		err_code == NOT_A_HASH ? ft_putendl_fd("Error: wrong command", STDERR) :
		ft_putendl_fd("Error: option requires an argument -- s", STDERR);
		print_err(FALSE, flags);
	}
	else if (err_code == NOT_A_FILE)
	{
		print_err(TRUE, flags);
		ft_putendl_fd(": No such file or directory", STDERR);
	}
	else if (err_code == ILLEGAL_OPTION)
	{
		print_err(TRUE, flags);
		ft_putendl_fd(": Illegal option", STDERR);
		print_err(FALSE, flags);
		exit(1);
	}
	else if (err_code == IS_DIRECTORY)
	{
		print_err(TRUE, flags);
		ft_putendl_fd(": Is a directory", STDERR);
	}
}

void			err_sys(t_sys err_code)
{
	if (err_code == MALLOC)
		ft_putendl_fd("Error: could not malloc", STDERR);
	else if (err_code == READ)
	{
		ft_putendl_fd("Error: while reading", STDERR);
		exit(1);
	}
	exit(-1);
}
