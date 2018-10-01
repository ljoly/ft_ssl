/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:08:52 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 15:17:31 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	err_usage(t_usage err_code, t_flags *flags)
{
	flags->error = TRUE;
	if (err_code == NOT_A_HASH)
	{
		ft_putendl_fd("ERROR: wrong command", 2);
	}
	else if (err_code == NO_STRING)
	{
		ft_putendl_fd("ERROR: option -s requires an argument", 2);
	}
	else if (err_code == NOT_A_FILE)
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putstr_fd(flags->input, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (err_code == ILLEGAL_OPTION)
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putstr_fd(flags->input, 2);
		ft_putendl_fd(": Illegal option", 2);
	}
	ft_putendl_fd("Usage: ft_ssl command [command opts] [command args]", 2);
}

void	err_sys(t_sys err_code)
{
	if (err_code == OPEN)
		ft_putendl_fd("ERROR: while opening file", 2);
	else if (err_code == MALLOC)
		ft_putendl_fd("ERROR: could not malloc", 2);
	else if (err_code == READ)
	{
		ft_putendl_fd("ERROR: while reading file", 2);
		exit(1);
	}
	exit(-1);
}