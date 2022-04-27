/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:14:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:19:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_TEST_H
# define LOOKUP_TEST_H

typedef struct s_test	t_test;
typedef int				(*t_fct)(int *const ret);

struct s_test
{
	char const	*name;
	t_fct const	fct;
};

int	test_ft_atohhi(int *const ret);
int	test_ft_atohhi_base(int *const ret);
int	test_ft_atohhu(int *const ret);
int	test_ft_atohhu_base(int *const ret);
int	test_ft_atohi(int *const ret);
int	test_ft_atohi_base(int *const ret);
int	test_ft_atohu(int *const ret);
int	test_ft_atohu_base(int *const ret);
int	test_ft_atoi(int *const ret);
int	test_ft_atoi_base(int *const ret);
int	test_ft_atoli(int *const ret);
int	test_ft_atoli_base(int *const ret);
int	test_ft_atolli(int *const ret);
int	test_ft_atolli_base(int *const ret);
int	test_ft_atollu(int *const ret);
int	test_ft_atollu_base(int *const ret);
int	test_ft_atolu(int *const ret);
int	test_ft_atolu_base(int *const ret);
int	test_ft_atosize(int *const ret);
int	test_ft_atou(int *const ret);
int	test_ft_atou_base(int *const ret);
int	test_ft_convert_base(int *const ret);
int	test_ft_ctoa(int *const ret);
int	test_ft_fddel(int *const ret);
int	test_ft_hhintlen(int *const ret);
int	test_ft_hhintlen_base(int *const ret);
int	test_ft_hhitoa(int *const ret);
int	test_ft_hhitoa_base(int *const ret);
int	test_ft_hhuintlen(int *const ret);
int	test_ft_hhuintlen_base(int *const ret);
int	test_ft_hhutoa(int *const ret);
int	test_ft_hhutoa_base(int *const ret);
int	test_ft_hintlen(int *const ret);
int	test_ft_hintlen_base(int *const ret);
int	test_ft_hitoa(int *const ret);
int	test_ft_hitoa_base(int *const ret);
int	test_ft_huintlen(int *const ret);
int	test_ft_huintlen_base(int *const ret);
int	test_ft_hutoa(int *const ret);
int	test_ft_hutoa_base(int *const ret);
int	test_ft_indexof(int *const ret);
int	test_ft_intlen(int *const ret);
int	test_ft_intlen_base(int *const ret);
int	test_ft_isalnum(int *const ret);
int	test_ft_isalpha(int *const ret);
int	test_ft_isascii(int *const ret);
int	test_ft_isdigit(int *const ret);
int	test_ft_islower(int *const ret);
int	test_ft_isprint(int *const ret);
int	test_ft_isspace(int *const ret);
int	test_ft_isupper(int *const ret);
int	test_ft_isvalid(int *const ret);
int	test_ft_itoa(int *const ret);
int	test_ft_itoa_base(int *const ret);
int	test_ft_lintlen(int *const ret);
int	test_ft_lintlen_base(int *const ret);
int	test_ft_litoa(int *const ret);
int	test_ft_litoa_base(int *const ret);
int	test_ft_llintlen(int *const ret);
int	test_ft_llintlen_base(int *const ret);
int	test_ft_llitoa(int *const ret);
int	test_ft_llitoa_base(int *const ret);
int	test_ft_lluintlen(int *const ret);
int	test_ft_lluintlen_base(int *const ret);
int	test_ft_llutoa(int *const ret);
int	test_ft_llutoa_base(int *const ret);
int	test_ft_luintlen(int *const ret);
int	test_ft_luintlen_base(int *const ret);
int	test_ft_lutoa(int *const ret);
int	test_ft_lutoa_base(int *const ret);
int	test_ft_printf(int *const ret);
int	test_ft_putbyte_fd(int *const ret);
int	test_ft_putbytes_fd(int *const ret);
int	test_ft_putchar_fd(int *const ret);
int	test_ft_putendl_fd(int *const ret);
int	test_ft_puthhint_base_fd(int *const ret);
int	test_ft_puthhint_fd(int *const ret);
int	test_ft_puthhuint_base_fd(int *const ret);
int	test_ft_puthhuint_fd(int *const ret);
int	test_ft_puthint_base_fd(int *const ret);
int	test_ft_puthint_fd(int *const ret);
int	test_ft_puthuint_base_fd(int *const ret);
int	test_ft_puthuint_fd(int *const ret);
int	test_ft_putint_base_fd(int *const ret);
int	test_ft_putint_fd(int *const ret);
int	test_ft_putlint_base_fd(int *const ret);
int	test_ft_putlint_fd(int *const ret);
int	test_ft_putllint_base_fd(int *const ret);
int	test_ft_putllint_fd(int *const ret);
int	test_ft_putlluint_base_fd(int *const ret);
int	test_ft_putlluint_fd(int *const ret);
int	test_ft_putluint_base_fd(int *const ret);
int	test_ft_putluint_fd(int *const ret);
int	test_ft_putstr_fd(int *const ret);
int	test_ft_putuint_base_fd(int *const ret);
int	test_ft_putuint_fd(int *const ret);
int	test_ft_putwchar_fd(int *const ret);
int	test_ft_tolower(int *const ret);
int	test_ft_toupper(int *const ret);
int	test_ft_uintlen(int *const ret);
int	test_ft_uintlen_base(int *const ret);
int	test_ft_utoa(int *const ret);
int	test_ft_utoa_base(int *const ret);
int	test_get_next_line(int *const ret);

