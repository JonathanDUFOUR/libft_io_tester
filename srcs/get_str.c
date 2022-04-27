/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:11:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:33:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "e_ret.h"

static char	*strjoin(char const *s0, char const *s1)
{
	char	*output;
	char	*ptr;
	size_t	len;

	len = 0;
	if (s0)
		len = strlen(s0);
	if (s1)
		len += strlen(s1);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (s0 && *s0)
		*ptr++ = *s0++;
	while (s1 && *s1)
		*ptr++ = *s1++;
	*ptr = 0;
	return (output);
}

int	get_str(char **const str, int const *fd, int *const ret)
{
	char	buff[4097];
	char	*tmp;
	ssize_t	rd;

	rd = read(fd[0], buff, 4096);
	while (rd > 0)
	{
		buff[rd] = 0;
		*str = strjoin(buff, tmp = *str);
		free(tmp);
		if (!*str)
			return (*ret = MALLOC_ERR);
		if (rd < 4096)
			return (*ret = SUCCESS);
		rd = read(fd[0], buff, 4096);
	}
	if (rd == -1)
		free(*str);
	return (*ret = !!rd * READ_ERR);
}
