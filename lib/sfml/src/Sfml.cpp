/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sfml
*/

#include "SFML.hpp"
#include "../include/Components.hpp"
#include <chrono>

void SFML::SFML::setEventKey(int nb)
{
    this->eventKey = nb;
}

int SFML::SFML::getEventKey()
{
    return this->eventKey;
}

int SFML::SFML::manageEventOnKeyboard(sf::Event event)
{
    int nb = 0;
    if (event.type == sf::Event::Closed) {
        printf("CLOSED\n");
        nb = 84;
        this->isRunning = false;
    }
    if (event.key.code == sf::Keyboard::Comma) {
        printf("PREVLIB\n");
        nb = Prev_Lib_Key;
    }
    if (event.key.code == sf::Keyboard::SemiColon) {
        printf("NEXTLIB\n");
        nb = Next_Lib_Key;
    }
    if (event.key.code == sf::Keyboard::Num1) {
        printf("PREVGAME\n");
        nb = Prev_Game_Key;
    }
    if (event.key.code == sf::Keyboard::Num2) {
        printf("NEXTGAME\n");
        nb = Next_Game_Key;
    }
    return nb;
}

int manageEvent(sf::Event event)
{
    int nb = 0;
    if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Q) {
        printf("CLOSED\n");
        nb = 84;
    }
    if (event.key.code == sf::Keyboard::Comma) {
        printf("PREVLIB\n");
        nb = Prev_Lib_Key;
    }
    if (event.key.code == sf::Keyboard::SemiColon) {
        printf("NEXTLIB\n");
        nb = Next_Lib_Key;
    }
    if (event.key.code == sf::Keyboard::Num1) {
        printf("PREVGAME\n");
        nb = Prev_Game_Key;
    }
    if (event.key.code == sf::Keyboard::Num2) {
        printf("NEXTGAME\n");
        nb = Next_Game_Key;
    }
    return nb;
}

sf::Color convertColorFromComponent(Component::Color::Color color)
{
    switch (color) {
        case Component::Color::White:
            return sf::Color::White;
        case Component::Color::Black:
            return sf::Color::Black;
        case Component::Color::Red:
            return sf::Color::Red;
        case Component::Color::Green:
            return sf::Color::Green;
        case Component::Color::Blue:
            return sf::Color::Blue;
    }
    return sf::Color::Black;
}

std::string SFKeyToString(unsigned int keycode)
{
    std::string keyStr;

    switch (keycode) {
        case sf::Keyboard::A: keyStr = "A"; break;
        case sf::Keyboard::B: keyStr = "B"; break;
        case sf::Keyboard::C: keyStr = "C"; break;
        case sf::Keyboard::D: keyStr = "D"; break;
        case sf::Keyboard::E: keyStr = "E"; break;
        case sf::Keyboard::F: keyStr = "F"; break;
        case sf::Keyboard::G: keyStr = "G"; break;
        case sf::Keyboard::H: keyStr = "H"; break;
        case sf::Keyboard::I: keyStr = "I"; break;
        case sf::Keyboard::J: keyStr = "J"; break;
        case sf::Keyboard::K: keyStr = "K"; break;
        case sf::Keyboard::L: keyStr = "L"; break;
        case sf::Keyboard::M: keyStr = "M"; break;
        case sf::Keyboard::N: keyStr = "N"; break;
        case sf::Keyboard::O: keyStr = "O"; break;
        case sf::Keyboard::P: keyStr = "P"; break;
        case sf::Keyboard::Q: keyStr = "Q"; break;
        case sf::Keyboard::R: keyStr = "R"; break;
        case sf::Keyboard::S: keyStr = "S"; break;
        case sf::Keyboard::T: keyStr = "T"; break;
        case sf::Keyboard::U: keyStr = "U"; break;
        case sf::Keyboard::V: keyStr = "V"; break;
        case sf::Keyboard::W: keyStr = "W"; break;
        case sf::Keyboard::X: keyStr = "X"; break;
        case sf::Keyboard::Y: keyStr = "Y"; break;
        case sf::Keyboard::Z: keyStr = "Z"; break;
        case sf::Keyboard::Escape: keyStr = "Escape"; break;
        case sf::Keyboard::LControl: keyStr = "LControl"; break;
        case sf::Keyboard::LShift: keyStr = "LShift"; break;
        case sf::Keyboard::LAlt: keyStr = "LAlt"; break;
        case sf::Keyboard::LSystem: keyStr = "LSystem"; break;
        case sf::Keyboard::RControl: keyStr = "RControl"; break;
        case sf::Keyboard::RShift: keyStr = "RShift"; break;
        case sf::Keyboard::RAlt: keyStr = "RAlt"; break;
        case sf::Keyboard::RSystem: keyStr = "RSystem"; break;
        case sf::Keyboard::Menu: keyStr = "Menu"; break;
        case sf::Keyboard::LBracket: keyStr = "LBracket"; break;
        case sf::Keyboard::RBracket: keyStr = "RBracket"; break;
        case sf::Keyboard::SemiColon: keyStr = ";"; break;
        case sf::Keyboard::Comma: keyStr = ","; break;
        case sf::Keyboard::Period: keyStr = "."; break;
        case sf::Keyboard::Quote: keyStr = "\'"; break;
        case sf::Keyboard::Slash: keyStr = "/"; break;
        case sf::Keyboard::BackSlash: keyStr = "\\"; break;
        case sf::Keyboard::Tilde: keyStr = "~"; break;
        case sf::Keyboard::Equal: keyStr = "="; break;
        case sf::Keyboard::Dash: keyStr = "-"; break;
        case sf::Keyboard::Space: keyStr = "Space"; break;
        case sf::Keyboard::Return: keyStr = "Return"; break;
        case sf::Keyboard::BackSpace: keyStr = "Back"; break;
        case sf::Keyboard::Tab: keyStr = "Tab"; break;
        case sf::Keyboard::PageUp: keyStr = "Page Up"; break;
        case sf::Keyboard::PageDown: keyStr = "Page Down"; break;
        case sf::Keyboard::End: keyStr = "End"; break;
        case sf::Keyboard::Home: keyStr = "Home"; break;
        case sf::Keyboard::Insert: keyStr = "Insert"; break;
        case sf::Keyboard::Delete: keyStr = "Delete"; break;
        case sf::Keyboard::Add: keyStr = "+"; break;
        case sf::Keyboard::Subtract: keyStr = "-"; break;
        case sf::Keyboard::Multiply: keyStr = "*"; break;
        case sf::Keyboard::Divide: keyStr = "/"; break;
        case sf::Keyboard::Left: keyStr = "Left"; break;
        case sf::Keyboard::Right: keyStr = "Right"; break;
        case sf::Keyboard::Up: keyStr = "Up"; break;
        case sf::Keyboard::Down: keyStr = "Down"; break;
        case sf::Keyboard::Numpad0: keyStr = "NP 0"; break;
        case sf::Keyboard::Numpad1: keyStr = "NP 1"; break;
        case sf::Keyboard::Numpad2: keyStr = "NP 2"; break;
        case sf::Keyboard::Numpad3: keyStr = "NP 3"; break;
        case sf::Keyboard::Numpad4: keyStr = "NP 4"; break;
        case sf::Keyboard::Numpad5: keyStr = "NP 5"; break;
        case sf::Keyboard::Numpad6: keyStr = "NP 6"; break;
        case sf::Keyboard::Numpad7: keyStr = "NP 7"; break;
        case sf::Keyboard::Numpad8: keyStr = "NP 8"; break;
        case sf::Keyboard::Numpad9: keyStr = "NP 9"; break;
        case sf::Keyboard::F1: keyStr = "F1"; break;
        case sf::Keyboard::F2: keyStr = "F2"; break;
        case sf::Keyboard::F3: keyStr = "F3"; break;
        case sf::Keyboard::F4: keyStr = "F4"; break;
        case sf::Keyboard::F5: keyStr = "F5"; break;
        case sf::Keyboard::F6: keyStr = "F6"; break;
        case sf::Keyboard::F7: keyStr = "F7"; break;
        default:
        keyStr = "";
    }
    return keyStr;
}

