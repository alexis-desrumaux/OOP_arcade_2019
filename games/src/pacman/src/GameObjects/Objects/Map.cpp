/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Map
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "../../../include/Pacman.hpp"

std::vector<std::string *> *file_to_tab_str(int *size, char *str, std::vector<std::string *> *file)
{
    if (*size < 1)
        str[0] = '\0';
    if (*size > 1) {
        if (str[*size - 1] == '\n')
            str[*size - 1] = '\0';
        else
            str[*size] = '\0';
    }
    if (*size != -1) {
        file->push_back(new std::string(str));
        free(str);
    }
    return file;
}

std::vector<std::string *> *file_to_tab(std::string path)
{
    FILE *fd = fopen(path.c_str(), "r");
    int size = 0;
    size_t bufsize = 0;
    char *buff;
    std::vector<std::string *> *file = new std::vector<std::string *>;

    size = 0;
    if (fd == NULL)
        return file;
    while (1) {
        size = getline(&buff, &bufsize, fd);
        file = file_to_tab_str(&size, buff, file);
        if (file->empty())
            return file;
        if (size == -1)
            break;
        bufsize = 0;
        size = 0;
    }
    return file;
}

std::vector<Components *>Game::Map::getComponents()
{
    std::vector<Components *> components;

    for (size_t i = 0; i != this->map->size(); i += 1) {
        for (size_t j = 0; j != this->map->at(i)->size(); j += 1) {
            if (this->map->at(i)->at(j)->type == Game::objType::_wall) {
                components.push_back(dynamic_cast<Game::Wall *>(this->map->at(i)->at(j))->getSprite());
            }
            if (this->map->at(i)->at(j)->type == Game::objType::_pacGomme) {
                components.push_back(dynamic_cast<Game::PacGomme *>(this->map->at(i)->at(j))->getSprite());
            }
        }
    }
    /*for (size_t i = 0; i != this->walls.size(); i += 1) {
        components.push_back(this->walls.at(i)->getSprite());
    }*/
    return components;
}

std::vector<std::vector<Game::MapObject *> *> *Game::Map::getMap()
{
    return this->map;
}

std::vector<std::string *> *Game::Map::getFileMap()
{
    return this->fileMap;
}

Point2D *Game::Map::getDefPosPacman()
{
    return this->defaultPosPacman;
}
         
void Game::Map::createBlocks()
{
    std::vector<std::string *> *map = this->fileMap;
    std::vector<Game::MapObject *> *line;
    int x = 0;
    int y = 0;
    int s = 0;
    int nbpg = 0;

    for (size_t i = 0; i != map->size(); i += 1, y += 27) {
        x = 0;
        line = new std::vector<Game::MapObject *>;
        for (size_t j = 0; j != map->at(i)->size(); j += 1, x += 27) {
            if (map->at(i)->at(j) == '*') {
                Game::Wall *wall = new Game::Wall(s, marginMapLeft + x, marginMapTop + y);
                wall->gameObj = this->gameObj;
                wall->type = Game::objType::_wall;
                line->push_back(wall);
                s++;
            }
            if (map->at(i)->at(j) == 'P') {
                this->defaultPosPacman = new Point2D;
                this->defaultPosPacman->x = marginMapLeft + x;
                this->defaultPosPacman->y = marginMapTop + y;
                Game::Empty *empty = new Game::Empty(new Point2D{marginMapLeft + x, marginMapTop + y}, new IntRect_t{0, 27, 0, 27});
                empty->gameObj = this->gameObj;
                empty->type = Game::objType::_empty;
                line->push_back(empty);
            }
            if (map->at(i)->at(j) == ' ') {
                Game::PacGomme *pg = new Game::PacGomme(nbpg, new Point2D{marginMapLeft + x, marginMapTop + y}, new IntRect_t{0, 27, 0, 27});
                pg->gameObj = this->gameObj;
                pg->type = Game::objType::_pacGomme;
                line->push_back(pg);
                nbpg++;
            }
            if (map->at(i)->at(j) == '_') {
                Game::Empty *empty = new Game::Empty(new Point2D{marginMapLeft + x, marginMapTop + y}, new IntRect_t{0, 27, 0, 27});
                empty->gameObj = this->gameObj;
                empty->type = Game::objType::_empty;
                line->push_back(empty);
            }
        }
        this->map->push_back(line);
    }
}

void Game::Map::createMap()
{
    createBlocks();
}

Game::Map::Map(std::string file)
{
    this->fileMap = file_to_tab(file.c_str());
    this->map = new std::vector<std::vector<Game::MapObject *> *>;
    createMap();
}

Game::Map::~Map()
{
}
