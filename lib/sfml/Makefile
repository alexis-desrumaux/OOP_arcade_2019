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

NAME	= ../lib_arcade_sfml.so

CC	= g++

RM	= rm -f

SRCS	= ./src/Sfml.cpp \
	  ./src/Components.cpp \
	  ./src/Sfml_c.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/ -fPIC
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) -fPIC -shared $(CPPFLAGS) $(OBJS) -o $(NAME) -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system -logg && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_sfml.so" $(DEFAULT)  || \
    $(ECHO) $(RED) "[ERROR]" $(TEAL) lib_arcade_sfml.so $(DEFAULT)

clean:
	@$(RM) $(OBJS) && \
        $(ECHO) $(TEAL)"  CLEAN : $(OBJS)" $(DEFAULT)
fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CPPFLAGS += -g
debug:	re

.PHONY: all clean fclean re
