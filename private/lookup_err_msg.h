/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_err_msg.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:27:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:18:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_ERR_MSG_H
# define LOOKUP_ERR_MSG_H

# include "e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const	err;
	char const	*msg;
};

static t_err_msg const		g_err_msg[] = {
{DUP_ERR, "dup() failed"},
{DUP2_ERR, "dup2() failed"},
{PIPE_ERR, "pipe() failed"},
{READ_ERR, "read() failed"},
{WRITE_ERR, "write() failed"},
{CLOSE_ERR, "close() failed"},
{FSTAT_ERR, "fstat() failed"},
{MALLOC_ERR, "malloc() failed"},
{FFLUSH_ERR, "fflush() failed"},
{FT_FDDEL_ERR, "ft_fddel() failed"},
{FT_PRINTF_ERR, "ft_printf() failed"},
{FT_PUTSTR_FD_ERR, "ft_putstr_fd() failed"},
{FT_PUTENDL_FD_ERR, "ft_putendl_fd() failed"},
{FT_PUTCHAR_FD_ERR, "ft_putchar_fd() failed"},
{FT_PUTBYTE_FD_ERR, "ft_putbyte_fd() failed"},
{FT_PUTBYTES_FD_ERR, "ft_putbytes_fd() failed"},
{FT_PUTHHINT_FD_ERR, "ft_puthhint_fd() failed"},
{FT_PUTHHUINT_FD_ERR, "ft_puthhuint_fd() failed"},
{FT_PUTHINT_FD_ERR, "ft_puthint_fd() failed"},
{FT_PUTHUINT_FD_ERR, "ft_puthuint_fd() failed"},
{FT_PUTINT_FD_ERR, "ft_putint_fd() failed"},
{FT_PUTUINT_FD_ERR, "ft_putuint_fd() failed"},
{FT_PUTLINT_FD_ERR, "ft_putlint_fd() failed"},
{FT_PUTLUINT_FD_ERR, "ft_putluint_fd() failed"},
{FT_PUTLLINT_FD_ERR, "ft_putllint_fd() failed"},
{FT_PUTLLUINT_FD_ERR, "ft_putlluint_fd() failed"},
{FT_PUTHHINT_BASE_FD_ERR, "ft_puthhint_base_fd() failed"},
{FT_PUTHHUINT_BASE_FD_ERR, "ft_puthhuint_base_fd() failed"},
{FT_PUTHINT_BASE_FD_ERR, "ft_puthint_base_fd() failed"},
{FT_PUTHUINT_BASE_FD_ERR, "ft_puthuint_base_fd() failed"},
{FT_PUTINT_BASE_FD_ERR, "ft_putint_base_fd() failed"},
{FT_PUTUINT_BASE_FD_ERR, "ft_putuint_base_fd() failed"},
{FT_PUTLINT_BASE_FD_ERR, "ft_putlint_base_fd() failed"},
{FT_PUTLUINT_BASE_FD_ERR, "ft_putluint_base_fd() failed"},
{FT_PUTLLINT_BASE_FD_ERR, "ft_putllint_base_fd() failed"},
{FT_PUTLLUINT_BASE_FD_ERR, "ft_putlluint_base_fd() failed"},
{FT_PUTWCHAR_FD_ERR, "ft_putwchar_fd() failed"},
{0}
};

#endif
