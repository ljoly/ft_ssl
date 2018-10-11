/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:09:34 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/11 19:36:08 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** anything but a string
*/

void		*state_a(char *arg, t_flags *flags)
{
	flags->s = FALSE;
	flags->p = FALSE;
	if (lex_flags_pqr(arg, flags))
	{
		return (&(state_a));
	}
	else if (lex_flag_s(arg))
	{
		flags->s = TRUE;
		return (&(state_c));
	}
	else if (lex_illegal_opt(arg))
	{
		flags->input = arg;
		err_usage(ILLEGAL_OPTION, flags);
	}
	else
	{
		lex_file(arg, flags);
	}
	return (&(state_b));
}
