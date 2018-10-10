/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:45:22 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/10 20:00:44 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void			handle_stdin(t_flags *flags)
{
	int				ret;
	char			buf[2];

	if (!(flags->input = (char*)ft_memalloc(sizeof(char) * 2)))
	{
		err_sys(MALLOC);
	}
	while ((ret = read(STDIN, buf, 1)))
	{
		if (ret == -1)
		{
			err_sys(READ);
		}
		buf[1] = '\0';
		flags->input = ft_strjoin_and_free(flags->input, buf, '\0', 1);
	}
	flags->size = ft_strlen(flags->input);
}

void				read_fd(t_flags *flags, int fd)
{
	int				ret;
	struct stat		input;

	if (fd == STDIN)
		handle_stdin(flags);
	else
	{
		if (fstat(fd, &input))
		{
			err_sys(READ);
		}
		if (S_ISDIR(input.st_mode))
		{
			err_usage(IS_DIRECTORY, flags);
			return ;
		}
		flags->size = input.st_size;
		if (!(flags->input = (char*)ft_memalloc(sizeof(char) * flags->size)))
		{
			err_sys(MALLOC);
		}
		ret = read(fd, flags->input, flags->size);
		if (ret == -1)
			err_sys(READ);
	}
}
