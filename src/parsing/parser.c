/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:01:27 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/27 19:26:31 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		init_arg(t_arg *arg)
{
	arg->md5 = FALSE;
	arg->p = FALSE;
	arg->q = FALSE;
	arg->r = FALSE;
	arg->s = FALSE;
	arg->file_opened = FALSE;
	arg->input = NULL;
}

static void			*state_initial(char *str, t_arg *arg)
{
	if (lex_hashname(str, arg))
	{
		return (&state_a);
	}
	else
	{
		err_usage(NOT_A_HASH, NULL);
	}
	return (NULL);
}

/*
** Parsing the arguments using a state-machine
*/
void	    		handle_args(int action, char *str, t_arg *arg)
{
	static void		*(*state)(char *str, t_arg *arg);

	init_arg(arg);
	if (action == START)
	{
		state = &(state_initial);
	}
	else if (action == USE)
	{
		state = state(str, arg);
	}
}