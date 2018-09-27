/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_hashname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:05:16 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/27 17:19:18 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_bool      lex_hashname(char *str, t_arg *arg)
{
    if (ft_strequ("md5", str) || ft_strequ("sha256", str))
    {
        if (ft_strequ("md5", str))
            arg->md5 = TRUE;
        return (TRUE);
    }
    return (FALSE);
}