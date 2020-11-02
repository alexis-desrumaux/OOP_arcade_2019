/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#include <vector>
#include "Ncurses.hpp"

void Ncurses::Ncurses::setEventKey(int nb)
{
    this->eventKey = nb;
}

int Ncurses::Ncurses::getEventKey()
{
    return this->eventKey;
}

/*int Ncurses::get_name_player(std::string name)
{
    return 0;
}*/

/*int Ncurses::drawText(Component::Text *mc)
{
    std::pair<float, float> xy = mc->getPosXY();
    int height = xy.first;
    int widht = xy.second;
    mvprintw(height, widht, mc->getText().c_str());
    return 0;
}*/

/*int Ncurses::draw(Components *components)
{
    dynamic_cast<Component::Text *>(components->at(1))->setPosXY(std::pair<float, float>(this->height / 2 - 5, this->widht / 2 - 10));
    dynamic_cast<Component::Text *>(components->at(2))->setPosXY(std::pair<float, float>(this->height / 2, this->widht / 2 - this->name.size() / 2));
    dynamic_cast<Component::Text *>(components->at(2))->setText(this->name);
    for (size_t i = 0; i != components->size(); i += 1) {
        if (dynamic_cast<Component::Text *>(components->at(i)) != NULL)
            drawText(dynamic_cast<Component::Text *>(components->at(i)));
    }
    return 0;
}*/

std::string NcursesKeyToString(int keycode)
{
    std::string keyStr;

    if (keycode != -32 && keycode != 0 && keycode != -1) {
    }
    switch (keycode) {
        case 'a': keyStr = "A"; break;
        case 'b': keyStr = "B"; break;
        case 'c': keyStr = "C"; break;
        case 'd': keyStr = "D"; break;
        case 'e': keyStr = "E"; break;
        case 'f': keyStr = "F"; break;
        case 'g': keyStr = "G"; break;
        case 'h': keyStr = "H"; break;
        case 'i': keyStr = "I"; break;
        case 'j': keyStr = "J"; break;
        case 'k': keyStr = "K"; break;
        case 'l': keyStr = "L"; break;
        case 'm': keyStr = "M"; break;
        case 'n': keyStr = "N"; break;
        case 'o': keyStr = "O"; break;
        case 'p': keyStr = "P"; break;
        case 'q': keyStr = "Q"; break;
        case 'r': keyStr = "R"; break;
        case 's': keyStr = "S"; break;
        case 't': keyStr = "T"; break;
        case 'u': keyStr = "U"; break;
        case 'v': keyStr = "V"; break;
        case 'w': keyStr = "W"; break;
        case 'x': keyStr = "X"; break;
        case 'y': keyStr = "Y"; break;
        case 'z': keyStr = "Z"; break;
        case KEY_BACKSPACE: keyStr = "Back"; break;
        case 10: keyStr = "Return"; break;
        case KEY_END: keyStr = "End"; break;
        case KEY_LEFT: keyStr = "Left"; break;
        case KEY_RIGHT: keyStr = "Right"; break;
        case KEY_UP: keyStr = "Up"; break;
        case KEY_DOWN: keyStr = "Down"; break;
        case KEY_F(1): keyStr = "F1"; break;
        case KEY_F(2): keyStr = "F2"; break;
        case KEY_F(3): keyStr = "F3"; break;
        case KEY_F(4): keyStr = "F4"; break;
        case KEY_F(5): keyStr = "F5"; break;
        case KEY_F(6): keyStr = "F6"; break;
    }
    return keyStr;
}

int Ncurses::Ncurses::draw(void)
{

    for (size_t i = 0; i != this->lComponents.size(); i += 1) {
        this->lComponents.at(i)->draw();
    }
    return 0;
}

