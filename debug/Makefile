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

TARGET_DBG := fillit_debug

#directories
SRCS_DIR  := ../srcs
INC_DIR   := ../srcs
BUILD_DIR := ../build
LIB_DIR   := ../lib

# src / obj files
SRCS    :=	main.c \
			algorithm.c
OBJECTS := $(patsubst %,$(BUILD_DIR)/%,$(SRCS:.c=.o))
# objects dependencies
DEPS       = $(OBJECTS:.o:.d)
DEPS_FLAGS = -MD -MP

# # compiler and flags
CC     := gcc
DBG_FLAGS := -Og -g

# # libraries
LIBS := ft
LIB_FLAGS := -L$(LIB_DIR) -l$(LIBS)

# echo output colours
WHITE  = \033[1;37m
CYAN = \e[1;36m
NC   = \033[0m

.PHONY: all clean fclean re

all:
	@mkdir -p $(BUILD_DIR)
	@make -C $(LIB_DIR)/
	@make $(TARGET_DBG)

$(TARGET_DBG): $(OBJECTS)
	@echo "[Building ${WHITE}debug${NC}]"
	@$(CC) $(DBG_FLAGS) $(OBJECTS) $(LIB_FLAGS) -o $(TARGET_DBG)

$(BUILD_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(CC) $(DBG_FLAGS) $(DEPS_FLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@echo "[Cleaning ${WHITE}debug${NC} objects]"
	@make clean -C $(LIB_DIR)
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo  "[Cleaning ${WHITE}debug${NC}]"
	@make fclean -C $(LIB_DIR)
	@rm -rf $(TARGET_DBG)

re: fclean all

-include $(DEPS)
