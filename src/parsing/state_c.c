/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:35:29 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/03 19:15:14 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** a string
*/

void		*state_c(char *arg, t_flags *flags)
{
	ft_putendl("STATE_C");
	flags->input = ft_strdup(arg);
	// flags->s = FALSE;
	return (&(state_a));
}
