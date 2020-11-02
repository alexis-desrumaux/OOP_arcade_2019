/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_
#include "IGame.hpp"

class Nibbler : public IGame {
    public:
    //functions
        Nibbler();
        virtual ~Nibbler();
        virtual std::string Talk();
        virtual std::vector<Components *>initMenuGame();
        virtual std::vector<Components *>initGame();
        virtual std::vector<Components *> manageEventMenuGame(std::string &keyPressed);
        virtual cDoubleState manageEventGame(std::string &keyPressed);
        void addInUpdateList(Components *toUpdate);
        void resetListUpdateComponent();
        void resetStateComponents();
    //settings
        std::vector<Components *> components;
        std::vector<Components *> update;
        bool needToBeReInit;
        time_t start;

    protected:
    private:
};

#endif /* !NIBBLER_HPP_ */
