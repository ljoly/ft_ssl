/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 20:02:57 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/17 20:13:01 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "libft.h"

typedef enum	e_name
{
	MD5,
	SHA224,
	SHA256,
}				t_name;

typedef struct	s_flags
{
	t_name		algo;
	t_bool		p;
	t_bool		q;
	t_bool		r;
	t_bool		s;
	t_bool		file_open;
	t_bool		stdin_open;
	t_bool		error_seen;
	t_bool		error;
	char		*input;
	size_t		size;
	size_t		hashes;
}				t_flags;

#endif