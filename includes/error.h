/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:05:45 by ljoly             #+#    #+#             */
/*   Updated: 2018/07/09 18:09:10 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum		e_error
{
    USAGE,
    OPEN,
    READ,
    MALLOC,
}					t_error;

void                ft_err(t_error err_code);

#endif