##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

ECHO    =       /bin/echo -e

DEFAULT =       "\033[00m"
GREEN   =       "\033[0;32m"
TEAL    =       "\033[1;36m"
RED     =       "\033[5;31m"


MY_CORE					= arcade
MY_GAMES_1				= ./games/lib_arcade_pacman.so
MY_GAMES_2				= ./games/lib_arcade_nibbler.so
MY_GRAPHICALS_1	        = ./lib/lib_arcade_sfml.so
MY_GRAPHICALS_2	        = ./lib/lib_arcade_ncurses.so
MY_GRAPHICALS_3	        = ./lib/lib_arcade_sdl1.so

CC	= g++

RM	= rm -f

M = make

all: $(MY_CORE) $(MY_GAMES_1) $(MY_GAMES_2) $(MY_GRAPHICALS_1) $(MY_GRAPHICALS_2)  $(MY_GRAPHICALS_3)

$(MY_CORE):
	@$(M) --no-print-directory -C src/

$(MY_GAMES_1):
	@$(M) --no-print-directory -C games/src/pacman/

$(MY_GAMES_2):
	@$(M) --no-print-directory -C games/src/nibbler/

$(MY_GRAPHICALS_1):
	@$(M) --no-print-directory -C lib/sfml/

$(MY_GRAPHICALS_2):
	@$(M) --no-print-directory -C lib/ncurses/

$(MY_GRAPHICALS_3):
	@$(M) --no-print-directory -C lib/sdl/


core:	$(MY_CORE)

games:	$(MY_GAMES_1) $(MY_GAMES_2)

graphicals:	$(MY_GRAPHICALS_1) $(MY_GRAPHICALS_2) $(MY_GRAPHICALS_3)


clean:
	@make clean --no-print-directory -C src/
	@make clean --no-print-directory -C lib/ncurses/
	@make clean --no-print-directory -C lib/sfml/
	@make clean --no-print-directory -C lib/sdl/
	@make clean --no-print-directory -C games/src/pacman/
	@make clean --no-print-directory -C games/src/nibbler/

fclean: clean
	@$(RM) $(MY_CORE) && \
        $(ECHO) $(TEAL)"  CLEAN : arcade" $(DEFAULT)
	@$(RM) $(MY_GAMES_1) && \
        $(ECHO) $(TEAL)"  CLEAN : lib_arcade_nibbler.so" $(DEFAULT)
	@$(RM) $(MY_GAMES_2) && \
        $(ECHO) $(TEAL)"  CLEAN : lib_arcade_pacman.so" $(DEFAULT)
	@$(RM) $(MY_GRAPHICALS_1) && \
        $(ECHO) $(TEAL)"  CLEAN : lib_arcade_sfml.so" $(DEFAULT)
	@$(RM) $(MY_GRAPHICALS_2) && \
        $(ECHO) $(TEAL)"  CLEAN : lib_arcade_ncurses.so" $(DEFAULT)
	@$(RM) $(MY_GRAPHICALS_3) && \
        $(ECHO) $(TEAL)"  CLEAN : lib_arcade_sdl1.so" $(DEFAULT)

re: fclean all

debug:	M += debug
debug:	re

.PHONY: all clean fclean re debug core graphicals games
