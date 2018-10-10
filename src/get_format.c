/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:52:05 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/10 20:09:08 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	get_format(t_env *e)
{
	if (e->input_bitsize)
		e->input_bitsize += 64;
	e->blocks = 1 + e->input_bitsize / 512;
	e->padding_bitsize = e->blocks * 512 - e->input_bitsize % 512;
	if (e->blocks > 1)
	{
		e->padding_bitsize -= 512 * (e->blocks - 1);
	}
}
