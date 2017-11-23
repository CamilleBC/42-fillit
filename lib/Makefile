#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/11/13 18:12:06 by cbaillat          #+#    #+#             *#
#*   Updated: 2017/11/14 18:28:12 by cbaillat         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

TARGET_LIB = libft.a

LIB_SRC = 	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memccpy.c\
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \

LIB_OBJ = $(LIB_SRC:.c=.o)

LIB_CFLAGS = -Wall -Werror -Wextra -O3

HEADER = $(TARGET_LIB:.a=.h)

# echo output colours
RED    = \033[1;31m
PURPLE = \033[1;35m
NC     = \033[0m

all: $(TARGET_LIB)

$(TARGET_LIB):
	@echo "[Building ${PURPLE}library${NC}]"
	@gcc $(LIB_CFLAGS) -c $(LIB_SRC)
	@ar rc $(TARGET_LIB) $(LIB_OBJ)

clean:
	@echo "[Cleaning ${PURPLE}lib${NC} objects]"
	@/bin/rm -f $(LIB_OBJ)

fclean: clean
	@echo "[Cleaning ${PURPLE}lib${NC} binary]"
	@/bin/rm -f $(TARGET_LIB)

re: fclean all
