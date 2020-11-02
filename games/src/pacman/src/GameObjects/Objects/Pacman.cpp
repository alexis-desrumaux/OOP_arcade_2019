/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include "../../../include/Pacman.hpp"



bool Game::Pacman::switchDir(Game::direction origin, Game::direction dir)
{
    Game::Wall *currentWall = NULL;
    Game::Empty *currentEmpty = NULL;
    Game::PacGomme *currentPG = NULL;
    std::vector<std::pair<Game::MapObject *, Point2D>> p;

    for (size_t i = 0; i != this->gameObj->Map->getMap()->size(); i += 1) {
        for (size_t j = 0; j != this->gameObj->Map->getMap()->at(i)->size(); j += 1) {
            if (this->gameObj->Map->getMap()->at(i)->at(j)->type == Game::objType::_wall) {
                currentWall = dynamic_cast<Game::Wall *>(this->gameObj->Map->getMap()->at(i)->at(j));
                Point2D current_posPac = {(int)this->getSprite()->getPosition().first, (int)this->getSprite()->getPosition().second};
                if (currentWall->hit(dir, 0, current_posPac, convertGetRectToIntRect(this->getSprite()->getRect())) == true) {
                    p.push_back({currentWall, {(int)j, (int)i}});
                }
            }
            else if (this->gameObj->Map->getMap()->at(i)->at(j)->type == Game::objType::_empty) {
                currentEmpty = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(i)->at(j));
                Point2D current_posPac = {(int)this->getSprite()->getPosition().first, (int)this->getSprite()->getPosition().second};
                if (currentEmpty->hit(dir, 0, current_posPac, convertGetRectToIntRect(this->getSprite()->getRect())) == true) {
                    p.push_back({currentEmpty, {(int)j, (int)i}});
                }
            }
            else if (this->gameObj->Map->getMap()->at(i)->at(j)->type == Game::objType::_pacGomme) {
                currentPG = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(i)->at(j));
                Point2D current_posPac = {(int)this->getSprite()->getPosition().first, (int)this->getSprite()->getPosition().second};
                if (currentPG->hit(dir, 0, current_posPac, convertGetRectToIntRect(this->getSprite()->getRect())) == true) {
                    p.push_back({currentPG, {(int)j, (int)i}});
                }
            }
        }
    }
    for (size_t k = 0; k != p.size(); k += 1) {
        /*if (p.at(k).first->type == Game::objType::_empty)
            //std::cout << "EMPTY" << std::endl;
        else if (p.at(k).first->type == Game::objType::_wall)
            std::cout << "WALL" << std::endl;
        else if (p.at(k).first->type == Game::objType::_pacGomme)
            std::cout << "PACGOMME" << std::endl;*/
    }
    bool check = this->switcher->putSwitcher(origin, dir, p);
    //std::cout << "----------------END SWITCHDIR--------" << std::endl;
    return check;
}

