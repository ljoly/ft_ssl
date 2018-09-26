/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:08:52 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/26 20:50:05 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void usage_err(t_usage err_code, char *arg)
{
	if (err_code == NOT_A_HASH)
	{
		ft_putendl_fd("ERROR: wrong command", 2);
		ft_putendl_fd("Usage: ft_ssl command [command opts] [command args]", 2);		
		exit(-1);
	}
	else if (err_code == NOT_A_STRING)
	{
		ft_putendl_fd("ERROR: option -s requires an argument", 2);
		ft_putendl_fd("Usage: ft_ssl command [command opts] [command args]", 2);
	}
	else if (err_code == NOT_A_FILE)
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

void sys_err(t_sys err_code)
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