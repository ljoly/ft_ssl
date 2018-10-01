/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:06:13 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/01 17:21:04 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void        get_stdin(t_flags *flags)
{
	int     ret;
    char    buf[2];

    if (!(flags->input = (char*)ft_memalloc(sizeof(char) * 2)))
        err_sys(MALLOC);
	while ((ret = read(0, buf, 1)))
	{
		if (ret == -1)
			break;
        buf[1] = '\0';
        flags->input = ft_strjoin_and_free(flags->input, buf, '\0', 1);	
    }
}