std::pair<int, Game::objType> Game::Pacman::speedModifier(Game::direction dir, int far)
{
    int speed = 0;
    Game::Wall *current = NULL;
    Game::PacGomme *currentpg = NULL;
    Game::Empty *currentempty = NULL;
    Game::Empty *emptynext = NULL;
    std::vector<size_t> emptynextTab = {0, 0, this->gameObj->Map->getMap()->size()};
    bool check = false;

    for (size_t i = 0; i != this->gameObj->Map->getMap()->size(); i += 1) {
        for (size_t j = 0; j != this->gameObj->Map->getMap()->at(i)->size(); j += 1) {
            if (this->switcher->actived == true) {
                while (speed != far && this->switcher->fitIn(dir, speed, {(int)this->pacman->getPosition().first, (int)this->pacman->getPosition().second}, convertGetRectToIntRect(this->pacman->getRect())) == false) {
                    if (far < 0)
                        speed--;
                    if (far > 0)
                        speed++;
                }
                if (far > 0 && speed < far)
                    return {speed, Game::objType::_switcher};
                else if (far < 0 && speed > far)
                    return {speed, Game::objType::_switcher};
                else if (speed == 0)
                    return {speed, Game::objType::_switcher};
            }
            if (this->gameObj->Map->getMap()->at(i)->at(j)->type == Game::objType::_wall) {
                current = dynamic_cast<Game::Wall *>(this->gameObj->Map->getMap()->at(i)->at(j));
                speed = 0;
                while (speed != far && current->hit(dir, speed, {(int)this->pacman->getPosition().first, (int)this->pacman->getPosition().second} , convertGetRectToIntRect(this->pacman->getRect())) == false) {
                    if (far < 0)
                        speed--;
                    if (far > 0)
                        speed++;
                }
                if (far > 0 && speed < far)
                    return {speed, Game::objType::_wall};
                else if (far < 0 && speed > far)
                    return {speed, Game::objType::_wall};
                else if (speed == 0)
                    return {speed, Game::objType::_wall};
            }
            if (this->gameObj->Map->getMap()->at(i)->at(j)->type == Game::objType::_pacGomme) {
                currentpg = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(i)->at(j));
                if (currentpg->hit(dir, 0, {(int)this->pacman->getPosition().first, (int)this->pacman->getPosition().second} , convertGetRectToIntRect(this->pacman->getRect())) == true) {
                    Game::Empty *empty = new Game::Empty(new Point2D{currentpg->getPos()->x, currentpg->getPos()->y}, new IntRect_t{0, 27, 0, 27});
                    empty->gameObj = this->gameObj;
                    empty->type = Game::objType::_empty;
                    delete this->gameObj->Map->getMap()->at(i)->at(j);
                    this->gameObj->Map->getMap()->at(i)->at(j) = empty;
                    this->libNeedToBeReInit = true;
                    this->wakaPlayAudio = true;
                    return {far, Game::objType::_none};
                }
            }
            if (this->gameObj->Map->getMap()->at(i)->at(j)->type == Game::objType::_empty) {
                currentempty = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(i)->at(j));
                Point2D *currentemptyPos = currentempty->getPos();
                IntRect_t *currentemptyRect = currentempty->getRect();
                if (currentempty->hit(dir, 0, {(int)this->pacman->getPosition().first, (int)this->pacman->getPosition().second} , convertGetRectToIntRect(this->pacman->getRect())) == true) {
                    emptynextTab.at(0) = 0;
                    emptynextTab.at(1) = 0;
                    emptynextTab.at(2) = this->gameObj->Map->getMap()->size();
                    check = false;
                    if (i != 0)
                        emptynextTab.at(0) = i - 1;
                    if (i + 1 != this->gameObj->Map->getMap()->size())
                        emptynextTab.at(2) = i + 2;
                    for (; check == false && emptynextTab.at(0) != emptynextTab.at(2); emptynextTab.at(0) += 1) {
                        for (emptynextTab.at(1) = 0; check == false && emptynextTab.at(1) != this->gameObj->Map->getMap()->at(emptynextTab.at(0))->size(); emptynextTab.at(1) += 1) {
                            if (this->gameObj->Map->getMap()->at(emptynextTab.at(0))->at(emptynextTab.at(1))->type == Game::objType::_empty) {
                                emptynext = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(emptynextTab.at(0))->at(emptynextTab.at(1)));
                                if (emptynext->hit(dir, far, *currentemptyPos, *currentemptyRect) == true) {
                                    this->wakaPlayAudio = false;
                                    check = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return {speed, Game::objType::_none};
}

bool Game::Pacman::manageSpecialActionOnPacman(int &speed, std::pair<int, Game::objType> sp, Game::direction dir)
{
    if (sp.first == 0 && sp.second == Game::objType::_none)
        this->direction = Game::direction::_none;
    else if (sp.first == 0 && sp.second == Game::objType::_wall && this->direction == dir) {
        speed = 0;
        this->direction = Game::direction::_none;
    }
    else if (sp.first == 0 && sp.second == Game::objType::_wall && this->direction != dir)
        return true;
    else if (sp.first == 0 && sp.second == Game::objType::_switcher) {
        this->direction = this->switcher->getSwitchDir();
        this->switcher->actived = false;
    }
    else {
        this->direction = dir;
        speed = sp.first;
    }
    return false;
} 

void Game::Pacman::moveDown()
{
    std::pair<float, float> pos = this->pacman->getPosition();
    std::pair<int, Game::objType> sp = speedModifier(Game::direction::_down, 2 + this->speedM);
    int speed = 0;

    if (switchDir(this->direction, Game::direction::_down) == true)
        return;
    if (manageSpecialActionOnPacman(speed, sp, Game::direction::_down) == true)
        return;
    pos.second += speed;
    this->pacman->setPosition(pos);
    this->upRectSp.second = -1;
    this->rightRectSp.second = -1;
    this->leftRectSp.second = -1;
    if (this->downRectSp.second == -1)
        this->downRectSp.second = 0;
    if (getTime() - this->wakaAnim >= 200) {
        if (this->downRectSp.second == int(this->downRectSp.first.size()) - 1)
            this->downRectSp.second = 0;
        else
            this->downRectSp.second++;
        this->wakaAnim = getTime();
    }
    IntRect_t *actual = which_moveRect();
    this->pacman->setRect(actual->x, actual->size_x, actual->y, actual->size_y);
    this->pacman->setState(Component::State::UPDATE);
}

void Game::Pacman::moveUp()
{
    std::pair<float, float> pos = this->pacman->getPosition();
    std::pair<int, Game::objType> sp = speedModifier(Game::direction::_up, -2 - this->speedM);
    int speed = 0;

    if (switchDir(this->direction, Game::direction::_up) == true)
        return;
    if (manageSpecialActionOnPacman(speed, sp, Game::direction::_up) == true)
        return;
    pos.second += speed;
    this->pacman->setPosition(pos);
    this->downRectSp.second = -1;
    this->rightRectSp.second = -1;
    this->leftRectSp.second = -1;
    if (this->upRectSp.second == -1)
        this->upRectSp.second = 0;
    if (getTime() - this->wakaAnim >= 200) {
        if (this->upRectSp.second == int(this->upRectSp.first.size()) - 1)
            this->upRectSp.second = 0;
        else
            this->upRectSp.second++;
        this->wakaAnim = getTime();
    }
    IntRect_t *actual = which_moveRect();
    this->pacman->setRect(actual->x, actual->size_x, actual->y, actual->size_y);
    this->pacman->setState(Component::State::UPDATE);
}

void Game::Pacman::moveRight()
{
    std::pair<float, float> pos = this->pacman->getPosition();
    std::pair<int, Game::objType> sp = speedModifier(Game::direction::_right, 2 + this->speedM);
    int speed = 0;

    if (switchDir(this->direction, Game::direction::_right) == 1) {
        return;
    }
    if (manageSpecialActionOnPacman(speed, sp, Game::direction::_right) == true)
        return;
    pos.first += speed;
    this->pacman->setPosition(pos);
    this->upRectSp.second = -1;
    this->downRectSp.second = -1;
    this->leftRectSp.second = -1;
    if (this->rightRectSp.second == -1)
        this->rightRectSp.second = 0;
    if (getTime() - this->wakaAnim >= 200) {
        if (this->rightRectSp.second == int(this->rightRectSp.first.size()) - 1)
            this->rightRectSp.second = 0;
        else
            this->rightRectSp.second++;
        this->wakaAnim = getTime();
    }
    IntRect_t *actual = which_moveRect();
    this->pacman->setRect(actual->x, actual->size_x, actual->y, actual->size_y);
    this->pacman->setState(Component::State::UPDATE);
}

void Game::Pacman::moveLeft()
{
    std::pair<float, float> pos = this->pacman->getPosition();
    std::pair<int, Game::objType> sp = speedModifier(Game::direction::_left, -2 - this->speedM);
    int speed = 0;

    if (switchDir(this->direction, Game::direction::_left) == 1)
        return;
    if (manageSpecialActionOnPacman(speed, sp, Game::direction::_left) == true)
        return;
    pos.first += speed;
    this->pacman->setPosition(pos);
    this->upRectSp.second = -1;
    this->downRectSp.second = -1;
    this->rightRectSp.second = -1;
    if (this->leftRectSp.second == -1)
        this->leftRectSp.second = 0;
    if (getTime() - this->wakaAnim >= 200) {
        if (this->leftRectSp.second == int(this->leftRectSp.first.size()) - 1)
            this->leftRectSp.second = 0;
        else
            this->leftRectSp.second++;
        this->wakaAnim = getTime();
    }
    IntRect_t *actual = which_moveRect();
    this->pacman->setRect(actual->x, actual->size_x, actual->y, actual->size_y);
    this->pacman->setState(Component::State::UPDATE);
}

bool Game::Pacman::move(std::string &keyPressed)
{

    if (keyPressed == "Left" || (this->direction == Game::direction::_left && !isADirection(keyPressed))) {
        if (getTime() - this->moveAnim >= 10) {
            this->moveLeft();
            this->moveAnim = getTime();
        }
    }
    else if (keyPressed == "Right" || (this->direction == Game::direction::_right && !isADirection(keyPressed))) {
        if (getTime() - this->moveAnim >= 10) {
            this->moveRight();
            this->moveAnim = getTime();
        }
    }
    else if (keyPressed == "Up" || (this->direction == Game::direction::_up && !isADirection(keyPressed))) {
        if (getTime() - this->moveAnim >= 10) {
            this->moveUp();
            this->moveAnim = getTime();
        }
    }
    else if (keyPressed == "Down" || (this->direction == Game::direction::_down && !isADirection(keyPressed))) {
        if (getTime() - this->moveAnim >= 10) {
            this->moveDown();
            this->moveAnim = getTime();
        }
    }
    if (this->direction == Game::direction::_none)
        return false;
    else
        return true;
}

std::vector<Components *>Game::Pacman::getComponents()
{
    std::vector<Components *> c_pacman;

    c_pacman.push_back(this->pacman);
    c_pacman.push_back(this->waka);
    return c_pacman;
}

Component::Audio *Game::Pacman::getWakaAudio()
{
    return this->waka;
}

Component::Sprite * Game::Pacman::getSprite()
{
    return this->pacman;
}

IntRect_t *Game::Pacman::which_moveRect()
{
    if (this->upRectSp.second != -1)
        return this->upRectSp.first.at(this->upRectSp.second);
    else if (this->downRectSp.second != -1)
        return this->downRectSp.first.at(this->downRectSp.second);
    else if (this->leftRectSp.second != -1)
        return this->leftRectSp.first.at(this->leftRectSp.second);
    else if (this->rightRectSp.second != -1)
        return this->rightRectSp.first.at(this->rightRectSp.second);
    return NULL;
}



std::pair<std::vector<Components *>, bool> Game::Pacman::compute(std::string &keyPressed)
{
    this->myUpdate.clear();
    this->pacman->resetState();
    this->waka->resetState();
    this->libNeedToBeReInit = false;

    std::pair<std::vector<Components *>, bool> send;

    bool checkMove = move(keyPressed);

    if (checkMove == false)
        this->wakaPlayAudio = false;
    if ( this->wakaPlayAudio == false && this->wakaPlayAudioOnPlay == true) {
        //std::cout << "STOP AUDIO" << std::endl;
        this->waka->setAudioState(Component::AudioState::PAUSE);
        this->waka->setState(Component::State::UPDATE);
        this->myUpdate.push_back(this->waka);
        this->wakaPlayAudioOnPlay = false;
    }
    else if (this->wakaPlayAudio == true && this->wakaPlayAudioOnPlay == false) {
        //std::cout << "PLAY AUDIO" << std::endl;
        this->waka->setAudioState(Component::AudioState::PLAY);
        this->waka->setState(Component::State::UPDATE);
        this->myUpdate.push_back(this->waka);
        this->wakaPlayAudioOnPlay = true;
    }
    if (checkMove == true)
        this->myUpdate.push_back(this->pacman);
    for (size_t i = 0; i != this->myUpdate.size(); i += 1)
        send.first.push_back(this->myUpdate.at(i));
    send.second = this->libNeedToBeReInit;
    return send;
}

void Game::Pacman::initRectSp()
{
    this->upRectSp.first.push_back(new IntRect_t{166, 27, 0, 27});
    this->upRectSp.first.push_back(new IntRect_t{138, 27, 0, 27});
    this->upRectSp.second = -1;
    this->downRectSp.first.push_back(new IntRect_t{221, 27, 0, 27});
    this->downRectSp.first.push_back(new IntRect_t{194, 27, 0, 27});
    this->downRectSp.second = -1;
    this->leftRectSp.first.push_back(new IntRect_t{83, 27, 0, 27});
    this->leftRectSp.first.push_back(new IntRect_t{111, 27, 0, 27});
    this->leftRectSp.second = -1;
    this->rightRectSp.first.push_back(new IntRect_t{27, 27, 0, 27});
    this->rightRectSp.first.push_back(new IntRect_t{0, 27, 0, 27});
    this->rightRectSp.second = 0;
}

void Game::Pacman::setDefaultPosition(Point2D *def)
{
    this->pacman->setPosition({def->x, def->y});
}

void Game::Pacman::assign(Game::GameObjects *gameObj)
{
    this->gameObj = gameObj;
    this->switcher = new Game::Switcher();
    this->switcher->gameObj = this->gameObj;
}

Game::Pacman::Pacman()
{
    initRectSp();
    IntRect_t *actual = which_moveRect();
    this->pacman = new Component::Sprite("Pacman", "assets/images/Pacman/small/sp2.png", std::pair<float, float>(50, 50), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("P", std::pair<int, int>(30, 30)));
    this->pacman->setRect(actual->x, actual->size_x, actual->y, actual->size_y);
    this->waka = new Component::Audio("wakaAudio", "assets/Sound/Pacman/waka.wav", Component::AudioState::STOP, true);
    this->wakaPlayAudio = false;
    this->wakaPlayAudioOnPlay = false;
    this->wakaAnim = getTime();
    this->moveAnim = getTime();
    this->direction = Game::direction::_none;
    this->isAlive = true;
    this->libNeedToBeReInit = false;
}

Game::Pacman::~Pacman()
{

}
