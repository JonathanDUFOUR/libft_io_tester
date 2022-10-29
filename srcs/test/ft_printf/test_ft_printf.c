/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:29:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_colors.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;
typedef int(			*t_fct)(int const *fd, int *const ret);

struct s_test
{
	char const	*name;
	t_fct const	run;
};

int	test_literal(int const *fd, int *const ret);
int	test_cvrt_c(int const *fd, int *const ret);
int	test_cvrt_s(int const *fd, int *const ret);
int	test_cvrt_p(int const *fd, int *const ret);
int	test_cvrt_d(int const *fd, int *const ret);
int	test_cvrt_i(int const *fd, int *const ret);
int	test_cvrt_u(int const *fd, int *const ret);
int	test_cvrt_x_lower(int const *fd, int *const ret);
int	test_cvrt_x_upper(int const *fd, int *const ret);
int	test_cvrt_prct(int const *fd, int *const ret);

static t_test const		g_test[] = {
{"Literal", test_literal},
{"%c", test_cvrt_c},
{"%s", test_cvrt_s},
{"%p", test_cvrt_p},
{"%d", test_cvrt_d},
{"%i", test_cvrt_i},
{"%u", test_cvrt_u},
{"%x", test_cvrt_x_lower},
{"%X", test_cvrt_x_upper},
{"%%", test_cvrt_prct},
{0}
};

int	test_ft_printf(int *const ret)
{
	int	fd[2];
	int	i;

	if (pipe(fd) == -1)
		return (*ret = PIPE_ERR);
	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].run)
	{
		printf("\n"YELLOW_FG"[%s]"RESET"\n", g_test[i].name);
		if (g_test[i].run(fd, ret))
			return (*ret);
		++i;
	}
	printf("\n");
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (*ret = CLOSE_ERR);
	return (*ret = SUCCESS);
}
