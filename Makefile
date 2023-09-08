# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jferreir <jferreir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:07:52 by jferreir          #+#    #+#              #
#    Updated: 2022/02/23 10:42:55 by jferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ PROGRAM ################

NAME    =        push_swap
NAME_BONUS =	 checker

################ TERMINAL ###############

RMV        =        rm -f
MKD        =        mkdir
PRT        =        printf
MKE        =        make
CPY        =        cp

################# COLORS ################

--GRN    =        \033[32m
--RED    =        \033[31m
--WHT    =        \033[39m

################# DIRS ##################

_SRC    =        src/
_OBJ 	=		 obj/
_LIB    =        libs/
_BIN    =        ./

############### COMPILER ################

CC        =        gcc
CF        =        -Wall -Werror -Wextra

################ FILES ##################

SRCS    =        $(_SRC)ps_main.c
SRCS_BONUS	=	 $(_SRC)checker.c $(_SRC)checker_moves.c $(_SRC)get_next_line.c $(_SRC)get_next_line_utils.c \
				 $(_SRC)checker_utils.c
OBJS    =        $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))
OBJS_BONUS	=	 $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS_BONUS))
DEPS    =        $(_LIB)libft.a $(_LIB)libps.a
LIBS    =        -lft -lps

################ RULES ##################

all: $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CF) $(LIBS) $(OBJS) -o $@ -L $(_LIB)

bonus: $(DEPS) $(OBJS_BONUS) all
	$(CC) $(CF) $(LIBS) $(OBJS_BONUS) -o $(NAME_BONUS) -L $(_LIB)

################ DEPS ###################

$(_LIB)libft.a: $(shell make -C libft/ -q libft.a || echo force)
	$(MKE) bonus -C libft/

$(_LIB)libps.a: $(shell make -C src/ -q libps.a || echo force)
	$(MKE) libps.a -C src/

############## STRUCTURE ################

$(_OBJ):
	$(MKD) $(_OBJ)

$(_LIB):
	$(MKD) $(_LIB)

$(_SRC):
	$(MKD) $(_SRC)

$(_BIN):
	$(MKD) $(_BIN)

################### CLEAN ###############

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(NAME)
	$(RMV) -r $(NAME_BONUS)
	$(RMV) -r $(_LIB)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re force
