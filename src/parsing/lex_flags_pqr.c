/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_flags_pqr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:40:10 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/27 19:03:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_bool      lex_flags_pqr(char *str, t_arg *arg)
{
    if (!ft_strequ("-p", str) && ft_strequ("-q", str) && ft_strequ("-r", str))
        return (FALSE);
    if (ft_strequ("-p", str))
    {
        if (arg->p)
        {
            //print ""
        }
        else
        {
            arg->p = TRUE;
            //print STDIN
        }
    }
    else if (ft_strequ("-q", str))
    {
        arg->r = FALSE;
        arg->q = TRUE;
    }
    else if (ft_strequ("-r", str))
    {
        if (!arg->q)
            arg->r = TRUE;
    }
    return (TRUE);
}
