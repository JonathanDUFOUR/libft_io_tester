/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:27:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/25 18:44:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	SUCCESS,
	PIPE_ERR,
	READ_ERR,
	CLOSE_ERR,
	MALLOC_ERR,
	FT_PUTSTR_FD_ERR,
	FT_PUTENDL_FD_ERR,
	FT_PUTCHAR_FD_ERR,
	FT_PUTBYTE_FD_ERR
};

#endif