int Ncurses::Ncurses::manageUpdate(std::vector<Components *> update)
{
    for (size_t i = 0; i != update.size(); i += 1) {
        if (findInLComponents(this->lComponents, update.at(i)->componentName) != NULL) {
            findInLComponents(this->lComponents, update.at(i)->componentName)->display = update.at(i)->display;
            switch (update.at(i)->type)
            {
            case listComponent::TEXT:
            {
                Component::Text *text = dynamic_cast<Component::Text *>(update.at(i));
                if (text->getState().first == Component::State::UPDATE) {
                   LComponent::Text *c = dynamic_cast<LComponent::Text *>(findInLComponents(this->lComponents, text->componentName));
                   c->update(text);
                }
                break;
            }
            case listComponent::SPRITE:
            {
                Component::Sprite *sprite = dynamic_cast<Component::Sprite *>(update.at(i));
                if (sprite->getState().first == Component::State::UPDATE) {
                   LComponent::Sprite *c = dynamic_cast<LComponent::Sprite *>(findInLComponents(this->lComponents, sprite->componentName));
                   c->update(sprite);
                }
                break;
            }
            default:
                break;
            }
        }
    }
    return 0;
}

std::string Ncurses::Ncurses::display(std::vector<Components *> update)
{
    std::string keyPressed = "";

    keypad(stdscr, TRUE);
    keyPressed = NcursesKeyToString(getch());

    if (keyPressed == "End") {
        curs_set(TRUE);
        endwin();
        this->isRunning = false;
    }
    else if (keyPressed == "F4" || keyPressed == "F5") {
        curs_set(TRUE);
        endwin();
    }
    if (!update.empty())
        erase();
    manageUpdate(update);
    draw();
    return keyPressed;
}

void deleteUnusedLComponents(std::vector<Ncurses::LComponents *>&lComponents, std::vector<size_t> listLComponentSavedIndex)
{
    for (size_t j = 0; j != lComponents.size(); j += 1) {
        bool found = false;
        for (size_t i = 0; i != listLComponentSavedIndex.size(); i += 1) {
            if (j == listLComponentSavedIndex.at(i)) {
                found = true;
                break;
            }
        }
        if (!found)
            delete lComponents.at(j);
    }
}

size_t initLibFindLComponentsIndex(std::vector<Ncurses::LComponents *>&lcomponent, std::string name)
{
    for (size_t i = 0; !lcomponent.empty() && i != lcomponent.size(); i += 1) {
        if (lcomponent.at(i)->componentName == name)
            return i;
    }
    return 0;
}

Ncurses::LComponents *initLibFindLComponentsExist(std::vector<Ncurses::LComponents *>&lcomponent, std::string name)
{
    for (size_t i = 0; !lcomponent.empty() && i != lcomponent.size(); i += 1) {
        if (lcomponent.at(i)->componentName == name)
            return lcomponent.at(i);
    }
    return NULL;
}

int Ncurses::Ncurses::initLib(std::vector<Components *> components)
{
    std::vector<size_t> listLComponentSavedIndex;
    std::vector<LComponents *> newList;

    for (size_t i = 0; i != components.size(); i += 1) {
        switch (components.at(i)->type)
        {
        case listComponent::TEXT:
            if (initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName) != NULL) {
                listLComponentSavedIndex.push_back(initLibFindLComponentsIndex(this->lComponents, components.at(i)->componentName));
                LComponent::Text *txt = dynamic_cast<LComponent::Text *>(initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName));
                newList.push_back(txt);
            }
            else
                newList.push_back(new LComponent::Text(dynamic_cast<Component::Text *>(components.at(i))));
            break;
        case listComponent::SPRITE:
            if (initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName) != NULL) {
                listLComponentSavedIndex.push_back(initLibFindLComponentsIndex(this->lComponents, components.at(i)->componentName));
                LComponent::Sprite *sprite = dynamic_cast<LComponent::Sprite *>(initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName));
                newList.push_back(sprite);
            }
            else
                newList.push_back(new LComponent::Sprite(dynamic_cast<Component::Sprite *>(components.at(i))));
            break;
        default:
            break;
        }
    }
    deleteUnusedLComponents(this->lComponents, listLComponentSavedIndex);
    this->lComponents = newList;
    erase();
    return 0;
}

Ncurses::Ncurses::Ncurses()
{
    this->type = 2;
    initscr();
    getmaxyx(stdscr, this->height, this->widht);
    noecho();
    curs_set(FALSE);
    nodelay(stdscr,TRUE);
    erase();
}

Ncurses::Ncurses::~Ncurses()
{
    for (size_t i = 0; i != this->lComponents.size(); i++) {
        this->lComponents.at(i)->~LComponents();
    }
}

extern "C"
{
	IGLib *createLib()
	{
		return new Ncurses::Ncurses();
	}
}