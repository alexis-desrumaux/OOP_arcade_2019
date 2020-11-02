##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

ECHO    =       /bin/echo -e

DEFAULT =       "\033[00m"
GREEN   =       "\033[0;32m"
TEAL    =       "\033[1;36m"
RED     =       "\033[5;31m"

NAME	= ../lib_arcade_ncurses.so

CC	= g++

RM	= rm -f

SRCS	= ./src/Ncurses.cpp \
	  ./src/Components.cpp \
	  ./src/Ncurses_c.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/ -fPIC
CPPFLAGS += -Wall -Wextra -lncurses

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) -fPIC -shared $(OBJS)  -o $(NAME) -lncurses && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_ncurses.so" $(DEFAULT)  || \
    $(ECHO) $(RED) "[ERROR]" $(TEAL) lib_arcade_ncurses.so $(DEFAULT)

clean:
	@$(RM) $(OBJS) && \
        $(ECHO) $(TEAL)"  CLEAN : $(OBJS)" $(DEFAULT)
fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CPPFLAGS += -g
debug:	re

.PHONY: all clean fclean re
