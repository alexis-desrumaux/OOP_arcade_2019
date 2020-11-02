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

NAME	= ../../lib_arcade_pacman.so

CC	= g++

RM	= rm -f

SRCS	= ./src/Pacman.cpp \
	  ./src/Components.cpp \
	  ./src/GameObjects/GameObject.cpp \
	  ./src/GameObjects/Objects/Pacman.cpp \
	  ./src/GameObjects/Objects/Wall.cpp \
	  ./src/GameObjects/Objects/Map.cpp \
	  ./src/GameObjects/Objects/Empty.cpp \
	  ./src/GameObjects/Objects/Switcher.cpp \
	  ./src/GameObjects/Objects/PacGomme.cpp \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/ -fPIC
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) -fPIC -shared $(OBJS) -o $(NAME) && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_pacman.so" $(DEFAULT)  || \
    $(ECHO) $(RED) "[ERROR]" $(TEAL) lib_arcade_pacman.so $(DEFAULT)

clean:
	@$(RM) $(OBJS) && \
        $(ECHO) $(TEAL)"  CLEAN : $(OBJS)" $(DEFAULT)
fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CPPFLAGS += -g
debug:	re

.PHONY: all clean fclean re