int SFML::SFML::draw(void)
{
    for (size_t i = 0; i != this->lComponents.size(); i += 1) {
        this->lComponents.at(i)->draw(this->window);
    }
    return 0;
}

int SFML::SFML::manageUpdate(std::vector<Components *> update)
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
            case listComponent::AUDIO:
            {
                Component::Audio *audio = dynamic_cast<Component::Audio *>(update.at(i));
                if (audio->getState().first == Component::State::UPDATE) {
                    LComponent::Audio *c = dynamic_cast<LComponent::Audio *>(findInLComponents(this->lComponents, audio->componentName));
                    c->update(audio);
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

std::string SFML::SFML::display(std::vector<Components *> update)
{
    sf::Event event;
    std::string keyPressed = "";

    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->isRunning = false;
            this->window->close();
        }
        if (event.type == event.KeyPressed && event.type != event.MouseButtonPressed) {
            keyPressed = SFKeyToString(event.key.code);
            if (keyPressed == "F4" || keyPressed == "F5") {
                this->window->close();
            }
        }
    }
    this->window->clear();
    manageUpdate(update);
    draw();
    this->window->display();
    return keyPressed;
}

void deleteUnusedLComponents(std::vector<SFML::LComponents *>&lComponents, std::vector<size_t> listLComponentSavedIndex)
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

size_t initLibFindLComponentsIndex(std::vector<SFML::LComponents *>&lcomponent, std::string name)
{
    for (size_t i = 0; !lcomponent.empty() && i != lcomponent.size(); i += 1) {
        if (lcomponent.at(i)->componentName == name)
            return i;
    }
    return 0;
}

SFML::LComponents *initLibFindLComponentsExist(std::vector<SFML::LComponents *>&lcomponent, std::string name)
{
    for (size_t i = 0; !lcomponent.empty() && i != lcomponent.size(); i += 1) {
        if (lcomponent.at(i)->componentName == name)
            return lcomponent.at(i);
    }
    return NULL;
}

int SFML::SFML::initLib(std::vector<Components *> components)
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
            else {
                newList.push_back(new LComponent::Text(dynamic_cast<Component::Text *>(components.at(i))));
            }
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
        case listComponent::AUDIO:
            if (initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName) != NULL) {
                listLComponentSavedIndex.push_back(initLibFindLComponentsIndex(this->lComponents, components.at(i)->componentName));
                LComponent::Audio *audio = dynamic_cast<LComponent::Audio *>(initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName));
                newList.push_back(audio);
            }
            else
                newList.push_back(new LComponent::Audio(dynamic_cast<Component::Audio *>(components.at(i))));
            break;
        default:
            break;
        }
    }
    deleteUnusedLComponents(this->lComponents, listLComponentSavedIndex);
    this->lComponents = newList;
    return 0;
}

SFML::SFML::SFML()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
    this->name = "";
    this->type = 1;
    this->window->setFramerateLimit(60);
}

SFML::SFML::~SFML()
{
    for (size_t i = 0; i != this->lComponents.size(); i++) {
        this->lComponents.at(i)->~LComponents();
    }
    delete this->window;
}

extern "C"
{
	IGLib *createLib()
	{
		return new SFML::SFML();
	}
}