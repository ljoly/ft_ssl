/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:43:00 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/17 20:19:50 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "flags.h"
# include "error.h"
# include "sys/stat.h"

typedef enum	e_run
{
	START,
	USE,
	END,
}				t_run;

void			handle_args(int action, char *arg, t_flags *flags);
void			read_fd(t_flags *flags, int fd);
void			*state_a(char *arg, t_flags *flags);
void			*state_b(char *arg, t_flags *flags);
void			*state_c(char *arg, t_flags *flags);

t_bool			lex_hashname(char *arg);
t_bool			lex_flags_pqr(char *arg, t_flags *flags);
t_bool			lex_flag_s(char *arg);
t_bool			lex_file(char *arg, t_flags *flags);
t_bool			lex_illegal_opt(char *arg);

#endif
