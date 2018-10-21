/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 17:45:30 by ljoly             #+#    #+#             */
/*   Updated: 2018/10/21 18:44:26 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void        handle_prompt(t_flags *flags)
{
    int     ret;
    char    *line;
    char    *tmp;
    t_bool  err;

    line = NULL;
    ft_printf("ft_ssl> ");
    while ((ret = get_next_line(STDIN, &tmp)) > 0)
    {
        err = TRUE;
        line = ft_strtrim(tmp);
        free(tmp);
        if (lex_hashname(line))
        {
            read_fd(flags, STDIN);
            handle_input(line, flags);
        }
        else if (line[0])
            print_err(FALSE, flags);
        free(line);
        if (err)
            ft_printf("ft_ssl> ");
        if (flags->hashes)
            exit(0);
    }
}
