/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Wall
*/

#include "../../../include/Pacman.hpp"

bool Game::Wall::hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc)
{
    std::pair<std::pair<int, int>, std::pair<int, int>> getRectWall = this->wall->getRect();
    IntRect_t wallRect = {getRectWall.first.first, getRectWall.first.second, getRectWall.second.first, getRectWall.second.second};
    Point2D posWall = {(int)this->wall->getPosition().first, (int)this->wall->getPosition().second};

    Point2D myPosSrc = {posSrc.x, posSrc.y};
    if (dir == Game::direction::_left || dir == Game::direction::_right) {
        myPosSrc.x += far;
    }
    if (dir == Game::direction::_up || dir == Game::direction::_down) {
        myPosSrc.y += far;
    }

    if (dir == Game::direction::_right && hitRight(myPosSrc, rectSrc, posWall, wallRect) == true) {
        return true;
    }
    if (dir == Game::direction::_left && hitLeft(myPosSrc, rectSrc, posWall, wallRect) == true) {
        return true;
    }
    if (dir == Game::direction::_up && hitUp(myPosSrc, rectSrc, posWall, wallRect) == true) {
        return true;
    }
    if (dir == Game::direction::_down && hitDown(myPosSrc, rectSrc, posWall, wallRect) == true) {
        return true;
    }
    return false;
}

Component::Sprite *Game::Wall::getSprite()
{
    return this->wall;
}

std::pair<std::vector<Components *>, bool> Game::Wall::compute(std::string &keyPressed)
{
    keyPressed = keyPressed;
    this->wall->resetState();

    std::pair<std::vector<Components *>, bool> send;

    for (size_t i = 0; i != this->myUpdate.size(); i += 1)
        send.first.push_back(this->myUpdate.at(i));
    send.second = this->libNeedToBeReInit;
    return send;
}

Game::Wall::Wall(int id, float x, float y)
{
    std::string name = "Wall#" + std::to_string(id);
    this->wall = new Component::Sprite(name, "assets/images/Pacman/small/wall.png", std::pair<float, float>(x, y), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("X", std::pair<int, int>(50, 50)));
    this->wall->setRect(0, 27, 0, 27);
    this->isAlive = true;
    this->libNeedToBeReInit = false;
}

Game::Wall::~Wall()
{
}
