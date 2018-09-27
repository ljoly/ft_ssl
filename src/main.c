/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:44:56 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/27 19:26:21 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	handle_md5(t_arg arg)
{
	ft_md5(arg.input);
}

int			main(int argc, char **argv)
{
	int		i;
	t_arg	arg;	

	if (argc > 1)
		handle_args(START, argv[1], &arg);
	i = 1;
	while (i < argc)
	{
		handle_args(USE, argv[i], &arg);
		if (arg.md5)
		{
			handle_md5(arg);
		}
		else
		{
			ft_putendl("HANDLE SHA256");
		}
		i++;
	}
	handle_args(END, NULL, &arg);  // WARNING

	// if (argc < 2 || (!ft_strequ(argv[1], "md5") &&
	// 	!ft_strequ(argv[1], "sha256")))
	// {
	// 	err_usage(NOT_A_HASH, NULL);
	// }
 	// if (ft_strequ(argv[1], "md5"))
 	// {
 	// 	argc == 2 ? ft_md5("") : ft_md5(argv[2]);
 	// }
 	// else if (ft_strequ(argv[1], "sha256"))
 	// {
 	// 	ft_putendl("ok");
 	// }
 	return (0);
}