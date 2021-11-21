# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 00:16:26 by jodufour          #+#    #+#              #
#    Updated: 2021/11/21 17:22:48 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC				=	clang -c -o
LINK			=	clang -o
MKDIR			=	mkdir -p
RM				=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME			=	libft_io_unit_test

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/
INC_DIR			=	
PRV_DIR			=	private/

FT_IO_DIR		=	../
FT_IO_INC_DIR	=	include/
FT_IO_INC_DIR	:=	${addprefix ${FT_IO_DIR}, ${FT_IO_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_IO_A			=	libft_io.a
FT_IO_A			:=	${addprefix ${FT_IO_DIR}, ${FT_IO_A}}

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					${addprefix test/,				\
						test_ft_atohhi_base.c		\
						test_ft_atohhi.c			\
						test_ft_atohhu_base.c		\
						test_ft_atohhu.c			\
						test_ft_atohi_base.c		\
						test_ft_atohi.c				\
						test_ft_atohu_base.c		\
						test_ft_atohu.c				\
						test_ft_atoi_base.c			\
						test_ft_atoi.c				\
						test_ft_atoli_base.c		\
						test_ft_atoli.c				\
						test_ft_atolli_base.c		\
						test_ft_atolli.c			\
						test_ft_atollu_base.c		\
						test_ft_atollu.c			\
						test_ft_atolu_base.c		\
						test_ft_atolu.c				\
						test_ft_atou_base.c			\
						test_ft_atou.c				\
						test_ft_cat.c				\
						test_ft_convert_base.c		\
						test_ft_ctoa.c				\
						test_ft_fddel.c				\
						test_ft_file_size.c			\
						test_ft_hhintlen_base.c		\
						test_ft_hhintlen.c			\
						test_ft_hhitoa_base.c		\
						test_ft_hhitoa.c			\
						test_ft_hhuintlen_base.c	\
						test_ft_hhuintlen.c			\
						test_ft_hhutoa_base.c		\
						test_ft_hhutoa.c			\
						test_ft_hintlen_base.c		\
						test_ft_hintlen.c			\
						test_ft_hitoa_base.c		\
						test_ft_hitoa.c				\
						test_ft_huintlen_base.c		\
						test_ft_huintlen.c			\
						test_ft_hutoa_base.c		\
						test_ft_hutoa.c				\
						test_ft_indexof.c			\
						test_ft_intlen_base.c		\
						test_ft_intlen.c			\
						test_ft_isalnum.c			\
						test_ft_isalpha.c			\
						test_ft_isascii.c			\
						test_ft_isdigit.c			\
						test_ft_islower.c			\
						test_ft_isprint.c			\
						test_ft_isspace.c			\
						test_ft_isupper.c			\
						test_ft_isvalid.c			\
						test_ft_itoa_base.c			\
						test_ft_itoa.c				\
						test_ft_lintlen_base.c		\
						test_ft_lintlen.c			\
						test_ft_litoa_base.c		\
						test_ft_litoa.c				\
						test_ft_llintlen_base.c		\
						test_ft_llintlen.c			\
						test_ft_llitoa_base.c		\
						test_ft_llitoa.c			\
						test_ft_lluintlen_base.c	\
						test_ft_lluintlen.c			\
						test_ft_llutoa_base.c		\
						test_ft_llutoa.c			\
						test_ft_luintlen_base.c		\
						test_ft_luintlen.c			\
						test_ft_lutoa_base.c		\
						test_ft_lutoa.c				\
						test_ft_printf.c			\
						test_ft_putbyte_fd.c		\
						test_ft_putbytes_fd.c		\
						test_ft_putchar_fd.c		\
						test_ft_putendl_fd.c		\
						test_ft_puthhint_base_fd.c	\
						test_ft_puthhint_fd.c		\
						test_ft_puthhuint_base_fd.c	\
						test_ft_puthhuint_fd.c		\
						test_ft_puthint_base_fd.c	\
						test_ft_puthint_fd.c		\
						test_ft_puthuint_base_fd.c	\
						test_ft_puthuint_fd.c		\
						test_ft_putint_base_fd.c	\
						test_ft_putint_fd.c			\
						test_ft_putlint_base_fd.c	\
						test_ft_putlint_fd.c		\
						test_ft_putllint_base_fd.c	\
						test_ft_putllint_fd.c		\
						test_ft_putlluint_base_fd.c	\
						test_ft_putlluint_fd.c		\
						test_ft_putluint_base_fd.c	\
						test_ft_putluint_fd.c		\
						test_ft_putstr_fd.c			\
						test_ft_putuint_base_fd.c	\
						test_ft_putuint_fd.c		\
						test_ft_putwchar_fd.c		\
						test_ft_tolower.c			\
						test_ft_toupper.c			\
						test_ft_uintlen_base.c		\
						test_ft_uintlen.c			\
						test_ft_utoa_base.c			\
						test_ft_utoa.c				\
						test_get_next_line.c		\
					}								\
					err_msg.c						\
					main.c							\
					result.c

######################################
#            OBJECT FILES            #
######################################
OBJ			=	${SRC:.c=.o}
OBJ			:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP			=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-MMD -MP
CFLAGS		+=	-I${PRV_DIR}
CFLAGS		+=	-I${FT_IO_INC_DIR}

LDFLAGS		=	-L${FT_IO_DIR} -lft_io

ifeq (${DEBUG}, 1)
	CPPFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ} ${FT_IO_A}
	${LINK} $@ $^ ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

${FT_IO_A}:
	${MAKE} ${@F} -C ${@D}

update:
	git submodule update --remote

clean:
	${RM} ${OBJ_DIR}

fclean:
	${RM} ${OBJ_DIR} ${NAME}
ifeq (${REC}, 1)
	${MAKE} $@ -C ${FT_IO_DIR}
endif

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

re:	fclean all

.PHONY:	all clean fclean re update
