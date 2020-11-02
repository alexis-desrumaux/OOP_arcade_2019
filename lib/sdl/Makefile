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

NAME	= ../lib_arcade_sdl1.so

CC	= g++

RM	= rm -f

SRCS	= ./src/Sdl.cpp \
	  ./src/Components.cpp \
	  ./src/Sdl_c.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/ -fPIC
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) -fPIC -shared $(CPPFLAGS) $(OBJS) -o $(NAME) -lSDLmain -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer && \
	$(ECHO) $(GREEN) "[OK]"$(TEAL)"  BUILD : lib_arcade_sdl1.so" $(DEFAULT)  || \
    $(ECHO) $(RED) "[ERROR]" $(TEAL) lib_arcade_sdl1.so $(DEFAULT)

clean:
	@$(RM) $(OBJS) && \
        $(ECHO) $(TEAL)"  CLEAN : $(OBJS)" $(DEFAULT)
fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CPPFLAGS += -g
debug:	re

.PHONY: all clean fclean re
