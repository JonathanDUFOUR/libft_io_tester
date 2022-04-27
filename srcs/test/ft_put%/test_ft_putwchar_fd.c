/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putwchar_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:00:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:30:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	wchar_t const	wc;
	char const		*expect;
};

static t_test const		g_test[] = {
{1, U'ᕕ', "ᕕ"},
{2, U'ꯍ', "ꯍ"},
{3, U'', ""},
{4, U'ऒ', "ऒ"},
{5, U'ਲ਼', "ਲ਼"},
{6, U'', ""},
{7, U'鑠', "鑠"},
{8, U'😄', "😄"},
{9, U'🤪', "🤪"},
{0}
};

static int	test_one(int const i, int const *fd, int *const ret)
{
	char	*buff;
	size_t	len;
	ssize_t	rd;

	len = strlen(g_test[i].expect);
	if (ft_putwchar_fd(g_test[i].wc, fd[1]) == -1)
		return (*ret = FT_PUTWCHAR_FD_ERR);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (*ret = MALLOC_ERR);
	rd = read(fd[0], buff, len);
	if (rd == -1)
	{
		free(buff);
		return (*ret = READ_ERR);
	}
	buff[rd] = 0;
	result(g_test[i].num,
		!strcmp(buff, g_test[i].expect));
	free(buff);
	return (*ret = SUCCESS);
}

int	test_ft_putwchar_fd(int *const ret)
{
	int	fd[2];
	int	i;

	setlocale(LC_CTYPE, "");
	if (pipe(fd) == -1)
		return (*ret = PIPE_ERR);
	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		if (test_one(i, fd, ret))
			return (*ret);
		++i;
	}
	printf("\n");
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}
