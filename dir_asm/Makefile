# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:56:45 by cgiron            #+#    #+#              #
#    Updated: 2019/09/30 16:50:02 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_dir_asm.mk
include ../libft/dependancies_libft.mk
include ../shared_val.mk

ifeq ($(CHECK_ASM_DEP),)
$(error ASM_DEPENDANCIES not included)
endif
ifeq ($(CHECK_SHARED_VAL),)
$(error SHARE_VAL not included)
endif
ifeq ($(CHECK_LIBFT_DEP),)
$(error LIBFT_DEPENDANCIES not included)
endif

L_FT    := ../libft
EXFLAGS := -L $(L_FT) -lft $(SHARE_FLAGS)
SIMULINK := $(SHARE_INC_DIR)/$(NAME_LIBFT)

NAME 	:= $(NAME_ASM)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_ASM)
INC		:= $(INC_ASM)
OBJ		:= $(patsubst %.c,%.o,$(SRC))

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)

.PHONY: all clean fclean re debug simulink depend

all: $(NAME)

simulink:
	rm -rf	$(INC_DIR)/$(L_LIBFT_DIR)
	rm -rf	$(INC_DIR)/op.h
	rm -rf	$(SRC_DIR)/op.c
	ln -s 	../../shared_resource/op.h $(INC_DIR)
	ln -s 	../../shared_resource/op.c $(SRC_DIR)
	ln -s	../$(L_FT)/$(INC_DIR) $(INC_DIR)/$(L_LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_ASM_O)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OPTI_FLAGS) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

$(NAME): $(OBJ) $(DEPENDANCIES_ASM)
	$(MAKE) -C $(L_FT) "OPTI_FLAGS=$(OPTI_FLAGS)" --no-print-directory
	$(CC) $(OPTI_FLAGS) $(CFLAGS) $(EXFLAGS)  $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(NAME)

depend: depend.mk

depend.mk: $(SRC) $(INC)
		rm -f ./depend.mk
		$(CC) $(CFLAGS) -MM $^ -MG >> ./depend.mk;

ifneq ($(MAKECMDGOALS), clean)
ifneq ($(MAKECMDGOALS), simulink)
ifneq ($(MAKECMDGOALS), fclean)
ifneq ($(MAKECMDGOALS), re)
include   depend.mk
endif
endif
endif
endif

re: fclean depend all

clean:
	$(MAKE) clean -C $(L_FT) --no-print-directory
	rm -f ./depend.mk
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(L_FT) --no-print-directory
	rm -f $(NAME)

debug: OPTI_FLAGS := $(SHARE_DEBUG)
debug: re clean
