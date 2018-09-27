/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:09:34 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/27 19:19:51 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** anything but a string
*/
void        *state_a(char *str, t_arg *arg)
{
    if (lex_blank(str, arg))
    {
        return (NULL);
    }
    else if (lex_flags_pqr(str, arg))
    {
        return (&(state_a));
    }
    else if (lex_flag_s(str, arg))
    {
        // return (&(state_d));
    }
    else if (lex_file(str, arg))
    {
        // return (&state_b)); // meme chose que state_a sans les flags
    }
    return (NULL);
}
