/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:34:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/25 18:22:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*str;
	char const	*expect;
};

static t_test const		g_test[] = {
{1, "", "\n"},
{2, "koala", "koala\n"},
{3, "g", "g\n"},
{4, "42 est une ecole grandiose !", "42 est une ecole grandiose !\n"},
{5, "\t\n\n\t", "\t\n\n\t\n"},
{6, "D0n't w0rry, b3 h4ppy", "D0n't w0rry, b3 h4ppy\n"},
{7, "hKuNa MaTaTa!@#$%^&*()", "hKuNa MaTaTa!@#$%^&*()\n"},
{8, "\x12\x99\xaa", "\x12\x99\xaa\n"},
{9, "fcuf873t9R%*QYDOHCH*(W@(*bvjb66++", "fcuf873t9R%*QYDOHCH*(W@(*bvjb66++\n"},
{0}
};

static int	test_one(int const i, int const *fd, int *const ret)
{
	char	*buff;
	size_t	len;
	ssize_t	rd;

	len = strlen(g_test[i].expect);
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (*ret = MALLOC_ERR);
	if (ft_putendl_fd(g_test[i].str, fd[1]) == -1)
	{
		free(buff);
		return (*ret = FT_PUTENDL_FD_ERR);
	}
	rd = read(fd[0], buff, len + 1);
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

int	test_ft_putendl_fd(int *const ret)
{
	int	fd[2];
	int	i;

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
