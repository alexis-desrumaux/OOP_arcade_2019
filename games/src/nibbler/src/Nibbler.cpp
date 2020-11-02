/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#include "../include/Nibbler.hpp"

void Nibbler::resetStateComponents()
{
    if (this->components.empty() != true) {
        for (size_t i = 0; i != this->components.size(); i += 1) {
            this->components.at(i)->resetState();
        }
    }
}

void Nibbler::resetListUpdateComponent()
{
    this->update.clear();
}

void Nibbler::addInUpdateList(Components *toUpdate)
{
    this->update.push_back(toUpdate);
}

std::string Nibbler::Talk()
{
    return "OMG THIS IS NIBBLER BENJ BENJ CAN BE HAPPY !!";
}

cDoubleState Nibbler::manageEventGame(std::string &keyPressed)
{
    keyPressed = keyPressed;
    cDoubleState send;

    resetStateComponents();
    resetListUpdateComponent();
    send.first.first = this->components;
    send.first.second = this->needToBeReInit;
    send.second = this->update;
    return send;
}


std::vector<Components *> Nibbler::manageEventMenuGame(std::string &keyPressed)
{
    keyPressed = keyPressed;
	if (time(0) - this->start == 1) {
		Component::Text *startNibbler = dynamic_cast<Component::Text *>(findInComponents(this->components, "StartNibbler"));
        if (startNibbler->display == true)
            startNibbler->display = false;
        else
            startNibbler->display = true;
        startNibbler->setState(Component::State::UPDATE);
        addInUpdateList(startNibbler);
        this->start = this->start + 1;
	}
	return this->update;
}

std::vector<Components *> Nibbler::initGame()
{
    this->components.clear();
    this->update.clear();
    this->components.push_back(new Component::Sprite("N_BackgroundGame", "assets/images/Core/Home2.png", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    this->components.push_back(new Component::Text("N_TitleGame", "Nibbler", "assets/font/arcade.ttf", 30, Component::Color::White, std::pair<float, float>(1920 / 2 - 280, 1080/3), std::pair<int, int>(70, 20)));
	return this->components;
}

std::vector<Components *> Nibbler::initMenuGame()
{
	this->components.clear();
	this->components.push_back(new Component::Sprite("NibblerMenu", "assets/images/Core/NibblerMenu.png", std::pair<float, float>(78, 62), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("Nibbler", std::pair<int, int>(70, 15))));
    this->components.push_back(new Component::Text("StartNibbler", "START", "assets/font/arcade.ttf", 50, Component::Color::White, std::pair<float, float>(770, 550), std::pair<int, int>(70, 20)));
    this->start = time(0);
	return this->components;
}

Nibbler::Nibbler()
{
	this->needToBeReInit = false;
}

Nibbler::~Nibbler()
{

}

extern "C"
{
	IGame *createGame()
	{
		return new Nibbler();
	}
}


