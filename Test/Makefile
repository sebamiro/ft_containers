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

CONTAINERS	=	../
INC			=	inc/

SRC_DIR		=	src/

OBJ_DIR		=	obj/
BIN_DIR		=	bin/
DEP_DIR		=	dep/

CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
CFLAGS		+=	-MMD -MP -MF $(DEP_DIR)$*.d

RM			=	rm -rf
CC			=	c++

COMFLAGS	=	-I $(INC) -I $(CONTAINERS)

################################################################################

SRC_LIST	:=	$(shell find $(SRC_DIR:/=) -type d)

SRC			:=	$(shell find $(SRC_DIR:/=) -name '*.cpp')
OBJ 		=	$(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.cpp=.o))
DEP 		=	$(patsubst $(SRC_DIR)%, $(DEP_DIR)%, $(SRC:.cpp=.d))
BIN_STD		=	$(addprefix $(BIN_DIR), $(NAME_STD))
BIN_FT		=	$(addprefix $(BIN_DIR), $(NAME_FT))

################################################################################

all:
			@$(MAKE) $(BIN_STD)
			@$(MAKE) $(BIN_FT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp Makefile
			@echo "compiling.. $(notdir $<)"
			@$(CC) $(COMFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_STD):	$(OBJ_DIR) $(DEP_DIR) $(BIN_DIR) $(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $@
			@echo "$(notdir $@): done"

$(BIN_FT):	$(OBJ_DIR) $(DEP_DIR) $(BIN_DIR) $(OBJ)
			@$(CC) $(CFLAGS) -DFT $(OBJ) -o $@
			@echo "$(notdir $@): done"

$(BIN_DIR):
			@mkdir -p $@
			@echo "creating.. $@"

$(OBJ_DIR):
			@mkdir $(patsubst $(SRC_DIR:/=)%, $(@:/=)%, $(SRC_LIST))
			@echo "creating.. $@"

$(DEP_DIR):
			@mkdir $(patsubst $(SRC_DIR:/=)%, $(@:/=)%, $(SRC_LIST))
			@echo "creating.. $@"


clean:
			@$(RM) $(OBJ_DIR) $(DEP_DIR)
			@echo "removing.. $(OBJ_DIR)"
			@echo "removing.. $(DEP_DIR)"

fclean:
			@$(MAKE) clean
			@$(RM) $(BIN_DIR)
			@echo "removing.. $(BIN_DIR)"

re:
			@$(MAKE) fclean
			@$(MAKE)

.PHONY: all clean fclean re
-include $(DEP)
