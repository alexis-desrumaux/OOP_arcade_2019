/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacGomme
*/

#include "../../../include/Pacman.hpp"

IntRect_t *Game::PacGomme::getRect()
{
    std::pair<std::pair<int, int>, std::pair<int, int>> mrect = this->pacGomme->getRect();
    this->rect->x = mrect.first.first;
    this->rect->size_x = mrect.first.second;
    this->rect->y = mrect.second.first;
    this->rect->size_y = mrect.second.second;
    return this->rect;
}

Point2D *Game::PacGomme::getPos()
{
    this->pos->x = this->pacGomme->getPosition().first;
    this->pos->y = this->pacGomme->getPosition().second;
    return this->pos;
}

Component::Sprite *Game::PacGomme::getSprite()
{
    return this->pacGomme;
}

bool Game::PacGomme::hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc)
{
    std::pair<std::pair<int, int>, std::pair<int, int>> getRectPG = this->pacGomme->getRect();
    IntRect_t PGRect = {getRectPG.first.first, getRectPG.first.second, getRectPG.second.first, getRectPG.second.second};
    Point2D posPG = {(int)this->pacGomme->getPosition().first, (int)this->pacGomme->getPosition().second};

    Point2D myPosSrc = {posSrc.x, posSrc.y};
    if (dir == Game::direction::_left || dir == Game::direction::_right) {
        myPosSrc.x += far;
    }
    if (dir == Game::direction::_up || dir == Game::direction::_down) {
        myPosSrc.y += far;
    }

    if (dir == Game::direction::_right && hitRight(myPosSrc, rectSrc, posPG, PGRect) == true) {
        return true;
    }
    if (dir == Game::direction::_left && hitLeft(myPosSrc, rectSrc, posPG, PGRect) == true) {
        return true;
    }
    if (dir == Game::direction::_up && hitUp(myPosSrc, rectSrc, posPG, PGRect) == true) {
        return true;
    }
    if (dir == Game::direction::_down && hitDown(myPosSrc, rectSrc, posPG, PGRect) == true) {
        return true;
    }
    return false;
}

Game::PacGomme::PacGomme(int id, Point2D *pos, IntRect_t *rect)
{
    std::string name = "PacGomme#" + std::to_string(id);
    std::pair<float, float> myPos = {pos->x, pos->y};

    this->pos = new Point2D;
    this->rect = new IntRect_t;

    this->pacGomme = new Component::Sprite(name, "assets/images/Pacman/small/PacGomme.png", myPos, {1, 1}, std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1)));
    this->pacGomme->setRect(rect->x, rect->size_x, rect->y, rect->size_y);
}

Game::PacGomme::~PacGomme()
{

}