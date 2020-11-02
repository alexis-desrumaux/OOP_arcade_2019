/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Empty
*/

#include "../../../include/Pacman.hpp"

IntRect_t *Game::Empty::getRect()
{
    return this->rect;
}

Point2D *Game::Empty::getPos()
{
    return this->pos;
}

bool Game::Empty::hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc)
{
    IntRect_t *emptyRect = this->rect;
    Point2D *posEmpty = this->pos;
    Point2D myPosSrc = {posSrc.x, posSrc.y};

    if (dir == Game::direction::_left || dir == Game::direction::_right) {
        myPosSrc.x += far;
    }
    if (dir == Game::direction::_up || dir == Game::direction::_down) {
        myPosSrc.y += far;
    }

    if (dir == Game::direction::_right && hitRight(myPosSrc, rectSrc, *posEmpty, *emptyRect) == true) {
        return true;
    }
    if (dir == Game::direction::_left && hitLeft(myPosSrc, rectSrc, *posEmpty, *emptyRect) == true) {
        return true;
    }
    if (dir == Game::direction::_up && hitUp(myPosSrc, rectSrc, *posEmpty, *emptyRect) == true) {
        return true;
    }
    if (dir == Game::direction::_down && hitDown(myPosSrc, rectSrc, *posEmpty, *emptyRect) == true) {
        return true;
    }
    return false;
}

Game::Empty::Empty(Point2D *pos, IntRect_t *rect)
{
    this->pos = pos;
    this->rect = rect;
}

Game::Empty::~Empty()
{

}
