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

NAME  := fillit

#directories
SRCS_DIR  := ./srcs
INC_DIR   := ./srcs
BUILD_DIR := ./build
LIB_DIR   := ./libft

# src / obj files
SRCS    :=	main.c \
			algorithm.c \
			input.c \
			map.c \
			output.c \
			utils_input.c \

OBJECTS := $(patsubst %,$(BUILD_DIR)/%,$(SRCS:.c=.o))
# objects dependencies
DEPS       = $(OBJECTS:.o:.d)
DEPS_FLAGS = -MD -MP

# # compiler and flags
CC     := gcc
CFLAGS := -Wall -Wextra -Werror

# # libraries
LIBS := ft
LIB_FLAGS := -L$(LIB_DIR) -l$(LIBS)

# echo output colours
CYAN = \e[1;36m
RED  = \033[1;31m
WHITE  = \033[1;37m
NC   = \033[0m

.PHONY: all clean fclean re

all:
	@mkdir -p $(BUILD_DIR)
	@make $(NAME)

$(NAME): $(OBJECTS)
	@echo "[Building ${RED}executable${NC}]"
	@make -C $(LIB_DIR)/
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(NAME)

$(BUILD_DIR)/%.o:$(SRCS_DIR)/%.c
	@echo "[Building $@...]"
	@$(CC) $(CFLAGS) $(DEPS_FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@echo "[Cleaning ${RED}executable${NC} objects]"
	@make clean -C $(LIB_DIR)
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo  "[Cleaning ${RED}executable${NC}]"
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)
