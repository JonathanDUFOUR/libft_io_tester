/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:27:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/25 17:37:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_LOOKUP_H
# define ERR_MSG_LOOKUP_H

# include "enum/e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const	err;
	char const	*msg;
};

static t_err_msg const		g_err_msg[] = {
{PIPE_ERR, "pipe() failed"},
{READ_ERR, "read() failed"},
{CLOSE_ERR, "close() failed"},
{MALLOC_ERR, "malloc() failed"},
{FT_PUTCHAR_FD_ERR, "ft_putchar_fd() failed"},
{FT_PUTENDL_FD_ERR, "ft_putendl_fd() failed"},
{0}
};

#endif
