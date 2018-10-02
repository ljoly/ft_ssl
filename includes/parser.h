/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:43:00 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/02 20:39:43 by ljoly            ###   ########.fr       */
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

typedef enum    e_name
{
    MD5,
    SHA224,
    SHA256,
    SHA512,
}               t_name;

typedef struct  s_flags
{
    t_name      algo;
    t_bool      sha256;
    t_bool      p;
    t_bool      q;
    t_bool      r;
    t_bool      s;
    t_bool      file_open;
    t_bool      stdin_open;
    t_bool      error_seen;
    t_bool      error;
    char        *input; // copy the string/file/arg here
    int         hashes;
}				t_flags;

void	        handle_args(int action, char *arg, t_flags *flags);
void            read_fd(t_flags *flags, int fd);
void            *state_a(char *arg, t_flags *flags);
void            *state_b(char *arg, t_flags *flags);
void            *state_c(char *arg, t_flags *flags);

t_bool          lex_hashname(char *arg, t_flags *flags);
t_bool          lex_flags_pqr(char *arg, t_flags *flags);
t_bool          lex_flag_s(char *arg);
t_bool          lex_file(char *arg, t_flags *flags);

#endif