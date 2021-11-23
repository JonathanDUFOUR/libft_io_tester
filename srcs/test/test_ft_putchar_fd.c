/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:34:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/23 22:29:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "ft_io.h"
#include "tester.h"
#include "enum/e_ret.h"

#define LOG_FILE	"ft_putchar_fd.log"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	c;
};

static t_test const		g_test[] = {
{1, 0},
{2, '*'},
{3, '0'},
{4, '+'},
{5, '('},
{6, '<'},
{7, -111},
{8, -1},
{9, CHAR_MAX},
{10, CHAR_MIN},
{0}
};

int	test_ft_putchar_fd(int *const ret)
{
	int	fd;
	int	i;

	fd = open(LOG_FILE, O_RDWR | O_CREAT, 0600);
	if (fd == -1)
		return (*ret = OPEN_ERR);
	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		++i;
	}
	printf("\n");
	if (close(fd) == -1)
		return (*ret = CLOSE_ERR);
	if (remove(LOG_FILE) == -1)
		return (*ret = REMOVE_ERR);
	return (*ret = SUCCESS);
}
