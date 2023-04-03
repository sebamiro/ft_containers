# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:23:29 by smiro             #+#    #+#              #
#    Updated: 2023/03/20 17:16:23 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE		=	make --no-print-directory

NAME_STD	=	stdTest
NAME_FT		=	ftTest

CONTAINERS	= ../
INC			= inc/
INC_HEADERS	= $(INC)defines.hpp

SRC_DIR		= src/
OBJ_DIR		= obj/

CFLAGS		= -I $(INC) -I $(CONTAINERS) -MMD -Wall -Werror -Wextra -std=c++98
RM			= rm -f
CC			= c++

################################################################################
### COLORS
################################################################################

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

################################################################################
################################################################################

SRC_FILES	=	map_test.cpp \
				stack_test.cpp \
				test.cpp \
				utilsTest.cpp \
				vector_test.cpp \
				set_test.cpp

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP			= 	$(addsuffix .d, $(basename $(OBJ)))
B_OBJ		=	$(OBJ)

################################################################################
################################################################################

all:
			@$(MAKE) $(NAME_STD)
			@$(MAKE) $(NAME_FT)

$(OBJ_DIR)%.o: %.cpp Makefile
			@mkdir -p $(dir $@)
			@printf "\r${ORANGE} | $(BROWN)COMPILING ${ORANGE}|  $(BLUE)< ${MAGENTA}$(notdir $(basename $<)) $(BLUE)> $(DEF_COLOR)%20c"
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_STD):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $@
			@echo "\n\n$(BLUE)[$(ORANGE)============$(BLUE)<|$(ORANGE)DONE$(BLUE)|>$(ORANGE)============$(BLUE)] $(DEF_COLOR)"

$(NAME_FT):	$(OBJ)
			@$(CC) $(CFLAGS) -DFT $(OBJ) -o $@
			@echo "\n\n$(BLUE)[$(ORANGE)============$(BLUE)<|$(ORANGE)DONE$(BLUE)|>$(ORANGE)============$(BLUE)] $(DEF_COLOR)"

-include $(DEP)

clean:
			@$(RM) -r $(OBJ_DIR)
			@echo "\n${RED}[$(MAGENTA)Objects removed successfully${RED}]$(DEF_COLOR)\n"

fclean:
			@$(MAKE) clean
			@$(RM) $(NAME_STD) $(NAME_FT)
			@echo "\n${RED}[$(MAGENTA)Everything removed successfully${RED}]$(DEF_COLOR)\n"

re:
			@$(MAKE) fclean
			@$(MAKE)

.PHONY: all clean fclean re
