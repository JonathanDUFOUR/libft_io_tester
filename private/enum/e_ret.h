/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:27:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 22:21:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	SUCCESS,
	OPEN_ERR,
	WRITE_ERR,
	CLOSE_ERR,
	REMOVE_ERR,
	FT_PUTCHAR_FD_ERR,
};

#endif
