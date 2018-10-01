/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:09:34 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 17:48:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** anything but a string
*/
void        *state_a(char *arg, t_flags *flags)
{
    if (lex_flags_pqr(arg, flags))
    {
        return (&(state_a));
    }
    else if (lex_flag_s(arg))
    {
        flags->s = TRUE;
        return (&(state_c));
    }
    // else if (lex_file(arg, flags))
    // {
    //     // return (&state_b)); // meme chose que state_a sans les flags
    // }
    return (NULL);
}
