/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:05:45 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/10 18:16:45 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum		e_sys
{
    READ,
    MALLOC,
}					t_sys;

typedef enum        e_usage
{
    NOT_A_FILE,
    NO_STRING,
    NOT_A_HASH,
    ILLEGAL_OPTION,
	IS_DIRECTORY
}                   t_usage;

void                err_sys(t_sys err_code);
void                err_usage(t_usage err_code, t_flags *flags);

#endif