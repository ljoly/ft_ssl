/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:35:29 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 17:48:58 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** a string
*/
void            *state_c(char *arg, t_flags *flags)
{
    flags->input = arg;
    flags->s = FALSE;
    return (&(state_a));
}
