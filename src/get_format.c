/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:52:05 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 23:02:30 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	get_format_1024(t_env *e)
{
	if (e->input_bitsize)
		e->input_bitsize += 128;
	e->blocks = 1 + e->input_bitsize / 1024;
	e->padding_bitsize = e->blocks * 1024 - e->input_bitsize % 1024;
	if (e->blocks > 1)
	{
		e->padding_bitsize -= 1024 * (e->blocks - 1);
	}
}

void	get_format_512(t_env *e)
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
