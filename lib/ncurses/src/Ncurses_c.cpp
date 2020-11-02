/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses_c
*/

#include "../include/Ncurses.hpp"

void Ncurses::LComponent::Sprite::draw(void)
{
    if (this->display == true && this->ascii != "")
        mvprintw(this->position.second, this->position.first, this->ascii.c_str());
}

int Ncurses::LComponent::Sprite::update(Component::Sprite *sprite)
{
    std::pair<Component::State::State, std::vector<Component::Sprite::onChange>> state = sprite->getState();

    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i))
        {
        case Component::Sprite::onChange::_ascii:
        {
            this->ascii = sprite->getAscii().first;
            this->position = sprite->getAscii().second;
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

Ncurses::LComponent::Sprite::Sprite(Component::Sprite *sprite)
{
    this->componentName = sprite->componentName;
    this->display = sprite->display;
    /*std::ofstream myfile;
            myfile.open ("out.txt", std::ios::app);
            myfile << sprite->getAscii().first << std::endl;
            myfile.close();*/
    this->ascii = sprite->getAscii().first;
    this->position = sprite->getAscii().second;
}

Ncurses::LComponent::Sprite::~Sprite()
{

}

/*--------------------------------TEXT-----------------------------------*/

void Ncurses::LComponent::Text::draw(void)
{
    if (this->display == true)
        mvprintw(this->position.second, this->position.first, this->str.c_str());
}

int Ncurses::LComponent::Text::update(Component::Text *text)
{
    std::pair<Component::State::State, std::vector<Component::Text::onChange>> state = text->getState();
    
    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i)) {
            case Component::Text::onChange::_str:
            {
                this->str = text->getText();
                break;
            }
            case Component::Text::onChange::_asciiPos:
            {
                this->position = text->getAsciiPos();
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

Ncurses::LComponent::Text::Text(Component::Text *text)
{
    this->componentName = text->componentName;
    this->display = text->display;
    this->str = text->getText();
    this->position = text->getAsciiPos();
}

Ncurses::LComponent::Text::~Text()
{

}

/*---------------------------LComponents-----------------------------------*/

Ncurses::LComponents *findInLComponents(std::vector<Ncurses::LComponents *> &lcomponents, std::string name)
{
    for (size_t i = 0; i != lcomponents.size(); i += 1) {
        if (lcomponents.at(i)->componentName == name)
            return lcomponents.at(i);
    }
    return NULL;
}