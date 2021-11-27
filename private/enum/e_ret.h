/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:27:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/27 13:38:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	SUCCESS,
	PIPE_ERR,
	READ_ERR,
	WRITE_ERR,
	CLOSE_ERR,
	MALLOC_ERR,
	FT_PUTSTR_FD_ERR,
	FT_PUTENDL_FD_ERR,
	FT_PUTCHAR_FD_ERR,
	FT_PUTBYTE_FD_ERR,
	FT_PUTBYTES_FD_ERR,
	FT_PUTHHINT_FD_ERR,
	FT_PUTHHUINT_FD_ERR,
	FT_PUTHINT_FD_ERR,
	FT_PUTHUINT_FD_ERR,
	FT_PUTINT_FD_ERR,
	FT_PUTUINT_FD_ERR,
	FT_PUTLINT_FD_ERR,
	FT_PUTLUINT_FD_ERR,
	FT_PUTLLINT_FD_ERR,
	FT_PUTLLUINT_FD_ERR,
	FT_PUTHHINT_BASE_FD_ERR,
	FT_PUTHHUINT_BASE_FD_ERR,
	FT_PUTHINT_BASE_FD_ERR,
	FT_PUTHUINT_BASE_FD_ERR,
	FT_PUTINT_BASE_FD_ERR,
	FT_PUTUINT_BASE_FD_ERR,
	FT_PUTLINT_BASE_FD_ERR,
	FT_PUTLUINT_BASE_FD_ERR,
	FT_PUTLLINT_BASE_FD_ERR,
	FT_PUTLLUINT_BASE_FD_ERR,
	FT_PUTWCHAR_FD_ERR
};

#endif
