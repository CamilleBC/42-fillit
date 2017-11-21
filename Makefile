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

#TARGET_EXEC ?= fillit
#
#CC = gcc
#
#BUILD_DIR ?= ./build
#LIB_DIR ?= ./lib
#SRC_DIR ?= .
#INC_DIR := .
#
#SRCS := main.c
#OBJECTSS := $(SRCS:%=$(BUILD_DIR)/%.o)
#DEPS := $(OBJECTSS:.o=.d)
#
#INC_FLAGS := $(addprefix -I,$(INC_DIRS))
#LDFLAGS := -I$(LIB_DIR)
#
#CFLAGS ?= $(INC_FLAGS) -Wall -Werror -Wextra
#
#$(BUILD_DIR)/$(TARGET_EXEC): $(OBJECTSS)
#		$(CC) $(OBJECTSS) -o $@ $(LDFLAGS)
#
#$(BUILD_DIR)/%.o: %.c
#	$(MKDIR_P) $(dir $@)
#	$(CC) $(CFLAGS) -c $< -o $@
#
#.PHONY: clean
#
#clean:
#	$(RM) -r $(BUILD_DIR)
#
#fclean: clean
#	$(RM) $(TARGET_EXEC)
#
#-include $(DEPS)
#
#MKDIR_P ?= mkdir -p
#
#############################################

TARGET_EXEC = fillit
CC = gcc
RM = /bin/rm
MKDIR_P ?= mkdir -p

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

INC_DIR = .
BUILD_DIR = build

LIB_DIR := ./lib
LIBS = ft
LIB_FLAGS = -L$(LIB_DIR) -l$(LIBS)

_DEPS = fillit.h /lib/libft.h
#DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))

_OBJECTS = main.o
OBJECTS = $(patsubst %,$(BUILD_DIR)/%,$(_OBJECTS))


$(TARGET_EXEC): $(OBJECTS)
		gcc -o $@ $^ $(CFLAGS) $(LIB_FLAGS)

$(BUILD_DIR)/%.o: %.c $(DEPS)
		$(MKDIR_P) $(BUILD_DIR)
		$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	$(RM) -f $(BUILD_DIR)/*.o *~ core $(INCDIR)/*~ 

fclean: clean
	$(RM) $(TARGET_EXEC)
