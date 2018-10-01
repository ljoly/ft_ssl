/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:01:27 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 17:40:40 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void			*state_final(t_flags *flags)
{
	if (flags->s)
		err_usage(NO_STRING, flags);
	else
		get_stdin(flags);
	return (NULL);
}

static void			*state_initial(char *arg, t_flags *flags)
{
	if (lex_hashname(arg, flags))
	{
		return (&state_a);
	}
	else
	{
		err_usage(NOT_A_HASH, flags);
	}
	return (NULL);
}

/*
** Parsing the arguments using a state-machine
*/
void	    		handle_args(int action, char *arg, t_flags *flags)
{
	static void		*(*state)(char *arg, t_flags *flags);

	if (action == START)
	{
		state = &(state_initial);
	}
	else if (action == USE)
	{
		state = state(arg, flags);
	}
	else if (action == END)
	{
		if (!flags->hashes)
		{
			state_final(flags);
		}
	}
}