/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:56 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/25 16:52:33 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*output;

	fd = 1;
	if (argc < 2 || (!ft_strequ(argv[1], "md5") &&
		!ft_strequ(argv[1], "sha256")))
	{
		ft_err(USAGE);
	}
	if (ft_strequ(argv[1], "md5"))
	{
		argc == 2 ? ft_md5("") : ft_md5(argv[2]);
	}
	else if (ft_strequ(argv[1], "sha256"))
	{
		ft_putendl("ok");
	}
	return (0);
}