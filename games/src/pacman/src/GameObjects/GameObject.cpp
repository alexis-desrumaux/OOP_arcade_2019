/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#include "../../include/Pacman.hpp"

bool hitDown(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo)
{
    Point2D a;
    Point2D b;
    Point2D c;
    Point2D d;

    a.x = posObjOne.x;
    a.y = posObjOne.y + rectObjOne.size_y;
    b.x = posObjOne.x + rectObjOne.size_x;
    b.y = posObjOne.y + rectObjOne.size_y;
    c.x = posObjTwo.x;
    c.y = posObjTwo.y;
    d.x = posObjTwo.x + rectObjTwo.size_x;
    d.y = posObjTwo.y;

    if (a.y >= c.y && a.y < c.y + rectObjTwo.size_y && b.y >= d.y && b.y < d.y + rectObjTwo.size_y) {
        if (a.y == c.y && b.y == d.y) {
            //std::cout << "Same X" << std::endl;
        }
        if (a.x > c.x && a.x < d.x) {
            return true;
        }
        if (b.x > c.x && b.x < d.x) {
            return true;
        }
        if (a.x > c.x && a.x < d.x && b.x > c.x && b.x < d.x) {
            return true;
        }
        if (c.x > a.x && c.x < b.x && d.x > a.x && d.x < b.x) {
            return true;
        }
        if (a.x == c.x && b.x == d.x) {
            return true;
        }
    }
    return false;
}

bool hitUp(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo)
{
    Point2D a;
    Point2D b;
    Point2D c;
    Point2D d;

    a.x = posObjOne.x;
    a.y = posObjOne.y;
    b.x = posObjOne.x + rectObjOne.size_x;
    b.y = posObjOne.y;
    c.x = posObjTwo.x;
    c.y = posObjTwo.y + rectObjTwo.size_y;
    d.x = posObjTwo.x + rectObjTwo.size_x;
    d.y = posObjTwo.y + rectObjTwo.size_y;

    if (a.y <= c.y && a.y > c.y - rectObjTwo.size_y && b.y <= d.y && b.y > d.y - rectObjTwo.size_y) {
        if (a.y == c.y && b.y == d.y) {
            //std::cout << "Same X" << std::endl;
        }
        if (a.x > c.x && a.x < d.x) {
            return true;
        }
        if (b.x > c.x && b.x < d.x) {
            return true;
        }
        if (a.x > c.x && a.x < d.x && b.x > c.x && b.x < d.x) {
            return true;
        }
        if (c.x > a.x && c.x < b.x && d.x > a.x && d.x < b.x) {
            return true;
        }
        if (a.x == c.x && b.x == d.x) {
            return true;
        }
    }
    return false;
}

bool hitLeft(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo)
{
    Point2D a;
    Point2D b;
    Point2D c;
    Point2D d;

    a.x = posObjOne.x;
    a.y = posObjOne.y;
    b.x = posObjOne.x;
    b.y = posObjOne.y + rectObjOne.size_y;
    c.x = posObjTwo.x + rectObjTwo.size_x;
    c.y = posObjTwo.y;
    d.x = posObjTwo.x + rectObjTwo.size_x;
    d.y = posObjTwo.y + rectObjTwo.size_y;

    if (a.x <= c.x && a.x > c.x - rectObjTwo.size_x && b.x <= d.x && b.x > d.x - rectObjTwo.size_x) {
        if (a.x == c.x && b.x == d.x) {
            //std::cout << "Same X" << std::endl;
        }
        if (a.y > c.y && a.y < d.y) {
            return true;
        }
        if (b.y > c.y && b.y < d.y) {
            return true;
        }
        if (a.y > c.y && a.y < d.y && b.y > c.y && b.y < d.y) {
            return true;
        }
        if (c.y > a.y && c.y < b.y && d.y > a.y && d.y < b.y) {
            return true;
        }
        if (a.y == c.y && b.y == d.y) {
            return true;
        }
    }
    return false;
 }

bool hitRight(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo)
{
    Point2D a;
    Point2D b;
    Point2D c;
    Point2D d;

    a.x = posObjOne.x + rectObjOne.size_x;
    a.y = posObjOne.y;
    b.x = posObjOne.x + rectObjOne.size_x;
    b.y = posObjOne.y + rectObjOne.size_y;
    c.x = posObjTwo.x;
    c.y = posObjTwo.y;
    d.x = posObjTwo.x;
    d.y = posObjTwo.y + rectObjTwo.size_y;

    if (a.x >= c.x && a.x < c.x + rectObjTwo.size_x && b.x >= d.x && b.x < d.x + rectObjTwo.size_x) {
        if (a.x == c.x && b.x == d.x) {
            //std::cout << "Same X" << std::endl;
        }
        if (a.y > c.y && a.y < d.y) {
            return true;
        }
        if (b.y > c.y && b.y < d.y) {
            return true;
        }
        if (a.y > c.y && a.y < d.y && b.y > c.y && b.y < d.y) {
            return true;
        }
        if (c.y > a.y && c.y < b.y && d.y > a.y && d.y < b.y) {
            return true;
        }
        if (a.y == c.y && b.y == d.y) {
            return true;
        }
    }
    return false;
}

int checkIsAPath(Game::objType type)
{
    switch (type)
    {
    case Game::objType::_empty:
        return 0;
    case Game::objType::_pacGomme:
        return 1;
    default:
        return -1;
    }
    return -1;
}

IntRect_t convertGetRectToIntRect(std::pair<std::pair<int, int>, std::pair<int, int>> rectSrc)
{
    return {rectSrc.first.first, rectSrc.first.second, rectSrc.second.first, rectSrc.second.second};
}

double getTime()
{
  struct timeval detail_time;
  gettimeofday(&detail_time,NULL);
  return ((detail_time.tv_sec) * 1000 + (detail_time.tv_usec) / 1000); /* microseconds */
}

bool isADirection(std::string &keyPressed)
{
    if (keyPressed == "Left")
        return true;
    if (keyPressed == "Right")
        return true;
    if (keyPressed == "Up")
        return true;
    if (keyPressed == "Down")
        return true;
    return false;
}

Game::GameObjects::GameObjects()
{
    this->pacman = new Game::Pacman();
    this->Map = new Game::Map("assets/Map/Pacman/map.txt");
    this->pacman->setDefaultPosition(this->Map->getDefPosPacman());
    this->audioBackground = new Component::Audio("audioBackground", "assets/Sound/Pacman/audioBackground.wav", Component::AudioState::PLAY, true);
}

Game::GameObjects::~GameObjects()
{

}
