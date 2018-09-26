/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:43:00 by ljoly             #+#    #+#             */
/*   Updated: 2018/09/26 21:01:51 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef enum    e_run
{
    START,
    USE,
}               t_run;

typedef struct  s_arg
{
    t_bool      md5;
    t_bool      p;
    t_bool      q;
    t_bool      r;
    t_bool      s;
    char        *input;
}				t_arg;

void	        handle_args(int action, char *str, t_arg *arg);

#endif