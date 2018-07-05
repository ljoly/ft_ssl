/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:56 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/04 19:29:57 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void ft_err(int err_code)
{
	if (err_code == 1)
		ft_putendl_fd("Usage: ft_ssl command [command opts] [command args]", 2);
	else if (err_code == 2)
		ft_putendl_fd("ERROR: while opening file", 2);
	else if (err_code == 3)
		ft_putendl_fd("ERROR: could not malloc", 2);
	else if (err_code == 4)
		ft_putendl_fd("ERROR: while reading file", 2);
	exit(-1);
}

int main(int argc, char **argv)
{
	int fd;

	fd = 1;
	if (argc < 2)
	{
		ft_err(1);
	}
	if (ft_strequ(argv[1], "md5"))
	{
		ft_md5(argv[2]);
	}
	else if (ft_strequ(argv[1], "sha256"))
	{
		ft_putendl("ok");
	}
	return (0);
}