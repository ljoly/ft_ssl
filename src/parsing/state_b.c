/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:10:18 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/28 20:02:49 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** a file or nothing
*/
void        *state_b(char *arg, t_flags *flags)
{
    if (lex_file(arg, flags))
    {
        return (&state_b);
    }
    return (NULL);
}