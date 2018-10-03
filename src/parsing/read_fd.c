/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:45:22 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/03 17:31:26 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		read_fd(t_flags *flags, int fd)
{
	int		ret;
	char	buf[2];

	if (!(flags->input = (char*)ft_memalloc(sizeof(char) * 2)))
		err_sys(MALLOC);
	while ((ret = read(fd, buf, 1)))
	{
		if (ret == -1)
		{
			err_sys(READ);
		}
		buf[1] = '\0';
		flags->input = ft_strjoin_and_free(flags->input, buf, '\0', 1);
	}
}
