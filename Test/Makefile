# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 13:00:11 by smiro             #+#    #+#              #
#    Updated: 2023/03/05 16:20:11 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_STD	=	stdTest
NAME_FT		=	ftTest
MKFL		=	Makefile

SRC			=	test.cpp utilsTest.cpp vector_test.cpp map_test.cpp stack_test.cpp

OBJS		=	$(SRC:.cpp=.o)

RM			=	rm -f
CPP			=	c++
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98

%.o: %.cpp $(MKFL) defines.hpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

all:
	@$(MAKE) $(NAME_STD)
	@$(MAKE) $(NAME_FT)

$(NAME_STD): $(OBJS)
	@$(CPP) $(OBJS) -o $(NAME_STD)
	@echo DONE STD

$(NAME_FT): $(OBJS)
	@$(CPP) $(OBJS) -DFT -o $(NAME_FT)
	@echo DONE FT

clean:
	@$(RM) $(OBJS)

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean fclean re
