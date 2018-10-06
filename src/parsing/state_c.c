/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:35:29 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/06 17:35:32 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** a string
*/

void		*state_c(char *arg, t_flags *flags)
{
	flags->size = ft_strlen(arg);
	flags->input = ft_strdup(arg);
	return (&(state_a));
}
