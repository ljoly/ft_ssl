/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 20:02:57 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 17:02:05 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include "libft.h"

typedef struct	s_flags
{
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
