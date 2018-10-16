/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:45:22 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/16 18:32:07 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void			read_last_bytes(t_flags *flags, int fd, size_t iter)
{
	char			*buf;
	char			*tmp;
	size_t			i;
	ssize_t			ret;

	i = flags->size % INT_MAX;
	if (!(buf = (char*)malloc(sizeof(char) * i)))
		err_sys(MALLOC);
	ret = read(fd, buf, i);
	if (ret == -1)
	{
		err_sys(READ);
	}
	tmp = (char*)malloc(sizeof(char) * iter * INT_MAX);
	ft_memcpy(tmp, flags->input, iter * INT_MAX);
	free(flags->input);
	flags->input = (char*)ft_memalloc(sizeof(char) * iter * INT_MAX + i);
	ft_memcpy(flags->input, tmp, iter * INT_MAX);
	ft_memcpy(&flags->input[iter * INT_MAX], buf, i);
	free(tmp);
	free(buf);
}

/*
** Builtin function read handles INT_MAX sized files only
*/

static void			handle_big_files(t_flags *flags, int fd)
{
	char			*buf;
	char			*tmp;
	ssize_t			ret;
	size_t			i;

	if (!(flags->input = (char*)malloc(sizeof(char) * 1)))
		err_sys(MALLOC);
	if (!(buf = (char*)malloc(sizeof(char) * INT_MAX)))
		err_sys(MALLOC);
	i = -1;
	while (++i < flags->size / INT_MAX)
	{
		ret = read(fd, buf, INT_MAX);
		if (ret == -1)
			err_sys(READ);
		tmp = (char*)malloc(sizeof(char) * i * INT_MAX);
		ft_memcpy(tmp, flags->input, i * INT_MAX);
		free(flags->input);
		flags->input = (char*)malloc(sizeof(char) * (i + 1) * INT_MAX);
		ft_memcpy(flags->input, tmp, i * INT_MAX);
		ft_memcpy(&flags->input[i * INT_MAX], buf, INT_MAX);
		free(tmp);
	}
	free(buf);
	read_last_bytes(flags, fd, i);
}

static void			handle_small_files(t_flags *flags, int fd)
{
	ssize_t			ret;

	if (!(flags->input = (char*)malloc(sizeof(char) * flags->size)))
	{
		err_sys(MALLOC);
	}
	ret = read(fd, flags->input, flags->size);
	if (ret == -1)
	{
		err_sys(READ);
	}
}

static void			handle_stdin(t_flags *flags)
{
	ssize_t			ret;
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
	struct stat		input;

	if (fd == STDIN)
		handle_stdin(flags);
	else
	{
		if (fstat(fd, &input))
			err_sys(READ);
		if (S_ISDIR(input.st_mode))
		{
			err_usage(IS_DIRECTORY, flags);
			return ;
		}
		flags->size = input.st_size;
		free(flags->input);
		flags->input = NULL;
		if (flags->size > INT_MAX)
		{
			handle_big_files(flags, fd);
		}
		else
		{
			handle_small_files(flags, fd);
		}
	}
}
