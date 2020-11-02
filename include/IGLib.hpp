/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GLib
*/

#ifndef IGLIB_HPP_
#define IGLIB_HPP_

#include <iostream>
#include <fstream>
#include "Command.hpp"
#include "Components.hpp"

class IGLib {
    public:
    //functions
        IGLib() = default;
        virtual ~IGLib() = default;
        virtual std::string display(std::vector<Components *>) = 0;
        virtual int initLib(std::vector<Components *>) = 0;
        std::string name;
        int state;
    //settings
        bool isRunning;
        int type;
    protected:
    private:
};

#endif /* !IGLIB_HPP_ */
