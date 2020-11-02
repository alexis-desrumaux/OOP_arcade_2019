/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <time.h>
#include <sys/time.h>
#include "IGame.hpp"

#define marginMapLeft 320
#define marginMapTop 100

typedef struct IntRect_s 
{
    int x;
    int size_x;
    int y;
    int size_y;
} IntRect_t;

typedef struct Point2D_s
{
    int x;
    int y;
} Point2D;

/*typedef struct Switcher_s
{
    Point2D *line;
    IntRect_t lineSize;
    int direction;
} Switcher;*/

namespace Game {
    enum class direction {
        _none = -1,
        _left = 0,
        _right = 1,
        _up = 2,
        _down = 3,
    };
    enum class objType {
        _none = -1,
        _empty = 0,
        _wall = 1,
        _switcher = 2,
        _pacGomme = 3,
    };
    class GameObjects;
    class Pacman;
    class Wall;
    class Switcher;
    class Map;

    class MapObject
    {
        public:
        //functions
            MapObject() = default;
            virtual ~MapObject() = default;
            virtual bool hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc) = 0;
        //data
            Game::GameObjects *gameObj;
            objType type;
        private:
    };
    class Pacman
    {
        public:
            Pacman();
            ~Pacman();
            std::pair<std::vector<Components *>, bool> compute(std::string &keyPressed);
            Component::Sprite *getSprite();
            Component::Audio *getWakaAudio();
            std::vector<Components *>getComponents();
            void setDefaultPosition(Point2D *def);
            void assign(Game::GameObjects *gameObj);
        //data
            int speedM;
            Game::GameObjects *gameObj;
        private:
        //functions
            bool move(std::string &keyPressed);
            bool manageSpecialActionOnPacman(int &speed, std::pair<int, Game::objType> sp, Game::direction dir);
            void moveLeft();
            void moveRight();
            void moveUp();
            void moveDown();
            std::pair<int, Game::objType> speedModifier(Game::direction dir, int far);
            bool switchDir(Game::direction origin, Game::direction dir);
            int teleport();
            void initRectSp();
            IntRect_t *which_moveRect();
        //data
            std::pair<std::vector<IntRect_t *>, int> upRectSp;
            std::pair<std::vector<IntRect_t *>, int> downRectSp;
            std::pair<std::vector<IntRect_t *>, int> leftRectSp;
            std::pair<std::vector<IntRect_t *>, int> rightRectSp;
            Component::Sprite *pacman;
            Component::Audio *waka;
            Game::direction direction;
            std::vector<Components *> myUpdate;
            Switcher *switcher;
            double wakaAnim;
            double moveAnim;
            bool isAlive;
            bool wakaPlayAudio;
            bool wakaPlayAudioOnPlay;
            bool libNeedToBeReInit;
    };
    class Wall : public MapObject
    {
        public:
        //functions
            Wall(int id, float x, float y);
            virtual ~Wall();
            std::pair<std::vector<Components *>, bool> compute(std::string &keyPressed);
            Component::Sprite *getSprite();
            virtual bool hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc);
        //data
        private:
        //data
            Component::Sprite *wall;
            std::vector<Components *> myUpdate;
            bool libNeedToBeReInit;
            bool isAlive;
    };
    class Empty : public MapObject
    {
        public:
        //functions
            Empty(Point2D *pos, IntRect_t *rect);
            virtual ~Empty();
            virtual bool hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc);
            Point2D *getPos();
            IntRect_t *getRect();
        //data
        private:
        //functions
        //data
            Point2D *pos;
            IntRect_t *rect;
    };
    class PacGomme : public MapObject
    {
        public:
        //functions
            PacGomme(int id, Point2D *pos, IntRect_t *rect);
            virtual ~PacGomme();
            virtual bool hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc);
            Component::Sprite *getSprite();
            Point2D *getPos();
            IntRect_t *getRect();
        private:
        //data
            Component::Sprite *pacGomme;
            Point2D *pos;
            IntRect_t *rect;
    };
    class Switcher : public MapObject
    {
        public:
        //functions
            Switcher();
            virtual ~Switcher();
            virtual bool hit(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc);
            Game::direction getSwitchDir(void);
            bool canSwitchDir(Game::direction dir);
            Point2D *getPos();
            IntRect_t *getRect();
            bool fitIn(Game::direction dir, int far, Point2D posSrc, IntRect_t rectSrc);
            bool putSwitcher(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
        //data
            Game::GameObjects *gameObj;
            bool actived;
        private:
        //functions
            bool putSwitcherRight(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherRightUp(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherRightDown(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherLeft(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherLeftUp(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherLeftDown(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherUp(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherUpLeft(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherUpRight(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherDown(Game::direction origin, Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherDownLeft(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            bool putSwitcherDownRight(Game::direction dir, std::vector<std::pair<Game::MapObject *, Point2D>> p);
            void reset(Point2D *pos, IntRect_t *rect, Game::direction dir);
        //data
            Point2D *pos;
            IntRect_t *rect;
            Game::direction dir;
    };
    class Map
    {
        public:
        //functions
            Map(std::string file);
            ~Map();
            std::vector<Components *> getComponents();
            std::vector<std::string *> *getFileMap();
            std::vector<std::vector<MapObject *> *> *getMap();
            Point2D *getDefPosPacman();
        //data
            Game::GameObjects *gameObj;
        private:
        //functions
            void createMap();
            void createBlocks();
        //data
            std::vector<std::string *> *fileMap;
            std::vector<std::vector<Game::MapObject *> *> *map;
            Point2D *defaultPosPacman;
    };
    class GameObjects
    {
        public:
        //functions
            GameObjects();
            ~GameObjects();
        //data
            Game::Pacman *pacman;
            Game::Map *Map;
            Component::Audio *audioBackground;

        private:
    };
};

class Pacman : public IGame
{
    public:
    //functions
        Pacman();
        virtual ~Pacman();
        virtual std::string Talk();
        virtual std::vector<Components *>initMenuGame();
        virtual std::vector<Components *>initGame();
        virtual std::vector<Components *> manageEventMenuGame(std::string &keyPressed);
        virtual cDoubleState manageEventGame(std::string &keyPressed);
        void manageEnd(std::string &keyPressed);
        void addInUpdateList(Components *toUpdate);
        void getComponentsFromGameObj();
        void resetListUpdateComponent();
        void resetStateComponents();
        void resetPacmanEachLoop();
    //settings
        std::vector<Components *> components;
        std::vector<Components *> update;
        Game::GameObjects *gameObj;
        bool needToBeReInit;
        time_t start;
        int speedM;
};

//GameObject.cpp
bool hitDown(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo);
bool hitUp(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo);
bool hitLeft(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo);
bool hitRight(Point2D posObjOne, IntRect_t rectObjOne, Point2D posObjTwo, IntRect_t rectObjTwo);
int checkIsAPath(Game::objType type);
IntRect_t convertGetRectToIntRect(std::pair<std::pair<int, int>, std::pair<int, int>> rectSrc);
double getTime();
bool isADirection(std::string &keyPressed);

#endif /* !PACMAN_HPP_ */
