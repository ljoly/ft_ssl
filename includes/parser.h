/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:43:00 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/27 19:25:56 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef enum    e_run
{
    START,
    USE,
    END,
}               t_run;

typedef struct  s_arg
{
    t_bool      md5;
    t_bool      p;
    t_bool      q;
    t_bool      r;
    t_bool      s;
    t_bool      file_opened;
    char        *input;
}				t_arg;

void	        handle_args(int action, char *str, t_arg *arg);
void            *state_a(char *str, t_arg *arg);

t_bool          lex_hashname(char *str, t_arg *arg);
t_bool          lex_flags_pqr(char *str, t_arg *arg);
t_bool          lex_file(char *str, t_arg *arg);
t_bool          lex_blank(char *str, t_arg *arg);

#endif