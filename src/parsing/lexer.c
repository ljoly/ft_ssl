/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:05:48 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/08 11:23:01 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_bool		lex_flag_s(char *arg)
{
	return (ft_strequ("-s", arg));
}

t_bool		lex_flags_pqr(char *arg, t_flags *flags)
{
	if (!ft_strequ("-p", arg) && !ft_strequ("-q", arg) && !ft_strequ("-r", arg))
		return (FALSE);
	if (ft_strequ("-p", arg))
	{
		if (flags->stdin_open)
		{
			flags->size = 0;
			flags->input = ft_strdup("");
		}
		else
		{
			flags->stdin_open = TRUE;
			flags->p = TRUE;
			read_fd(flags, STDIN);
		}
	}
	else if (ft_strequ("-q", arg))
	{
		flags->r = FALSE;
		flags->q = TRUE;
	}
	else if (ft_strequ("-r", arg))
	{
		if (!flags->q)
			flags->r = TRUE;
	}
	return (TRUE);
}

t_bool		lex_file(char *arg, t_flags *flags)
{
	int		fd;

	flags->file_open = TRUE;
	flags->input = ft_strdup(arg);
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		err_usage(NOT_A_FILE, flags);
		return (FALSE);
	}
	// free(flags->input);
	read_fd(flags, fd);
	return (TRUE);
}

t_bool		lex_hashname(char *arg, t_flags *flags)
{
	if (ft_strequ("md5", arg) || ft_strequ("sha256", arg))
	{
		if (ft_strequ("md5", arg))
			flags->algo = MD5;
		else if (ft_strequ("sha256", arg))
			flags->algo = SHA256;
		return (TRUE);
	}
	return (FALSE);
}
