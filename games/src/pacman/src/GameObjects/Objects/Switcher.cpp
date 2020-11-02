/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Switcher
*/

#include "../../../include/Pacman.hpp"

bool Game::Switcher::putSwitcherDownLeft(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestX = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            bestX = p.at(0).second.x < p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != 0) {
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX - 1);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    if ((p.at(0).second.y != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX - 1)->type) != -1)
                    && (p.at(0).second.y != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX - 1)->type == Game::objType::_empty) {
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX - 1));
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX - 1)->type == Game::objType::_pacGomme) {
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX - 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            bestX = p.at(0).second.x < p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != 0) {
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX);
                if (obj->type == Game::objType::_empty) {
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherDownRight(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestX = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            //std::cout << "P1" << std::endl;
            bestX = p.at(0).second.x > p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != (int)this->gameObj->Map->getMap()->at(p.at(0).second.y)->size() - 1) {
                //std::cout << "P1-1" << std::endl;
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX + 1);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    //std::cout << "P1-2" << std::endl;
                    if ((p.at(0).second.y != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX + 1)->type) != -1)
                    && (p.at(0).second.y != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX + 1)->type == Game::objType::_empty) {
                            //std::cout << "P1-3" << std::endl;
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX + 1));
                            //std::cout << "P1-3.1" << std::endl;
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX + 1)->type == Game::objType::_pacGomme) {
                            //std::cout << "P1-4" << std::endl;
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX + 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            //std::cout << "P2" << std::endl;
            bestX = p.at(0).second.x > p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != 0) {
                //std::cout << "P2-1" << std::endl;
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX);
                if (obj->type == Game::objType::_empty) {
                    //std::cout << "P2-2" << std::endl;
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    //std::cout << "P2-3" << std::endl;
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y - 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherDown(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    if (origin == Game::direction::_left)
        return putSwitcherDownLeft(dir, p);
    if (origin == Game::direction::_right)
        return putSwitcherDownRight(dir, p);
    return false;   
}

bool Game::Switcher::putSwitcherUpLeft(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestX = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            bestX = p.at(0).second.x < p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != 0) {
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX - 1);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    if ((p.at(0).second.y != (int)this->gameObj->Map->getMap()->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX - 1)->type) != -1)
                    && (p.at(0).second.y != (int)this->gameObj->Map->getMap()->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX - 1)->type == Game::objType::_empty) {
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX - 1));
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX - 1)->type == Game::objType::_pacGomme) {
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX - 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            bestX = p.at(0).second.x < p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != 0) {
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX);
                if (obj->type == Game::objType::_empty) {
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherUpRight(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestX = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            bestX = p.at(0).second.x > p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != (int)this->gameObj->Map->getMap()->at(p.at(0).second.y)->size() - 1) {
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX + 1);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    if ((p.at(0).second.y != (int)this->gameObj->Map->getMap()->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX + 1)->type) != -1)
                    && (p.at(0).second.y != (int)this->gameObj->Map->getMap()->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX + 1)->type == Game::objType::_empty) {
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX + 1));
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX + 1)->type == Game::objType::_pacGomme) {
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX + 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
            
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            bestX = p.at(0).second.x > p.at(1).second.x ? p.at(0).second.x : p.at(1).second.x;
            if (bestX != 0) {
                obj = this->gameObj->Map->getMap()->at(p.at(0).second.y)->at(bestX);
                if (obj->type == Game::objType::_empty) {
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    if (this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(p.at(0).second.y + 1)->at(bestX));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherUp(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    if (origin == Game::direction::_left)
        return putSwitcherUpLeft(dir, p);
    if (origin == Game::direction::_right)
        return putSwitcherUpRight(dir, p);
    return false;   
}

bool Game::Switcher::putSwitcherRightDown(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestY = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            bestY = p.at(0).second.y > p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != (int)this->gameObj->Map->getMap()->size() - 1) {
                obj = this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    if ((p.at(0).second.x != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x - 1)->type) != -1)
                    && (p.at(0).second.x != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x - 1)->type == Game::objType::_empty) {
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x - 1));
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x - 1)->type == Game::objType::_pacGomme) {
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x - 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            //std::cout << "2P-1" << std::endl;
            bestY = p.at(0).second.y > p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != (int)this->gameObj->Map->getMap()->size() - 1) {
                //std::cout << "2P-2" << std::endl;
                obj = this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_empty) {
                    //std::cout << "2P-3" << std::endl;
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1)->type == Game::objType::_pacGomme) {
                        //std::cout << "2P-4" << std::endl;
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    //std::cout << "2P-5" << std::endl;
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherRightUp(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestY = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            bestY = p.at(0).second.y < p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != 0) {
                obj = this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    if ((p.at(0).second.x != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x - 1)->type) != -1)
                    && (p.at(0).second.x != 0 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x - 1)->type == Game::objType::_empty) {
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x - 1));
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x - 1)->type == Game::objType::_pacGomme) {
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x - 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            bestY = p.at(0).second.y < p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != 0) {
                obj = this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_empty) {
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x - 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherRight(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    if (origin == Game::direction::_up)
        return putSwitcherRightUp(dir, p);
    if (origin == Game::direction::_down)
        return putSwitcherRightDown(dir, p);
    return false;
}

bool Game::Switcher::putSwitcherLeftDown(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestY = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            bestY = p.at(0).second.y > p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != (int)this->gameObj->Map->getMap()->size() - 1) {
                obj = this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    if ((p.at(0).second.x != (int)this->gameObj->Map->getMap()->at(bestY + 1)->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x + 1)->type) != -1)
                    && (p.at(0).second.x != (int)this->gameObj->Map->getMap()->at(bestY)->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x + 1)->type == Game::objType::_empty) {
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x + 1));
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x + 1)->type == Game::objType::_pacGomme) {
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY + 1)->at(p.at(0).second.x + 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            bestY = p.at(0).second.y > p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != (int)this->gameObj->Map->getMap()->size() - 1) {
                obj = this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_empty) {
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherLeftUp(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    int bestY = 0;
    Game::Empty *intersec;
    Game::PacGomme *intersec2;
    Game::MapObject *obj;

    if (p.size() == 2) {
        if (p.at(0).first->type == Game::objType::_wall && p.at(1).first->type == Game::objType::_wall) {
            bestY = p.at(0).second.y < p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != 0) {
                obj = this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_wall) {
                }
                if (checkIsAPath(obj->type) != -1)
                {
                    if ((p.at(0).second.x != (int)this->gameObj->Map->getMap()->at(bestY - 1)->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x + 1)->type) != -1)
                    && (p.at(0).second.x != (int)this->gameObj->Map->getMap()->at(bestY)->size() - 1 && checkIsAPath(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1)->type) != -1)) {
                        if (this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x + 1)->type == Game::objType::_empty) {
                            intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x + 1));
                            this->reset(intersec->getPos(), intersec->getRect(), dir);
                            return true;
                        }
                        else if (this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x + 1)->type == Game::objType::_pacGomme) {
                            intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY - 1)->at(p.at(0).second.x + 1));
                            this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                            return true;
                        }
                    }
                }
            }
        }
        else if ((p.at(0).first->type == Game::objType::_wall && checkIsAPath(p.at(1).first->type) != -1) || (checkIsAPath(p.at(0).first->type) != -1 && p.at(1).first->type == Game::objType::_wall)) {
            bestY = p.at(0).second.y < p.at(1).second.y ? p.at(0).second.y : p.at(1).second.y;
            if (bestY != 0) {
                obj = this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x);
                if (obj->type == Game::objType::_empty) {
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
                else if (obj->type == Game::objType::_pacGomme) {
                    if (this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1)->type == Game::objType::_pacGomme) {
                        intersec2 = dynamic_cast<Game::PacGomme *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                        this->reset(intersec2->getPos(), intersec2->getRect(), dir);
                        return true;
                    }
                    intersec = dynamic_cast<Game::Empty *>(this->gameObj->Map->getMap()->at(bestY)->at(p.at(0).second.x + 1));
                    this->reset(intersec->getPos(), intersec->getRect(), dir);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::Switcher::putSwitcherLeft(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    if (origin == Game::direction::_up)
        return putSwitcherLeftUp(dir, p);
    if (origin == Game::direction::_down)
        return putSwitcherLeftDown(dir, p);
    return false;
}

bool Game::Switcher::putSwitcher(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p)
{
    if (dir == Game::direction::_right) {
        //std::cout << "right" << std::endl;
        return putSwitcherRight(origin, dir, p);
    }
    if (dir == Game::direction::_left) {
        //std::cout << "left" << std::endl;
        return putSwitcherLeft(origin, dir, p);
    }
    if (dir == Game::direction::_up) {
        //std::cout << "up" << std::endl;
        return putSwitcherUp(origin, dir, p);
    }
    if (dir == Game::direction::_down) {
        //std::cout << "down" << std::endl;
        return putSwitcherDown(origin, dir, p);
    }
    return false;
}

Game::direction Game::Switcher::getSwitchDir(void)
{
    return this->dir;
}

void Game::Switcher::reset(Point2D *pos, IntRect_t *rect, Game::direction dir)
{
    this->pos = pos;
    this->rect = rect;
    this->dir = dir;
    this->actived = true;
}

bool Game::Switcher::fitIn(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc)
{
    Point2D myPosSrc = {posSrc.x, posSrc.y};
    if (dir == Game::direction::_left || dir == Game::direction::_right) {
        myPosSrc.x += far;
    }
    if (dir == Game::direction::_up || dir == Game::direction::_down) {
        myPosSrc.y += far;
    }

    if (this->pos->x == myPosSrc.x && this->pos->y == myPosSrc.y &&
    this->pos->x + this->rect->size_x == myPosSrc.x + rectSrc.size_x && this->pos->y + this->rect->size_y == myPosSrc.y + rectSrc.size_y)
        return true;
    return false;
}

IntRect_t *Game::Switcher::getRect()
{
    return this->rect;
}

Point2D *Game::Switcher::getPos()
{
    return this->pos;
}

bool Game::Switcher::hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc)
{
    dir = dir;
    far = far;
    posSrc = posSrc;
    rectSrc = rectSrc;
    return false;
}

Game::Switcher::Switcher()
{
    this->pos = new Point2D;
    this->rect = new IntRect_t;
    this->actived = false;
}

Game::Switcher::~Switcher()
{
}
