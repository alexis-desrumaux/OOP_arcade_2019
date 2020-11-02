/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <iostream>
#include <Components.hpp>

#define cDoubleState std::pair<std::pair<std::vector<Components *>, bool>, std::vector<Components *>>

class IGame
{
    public:
        IGame() = default;
        virtual ~IGame() = default;
        virtual std::string Talk() = 0;
        virtual std::vector<Components *> initMenuGame() = 0;
        virtual std::vector<Components *> initGame() = 0;
        virtual std::vector<Components *> manageEventMenuGame(std::string &keyPressed) = 0;
        virtual cDoubleState manageEventGame(std::string &keyPressed) = 0;
};

#endif /* !IGAME_HPP_ */
