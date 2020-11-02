/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <fstream>
#include <iostream>
#include "IGLib.hpp"

namespace Ncurses
{
    class LComponents {
        public:
        //functions
            LComponents() = default;
            virtual ~LComponents() = default;
            virtual void draw() = 0;
        //settings
            std::string componentName;
            bool display;
    };
    namespace LComponent {
        class Sprite : public LComponents {
            public:
            //functions
                Sprite(Component::Sprite *);
                virtual ~Sprite();
                int update(Component::Sprite *);
                void draw();
            private:
            //settings
                std::string box;
                std::string ascii;
                std::pair<int, int> position;
        };
        class Text : public LComponents {
            public:
            //functions
                Text(Component::Text *);
                virtual ~Text();
                virtual int update(Component::Text *);
                void draw();
            private:
            //settings
                std::string str;
                Component::Color::Color color;
                std::pair<int, int> position;
        };
    }
    class Ncurses : public IGLib {
        public:
            Ncurses();
            virtual ~Ncurses();
            virtual std::string display(std::vector<Components *>);
            virtual int initLib(std::vector<Components *>);
            int manageUpdate(std::vector<Components *>);
            int draw(void);
            virtual int getEventKey();
            virtual void setEventKey(int);
            //int draw(Components *);
            //int drawText(Component::Text *);
        protected:
        private:
            std::string name;
            std::vector<LComponents *> lComponents;
            int eventKey;
            int widht;
            int height;
            int type;
    };
}

Ncurses::LComponents *findInLComponents(std::vector<Ncurses::LComponents *> &lcomponents, std::string name);

#endif /* !NCURSES_HPP_ */
