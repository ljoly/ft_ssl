/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:45:22 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/04 18:57:19 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void				read_fd(t_flags *flags, int fd)
{
	int				ret;
	char			*buf;
	struct stat		input;
	
	if (!(flags->input = (char*)ft_memalloc(sizeof(char) * 1)))
		err_sys(MALLOC);
	if (fd != 0 && fd != 1)
	{
		if (fstat(fd, &input))
			err_sys(READ);
		flags->size = input.st_size;
		if (!(buf = (char*)ft_memalloc(sizeof(char) * flags->size)))
			err_sys(MALLOC);
		ret = read(fd, buf, flags->size);
		ft_printf("ST_SIZE = %zu && FLAGS->SIZE = %zu\nRET = %d\n", input.st_size, flags->size, ret);
		if (ret == -1)
		{
			err_sys(READ);
		}
		ft_memcpy(flags->input, buf, flags->size);
		free(buf);
		// flags->input = ft_strjoin_and_free(flags->input, buf, '\0', 2);
	}
	// write(1, flags->input, input.st_size);
}
