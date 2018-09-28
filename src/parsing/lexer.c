/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:05:48 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/28 21:21:21 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_bool      lex_flag_s(char *arg)
{
    return (ft_strequ("-s", arg));
}

t_bool      lex_flags_pqr(char *arg, t_flags *flags)
{
    if (!ft_strequ("-p", arg) && !ft_strequ("-q", arg) && !ft_strequ("-r", arg))
        return (FALSE);
    if (ft_strequ("-p", arg))
    {
        if (flags->p)
        {
            //print ""
        }
        else
        {
            flags->p = TRUE;
            //print STDIN
        }
    }
    else if (ft_strequ("-q", arg))
    {
        flags->r = FALSE;
        flags->q = TRUE;
    }
    else if (ft_strequ("-r", arg))
    {
        if (!flags->q)
            flags->r = TRUE;
    }
    return (TRUE);
}

t_bool      lex_blank(char *arg)
{
    return (arg == NULL);
}

t_bool       lex_file(char *arg, t_flags *flags)
{
    (void)arg;
    (void)flags;
    return (FALSE);
}

t_bool      lex_hashname(char *arg, t_flags *flags)
{
    if (ft_strequ("md5", arg) || ft_strequ("sha256", arg))
    {
        if (ft_strequ("md5", arg))
            flags->md5 = TRUE;
        return (TRUE);
    }
    return (FALSE);
}