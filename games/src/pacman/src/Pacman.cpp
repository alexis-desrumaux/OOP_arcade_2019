/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include "../include/Pacman.hpp"

std::string Pacman::Talk()
{
    return "OMG THIS IS PACMAN !!";
}

void Pacman::resetStateComponents()
{
    
}

void Pacman::resetListUpdateComponent()
{
    this->update.clear();
}

void Pacman::addInUpdateList(Components *toUpdate)
{
    this->update.push_back(toUpdate);
}

void Pacman::resetPacmanEachLoop()
{
    //resetStateComponents();
    //resetListUpdateComponent();
    this->components.clear();
    this->update.clear();
    this->needToBeReInit = false;
}

void Pacman::getComponentsFromGameObj()
{
    std::vector<Components *> c_map = this->gameObj->Map->getComponents();
    std::vector<Components *> c_pacman = this->gameObj->pacman->getComponents();

    for (size_t i = 0; i != c_map.size(); i += 1)
        this->components.push_back(c_map.at(i));
    for (size_t i = 0; i != c_pacman.size(); i += 1)
        this->components.push_back(c_pacman.at(i));
    this->components.push_back(this->gameObj->audioBackground);
}

void Pacman::manageEnd(std::string &keyPressed)
{
    int check = 0;

    for (size_t i = 0; i != this->gameObj->Map->getMap()->size(); i += 1) {
        for (size_t j = 0; j != this->gameObj->Map->getMap()->at(i)->size(); j += 1) {
            if (this->gameObj->Map->getMap()->at(i)->at(j)->type == Game::objType::_pacGomme) {
                check++;
            }
        }
    }
    if (check == 0) {
        keyPressed = "F6";
        this->speedM += 1;
    }
    return;
}

cDoubleState Pacman::manageEventGame(std::string &keyPressed)
{
	resetPacmanEachLoop();

    std::pair<std::vector<Components *>, bool> recept;

    recept = this->gameObj->pacman->compute(keyPressed);

    manageEnd(keyPressed);

    if (recept.second == true)
        this->needToBeReInit = true;
    if (!recept.first.empty()) {
        for (size_t i = 0; i != recept.first.size(); i += 1) {
            this->update.push_back(recept.first.at(i));
        }
    }
    getComponentsFromGameObj();
    std::pair<std::pair<std::vector<Components *>, bool>, std::vector<Components *>> send;
    send.first.first = this->components;
    send.first.second = this->needToBeReInit;
    send.second = this->update;
    return send;
	//suite;
}

std::vector<Components *> Pacman::manageEventMenuGame(std::string &keyPressed)
{
	keyPressed = keyPressed;
	resetListUpdateComponent();
	if (time(0) - this->start >= 1) {
		Component::Text *startPacman = dynamic_cast<Component::Text *>(findInComponents(this->components, "StartPacman"));
        if (startPacman->display == true)
            startPacman->display = false;
        else
            startPacman->display = true;
        startPacman->setState(Component::State::UPDATE);
        addInUpdateList(startPacman);
        this->start = time(0);
	}
	//std::cout << this->update.size() << std::endl;
	return this->update;
}

std::vector<Components *>Pacman::initGame()
{
    this->gameObj = new Game::GameObjects();
    this->gameObj->pacman->assign(this->gameObj);
    this->gameObj->pacman->speedM = this->speedM;
    this->gameObj->Map->gameObj = this->gameObj;
	this->needToBeReInit = false;

    this->components.clear();
    this->update.clear();
    std::vector<Components *> c_map = this->gameObj->Map->getComponents();
    std::vector<Components *> c_pacman = this->gameObj->pacman->getComponents();

    for (size_t i = 0; i != c_map.size(); i += 1) {
        this->components.push_back(c_map.at(i));
    }
    for (size_t i = 0; i != c_pacman.size(); i += 1) {
        this->components.push_back(c_pacman.at(i));
    }
    this->components.push_back(this->gameObj->audioBackground);
	return this->components;
}

std::vector<Components *>Pacman::initMenuGame()
{
	this->components.clear();
	this->components.push_back(new Component::Sprite("PacmanMenu", "assets/images/Core/PacmanMenu.png", std::pair<float, float>(78, 62), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("Pacman", std::pair<int, int>(70, 15))));
    this->components.push_back(new Component::Text("StartPacman", "START", "assets/font/arcade.ttf", 50, Component::Color::White, std::pair<float, float>(770, 550), std::pair<int, int>(70, 20)));
    this->start = time(0);
	return this->components;
}

Pacman::Pacman()
{
    this->speedM = 0;
}

Pacman::~Pacman()
{
}

extern "C"
{
	IGame *createGame()
	{
		return new Pacman();
	}
}
