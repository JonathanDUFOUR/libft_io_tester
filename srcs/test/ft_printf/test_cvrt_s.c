/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cvrt_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:08:56 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:29:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_io.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*str0;
	char const	*str1;
	char const	*str2;
};

static t_test const		g_test[] = {
{1, NULL, "Hello", "World !"},
{2, "%s is funny", "", "A"},
{3, "42", "101010", "2a"},
{4, "What if I put convert in string ?", "%d%%%i%u%x%X", "..."},
{5, "Tadaaaaaaa!", "yes", "no"},
{6, "LeT's", "AlT eR nAtE", "lOwErS n UpPeRs"},
{7, NULL, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
Cras sit amet felis magna. Phasellus eleifend rhoncus consectetur. \
Proin auctor orci vitae sodales congue. \
Proin condimentum blandit leo, a egestas quam consequat sed. \
Nullam faucibus varius magna, nec condimentum massa faucibus vitae. \
Nam condimentum consequat sapien, ac hendrerit nulla ornare eu. \
Etiam non nulla faucibus, consequat felis sed, euismod lectus. \
Sed vitae ex ac nisl viverra commodo sit amet eu augue. \
Donec gravida nibh ac sollicitudin lacinia. \
Sed non dolor sagittis, pulvinar elit in, interdum dolor. \
Phasellus eu nibh fringilla, consequat ex sed, placerat justo. \
Duis pulvinar vel tortor vel tincidunt. \
Vestibulum aliquet ipsum eu venenatis auctor. \
Suspendisse ultrices vitae nulla ac euismod. \
Duis vitae ex convallis nisi vestibulum egestas. \
Nulla malesuada eget turpis sed commodo. \
Nullam varius in enim a rutrum. \
Maecenas efficitur ullamcorper nunc at efficitur. \
Suspendisse bibendum tortor vitae velit dignissim, \
bibendum bibendum urna nullam.", NULL},
{0}
};

static int	call0(int const i, int const *fd, int *r, int *const ret)
{
	int	save;

	save = dup(STDOUT_FILENO);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (close(STDOUT_FILENO) == -1)
		return (*ret = CLOSE_ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	r[0] = printf("First str: %s| Second str: %s| Third str: %s",
			g_test[i].str0, g_test[i].str1, g_test[i].str2);
	if (fflush(stdout))
		return (*ret = FFLUSH_ERR);
	if (dup2(save, STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	if (close(save) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}

static int	call1(int const i, int const *fd, int *r, int *const ret)
{
	int	save;

	save = dup(STDOUT_FILENO);
	if (save == -1)
		return (*ret = DUP_ERR);
	if (close(STDOUT_FILENO) == -1)
		return (*ret = CLOSE_ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	r[1] = ft_printf("First str: %s| Second str: %s| Third str: %s",
			g_test[i].str0, g_test[i].str1, g_test[i].str2);
	if (dup2(save, STDOUT_FILENO) == -1)
		return (*ret = DUP2_ERR);
	if (close(save) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}

static int	test_one(int const i, int const *fd, int *const ret)
{
	char	*str[2];
	int		r[2];

	str[0] = NULL;
	str[1] = NULL;
	if (call0(i, fd, r, ret))
		return (*ret);
	if (get_str(&str[0], fd, ret))
		return (*ret);
	if (call1(i, fd, r, ret))
		return (*ret);
	if (get_str(&str[1], fd, ret))
		return (*ret);
	result(g_test[i].num,
		r[0] == r[1] && ((!str[0] && !str[1]) || !strcmp(str[0], str[1])));
	if (fflush(stdout))
		return (*ret = FFLUSH_ERR);
	free(str[0]);
	free(str[1]);
	return (*ret = SUCCESS);
}

int	test_cvrt_s(int const *fd, int *const ret)
{
	int	i;

	i = 0;
	while (g_test[i].num)
	{
		if (test_one(i, fd, ret))
			return (*ret);
		++i;
	}
	return (*ret = SUCCESS);
}
