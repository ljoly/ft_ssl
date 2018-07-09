/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:08:52 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/09 18:22:15 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void ft_err(t_error err_code)
{
	if (err_code == USAGE)
		ft_putendl_fd("Usage: ft_ssl command [command opts] [command args]", 2);
	else if (err_code == OPEN)
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