/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include "IGame.hpp"
#include "IGLib.hpp"
#include "Components.hpp"
#define set_playe_name 0
#define select_game_and_graph 1
#define play_game 2
#define display_menu 3

class Core {
    public:
    //functions
        Core();
        Core(std::string);
        ~Core();
        int launch();
        int manageSpecialEventKey();
        int manageStateMenu();
        int testMenu();
        int menu();
        int game();
        int initMenu();
        int initMenuGameSelection();
        int manageEventMenu(std::string &keyPressed);
        int manageEventMenuStateOne(std::string &keyPressed);
        int manageEventMenuStateOneNext(std::string &keyPressed);
        int manageEventMenuStateTwo(std::string &keyPressed);
        void nextGameMenu();
        void *load(std::string _path, int type);
        void assignEventFromGame(cDoubleState received);
        void resetStateComponents(void);
        void resetListUpdateComponent();
        void addInUpdateList(Components *toUpdate);
    //settings
        void *handle_game;
        void *handle_lib;
        IGame *_currentGame;
        IGLib *_currentLib;
        std::vector<std::string> graph_lib;
        std::vector<std::string> games_lib;
        std::vector<Components *> components;
        std::vector<Components *> update;
        int actual_lib;
        int actual_game;
        int menuState;
        std::string keyPressed;
        time_t start;
    protected:
    private:
};

#endif /* !CORE_HPP_ */