static t_test const		g_test[] = {
{"ft_atohhi", test_ft_atohhi},
{"ft_atohhi_base", test_ft_atohhi_base},
{"ft_atohhu", test_ft_atohhu},
{"ft_atohhu_base", test_ft_atohhu_base},
{"ft_atohi", test_ft_atohi},
{"ft_atohi_base", test_ft_atohi_base},
{"ft_atohu", test_ft_atohu},
{"ft_atohu_base", test_ft_atohu_base},
{"ft_atoi", test_ft_atoi},
{"ft_atoi_base", test_ft_atoi_base},
{"ft_atoli", test_ft_atoli},
{"ft_atoli_base", test_ft_atoli_base},
{"ft_atolli", test_ft_atolli},
{"ft_atolli_base", test_ft_atolli_base},
{"ft_atollu", test_ft_atollu},
{"ft_atollu_base", test_ft_atollu_base},
{"ft_atolu", test_ft_atolu},
{"ft_atolu_base", test_ft_atolu_base},
{"ft_atosize", test_ft_atosize},
{"ft_atou", test_ft_atou},
{"ft_atou_base", test_ft_atou_base},
{"ft_convert_base", test_ft_convert_base},
{"ft_ctoa", test_ft_ctoa},
{"ft_fddel", test_ft_fddel},
{"ft_hhintlen", test_ft_hhintlen},
{"ft_hhintlen_base", test_ft_hhintlen_base},
{"ft_hhitoa", test_ft_hhitoa},
{"ft_hhitoa_base", test_ft_hhitoa_base},
{"ft_hhuintlen", test_ft_hhuintlen},
{"ft_hhuintlen_base", test_ft_hhuintlen_base},
{"ft_hhutoa", test_ft_hhutoa},
{"ft_hhutoa_base", test_ft_hhutoa_base},
{"ft_hintlen", test_ft_hintlen},
{"ft_hintlen_base", test_ft_hintlen_base},
{"ft_hitoa", test_ft_hitoa},
{"ft_hitoa_base", test_ft_hitoa_base},
{"ft_huintlen", test_ft_huintlen},
{"ft_huintlen_base", test_ft_huintlen_base},
{"ft_hutoa", test_ft_hutoa},
{"ft_hutoa_base", test_ft_hutoa_base},
{"ft_indexof", test_ft_indexof},
{"ft_intlen", test_ft_intlen},
{"ft_intlen_base", test_ft_intlen_base},
{"ft_isalnum", test_ft_isalnum},
{"ft_isalpha", test_ft_isalpha},
{"ft_isascii", test_ft_isascii},
{"ft_isdigit", test_ft_isdigit},
{"ft_islower", test_ft_islower},
{"ft_isprint", test_ft_isprint},
{"ft_isspace", test_ft_isspace},
{"ft_isupper", test_ft_isupper},
{"ft_isvalid", test_ft_isvalid},
{"ft_itoa", test_ft_itoa},
{"ft_itoa_base", test_ft_itoa_base},
{"ft_lintlen", test_ft_lintlen},
{"ft_lintlen_base", test_ft_lintlen_base},
{"ft_litoa", test_ft_litoa},
{"ft_litoa_base", test_ft_litoa_base},
{"ft_llintlen", test_ft_llintlen},
{"ft_llintlen_base", test_ft_llintlen_base},
{"ft_llitoa", test_ft_llitoa},
{"ft_llitoa_base", test_ft_llitoa_base},
{"ft_lluintlen", test_ft_lluintlen},
{"ft_lluintlen_base", test_ft_lluintlen_base},
{"ft_llutoa", test_ft_llutoa},
{"ft_llutoa_base", test_ft_llutoa_base},
{"ft_luintlen", test_ft_luintlen},
{"ft_luintlen_base", test_ft_luintlen_base},
{"ft_lutoa", test_ft_lutoa},
{"ft_lutoa_base", test_ft_lutoa_base},
{"ft_putbyte_fd", test_ft_putbyte_fd},
{"ft_putbytes_fd", test_ft_putbytes_fd},
{"ft_putchar_fd", test_ft_putchar_fd},
{"ft_putendl_fd", test_ft_putendl_fd},
{"ft_puthhint_base_fd", test_ft_puthhint_base_fd},
{"ft_puthhint_fd", test_ft_puthhint_fd},
{"ft_puthhuint_base_fd", test_ft_puthhuint_base_fd},
{"ft_puthhuint_fd", test_ft_puthhuint_fd},
{"ft_puthint_base_fd", test_ft_puthint_base_fd},
{"ft_puthint_fd", test_ft_puthint_fd},
{"ft_puthuint_base_fd", test_ft_puthuint_base_fd},
{"ft_puthuint_fd", test_ft_puthuint_fd},
{"ft_putint_base_fd", test_ft_putint_base_fd},
{"ft_putint_fd", test_ft_putint_fd},
{"ft_putlint_base_fd", test_ft_putlint_base_fd},
{"ft_putlint_fd", test_ft_putlint_fd},
{"ft_putllint_base_fd", test_ft_putllint_base_fd},
{"ft_putllint_fd", test_ft_putllint_fd},
{"ft_putlluint_base_fd", test_ft_putlluint_base_fd},
{"ft_putlluint_fd", test_ft_putlluint_fd},
{"ft_putluint_base_fd", test_ft_putluint_base_fd},
{"ft_putluint_fd", test_ft_putluint_fd},
{"ft_putstr_fd", test_ft_putstr_fd},
{"ft_putuint_base_fd", test_ft_putuint_base_fd},
{"ft_putuint_fd", test_ft_putuint_fd},
{"ft_putwchar_fd", test_ft_putwchar_fd},
{"ft_tolower", test_ft_tolower},
{"ft_toupper", test_ft_toupper},
{"ft_uintlen", test_ft_uintlen},
{"ft_uintlen_base", test_ft_uintlen_base},
{"ft_utoa", test_ft_utoa},
{"ft_utoa_base", test_ft_utoa_base},
{"get_next_line", test_get_next_line},
{"ft_printf", test_ft_printf},
{0}
};

#endif
