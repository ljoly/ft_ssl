/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:01:27 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/26 21:09:59 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void			*state_initial(char *str, t_arg *arg)
{
	if (lex_hashname(str, arg))
	{
		// return (&state_a);
	}
	return (NULL);
}

void	    		handle_args(int action, char *str, t_arg *arg)
{
	static void		*(*state)(char *str, t_arg *arg);

	if (action == START)
	{
		state = &(state_initial);
		if (!state)
			usage_err(NOT_A_HASH, NULL);
	}
	else if (action = USE)
	{
		state = state(str, arg);
	}
}