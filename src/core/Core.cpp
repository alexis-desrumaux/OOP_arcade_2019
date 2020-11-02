/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include <dirent.h>
#include "Core.hpp"
#include <sys/stat.h>
#include <dlfcn.h>
#include <string.h>

#include <chrono>
#include <ctime>
#include <time.h>

static struct {
    std::string name;
} lib_name [19] = {
    {"lib_arcade_ncurses.so"},
    {"lib_arcade_ndk++.so"},
    {"lib_arcade_aa-lib.so"},
    {"lib_arcade_libcaca.so"},
    {"lib_arcade_allegro4.so"},
    {"lib_arcade_allegro5.so"},
    {"lib_arcade_xlib.so"},
    {"lib_arcade_gtk+.so"},
    {"lib_arcade_sfml.so"},
    {"lib_arcade_sdl1.so"},
    {"lib_arcade_sdl2.so"},
    {"lib_arcade_opengl.so"},
    {"lib_arcade_vulkan.so"},
    {"lib_arcade_qt.so"},
    {"lib_arcade_nibbler.so"},
    {"lib_arcade_pacman.so"},
    {"lib_arcade_quix.so"},
    {"lib_arcade_centipede.so"},
    {"lib_arcade_solarfox.so"},
};

std::string randomMenuAudio()
{
    std::srand(std::time(nullptr));
    int random_variable = std::rand();

    if (random_variable <= RAND_MAX / 2)
        return "assets/Sound/Core/menu.wav";
    if (random_variable > RAND_MAX / 2)
        return "assets/Sound/Core/menu2.wav";
    return "assets/Sound/Core/menu.wav";
}

std::vector<std::string> recup_content_folder(const char *path)
{
    DIR *dir;
    struct dirent *ls_dir;
    std::vector<std::string> content;

    dir = opendir(path);
    if (!dir)
        return content;
    for (int i = 0; (ls_dir = readdir(dir)) != NULL; i++) {
        if (ls_dir->d_name[0] != '.' && ls_dir->d_type != DT_DIR) {
            content.push_back(std::string(ls_dir->d_name));
        }
    }
    closedir(dir);
    return content;
} 

std::vector<std::string> recup_games(const char *path)
{
    std::vector<std::string> games_in_folder;
    std::vector<std::string> content_of_folder = recup_content_folder(path);
    std::string tmp;

    for (int i = 0; i < 19; i++) {
        for (size_t j = 0; j < content_of_folder.size(); j++) {
            if (lib_name[i].name == content_of_folder.at(j)) {
                tmp = "games/" + content_of_folder.at(j);
                games_in_folder.push_back(tmp);
                break;
            }
        }
        
    }
    return games_in_folder;
}

std::vector<std::string> recup_lib(const char *path)
{
    std::vector<std::string> lib_in_folder;
    std::string dpath = path;
    std::string validpath = dpath.substr(0, dpath.find_last_of('/'));
    std::vector<std::string> content_of_folder = recup_content_folder(validpath.c_str());
    std::string tmp;

    for (int i = 0; i != 19; i++) {
        for (size_t j = 0; j != content_of_folder.size(); j++) {
            if (lib_name[i].name == content_of_folder.at(j)) {
                tmp = validpath + "/" + content_of_folder.at(j);
                lib_in_folder.push_back(tmp);
                break;
            }
        }    
    }
    return lib_in_folder;
}

int get_actual_lib(std::string actual, std::vector<std::string> lib)
{
    for (size_t i = 0; i < lib.size(); i++) {
        if (actual == lib.at(i))
            return i;
    }
    return -1;
}

IGLib *getGLib(std::string entry_point, void *_handle)
{
    IGLib *(*ptr)(void);
    ptr = reinterpret_cast<IGLib *(*)()>(dlsym(_handle, entry_point.c_str()));

    if (ptr == NULL) {
        std::cerr << "dlsym Error: " << dlerror() << std::endl;
		return (NULL);
    }
	return ptr();
}

IGame *getGame(std::string entry_point, void *_handle)
{
    IGame *(*ptr)(void);
    ptr = reinterpret_cast<IGame *(*)()>(dlsym(_handle, entry_point.c_str()));

    if (ptr == NULL) {
        std::cerr << "dlsym Error: " << dlerror() << std::endl;
		return (NULL);
    }
	return ptr();
}

void *Core::load(std::string _path, int type)
{
	void *_handle = dlopen(_path.c_str(), RTLD_NOW | RTLD_GLOBAL);

    if (type == 0) {
        this->handle_lib = _handle;
    }
    if (type == 1) {
        this->handle_game = _handle;
    }

	if (_handle == NULL)
	{
        std::cerr << "dlopen Error: " << dlerror() << " in lib " << _path << std::endl;
        std::cout << "OPEN FAILED" << std::endl;
        exit(84);
	}
    return _handle;
}

void Core::addInUpdateList(Components *toUpdate)
{

    this->update.push_back(toUpdate);
}

void Core::resetStateComponents()
{
    if (this->components.empty() != true) {
        for (size_t i = 0; i != this->components.size(); i += 1) {
            this->components.at(i)->resetState();
        }
    }
}

void Core::resetListUpdateComponent()
{
    this->update.clear();
}

int Core::manageStateMenu()
{
    switch (this->_currentLib->state) {
        case set_playe_name:
            break;
        case select_game_and_graph:
            break;
        case play_game:
            break;
        case display_menu:
            break;
    }
    return 0;
}

int Core::manageSpecialEventKey()
{
    if (this->keyPressed == "F4") {
        this->actual_lib--;
        if (this->actual_lib < 0)
            this->actual_lib = (int)this->graph_lib.size() - 1;
        this->_currentLib->~IGLib();
        dlclose(this->handle_lib);
        this->_currentLib = getGLib("createLib", load(this->graph_lib.at(this->actual_lib), 0));
        this->_currentLib->isRunning = true;
        this->_currentLib->initLib(this->components);
        this->keyPressed = "";
        resetListUpdateComponent();
    }
    else if (this->keyPressed == "F5") {
        this->actual_lib++;
        if (this->actual_lib >= (int)this->graph_lib.size())
            this->actual_lib = 0;
        this->_currentLib->~IGLib();
        dlclose(this->handle_lib);
        this->_currentLib = getGLib("createLib", load(this->graph_lib.at(this->actual_lib), 0));
        this->_currentLib->isRunning = true;
        this->_currentLib->initLib(this->components);
        this->keyPressed = "";
        resetListUpdateComponent();
    }
    if (this->menuState == 3) {
        if (this->keyPressed == "F2") {
            this->actual_game--;
            if (this->actual_game < 0)
                this->actual_game = (int)this->games_lib.size() - 1;
            dlclose(this->handle_game);
            this->_currentGame = getGame("createGame", load(this->games_lib.at(this->actual_game), 1));
            this->components = this->_currentGame->initGame();
            this->_currentLib->initLib(this->components);
            this->keyPressed = "";
            return 1;
        }
        else if (this->keyPressed == "F3") {
            this->actual_game++;
            if (this->actual_game >= (int)this->games_lib.size())
                this->actual_game = 0;
            dlclose(this->handle_game);
            this->_currentGame = getGame("createGame", load(this->games_lib.at(this->actual_game), 1));
            this->components = this->_currentGame->initGame();
            this->_currentLib->initLib(this->components);
            this->keyPressed = "";
            return 1;
        }
        else if (this->keyPressed == "F6") {
            std::vector<Components *> reset;
            this->_currentLib->initLib(reset);
            this->components = this->_currentGame->initGame();
            this->_currentLib->initLib(this->components);
            this->keyPressed = "";
            return 1;
        }
        else if (this->keyPressed == "F7") {
            this->menuState = 1;
            this->actual_game = 1;
            this->_currentLib->isRunning = true;
            dlclose(this->handle_game);
            this->_currentGame = getGame("createGame", load(this->games_lib.at(this->actual_game), 1));
            this->keyPressed.clear();
            return -1;
        }
    }
    return 0;
}

void Core::assignEventFromGame(cDoubleState received)
{
    this->components = received.first.first;
    this->update = received.second;
    if (received.first.second == true)
        this->_currentLib->initLib(this->components);
}

int Core::game()
{
    this->_currentLib->initLib(std::vector<Components *>());
    this->components = this->_currentGame->initGame();
    this->_currentLib->initLib(this->components);

    int out = 0;

    while (this->_currentLib->isRunning) {
        cDoubleState received = this->_currentGame->manageEventGame(keyPressed);
        out = manageSpecialEventKey();
        if (out == 1)
            continue;
        if (out == -1)
            break;
        assignEventFromGame(received);
        this->keyPressed = this->_currentLib->display(this->update);
    }
    return 0;
}

void Core::nextGameMenu()
{
    dlclose(this->handle_game);
    this->_currentGame = getGame("createGame", load(this->games_lib.at(this->actual_game), 1));
    Component::Audio *menuAudio = dynamic_cast<Component::Audio *>(findInComponents(this->components, "menuAudio"));
    Component::Audio *menuAudioSelect = dynamic_cast<Component::Audio *>(findInComponents(this->components, "menuAudioSelect"));
    Component::Sprite *sprite = dynamic_cast<Component::Sprite *>(findInComponents(this->components, "Background#2"));
    std::vector<Components *> gameMenuComponents = this->_currentGame->initMenuGame();
    menuAudio->setState(Component::State::ADD);
    menuAudioSelect->setState(Component::State::ADD);
    sprite->setState(Component::State::ADD);
    this->components.clear();
    this->components.push_back(menuAudio);
    this->components.push_back(menuAudioSelect);
    this->components.push_back(sprite);
    for (size_t i = 0; i != gameMenuComponents.size(); i += 1) {
        this->components.push_back(gameMenuComponents.at(i));
    }
    this->_currentLib->initLib(this->components);
    resetListUpdateComponent();
    Component::Audio *select = dynamic_cast<Component::Audio *>(findInComponents(this->components, "menuAudioSelect"));
    select->setAudioState(Component::AudioState::RELOAD);
    select->setState(Component::State::UPDATE);
    addInUpdateList(select);
}

int Core::manageEventMenuStateTwo(std::string &keyPressed)
{

    std::vector<Components *> update = this->_currentGame->manageEventMenuGame(keyPressed);
    for (size_t i = 0; i != update.size(); i += 1)
        this->update.push_back(update.at(i));
    if (!keyPressed.empty() && keyPressed.size() != 0) {
        if (keyPressed.size() > 1 && this->components.empty() != true) {
            if (keyPressed == "Right") {
                size_t actual_game_size  = this->actual_game;
                if (actual_game_size + 1 > this->games_lib.size() - 1)
                    this->actual_game = 0;
                else
                    this->actual_game += 1;
                nextGameMenu();   
            }
            else if (keyPressed == "Left") {
                int actual_game_size  = static_cast<int>(this->actual_game);
                if (actual_game_size - 1  == -1)
                    this->actual_game = this->games_lib.size() - 1;
                else
                    this->actual_game -= 1;
                nextGameMenu();
            }
            else if (keyPressed == "F7") {
                initMenu();
                this->_currentLib->initLib(this->components);
                menuState = 0;
                resetListUpdateComponent();
                Component::Audio *cancel = dynamic_cast<Component::Audio *>(findInComponents(this->components, "menuAudioCancel"));
                cancel->setAudioState(Component::AudioState::PLAY);
                cancel->setState(Component::State::UPDATE);
                addInUpdateList(cancel);
            }
            else if (keyPressed == "Return") {
                this->menuState = 3;
                resetListUpdateComponent();
            }
        }
    }
    return 0;
}

int Core::manageEventMenuStateOneNext(std::string &keyPressed)
{
    if (keyPressed == "Back") {
        Component::Text *text = dynamic_cast<Component::Text *>(findInComponents(this->components, "Name"));
        std::string str = text->getText();
        if (str.size() != 0) {
            str.pop_back();
            text->setText(str);
            text->setState(Component::State::UPDATE);
            addInUpdateList(findInComponents(this->components, "Name"));
        }
    }
    else if (keyPressed == "Space") {
        Component::Text *text = dynamic_cast<Component::Text *>(findInComponents(this->components, "Name"));
        std::string str = text->getText();
        str += " ";
        text->setText(str);
        text->setState(Component::State::UPDATE);
        addInUpdateList(findInComponents(this->components, "Name"));
    }
    else if (keyPressed == "Return") {
        Component::Text *text = dynamic_cast<Component::Text *>(findInComponents(this->components, "Name"));
        std::string str = text->getText();
        if (str != "") {
            initMenuGameSelection();
        }
    }
    return 0;
}

int Core::manageEventMenuStateOne(std::string &keyPressed)
{
    if (!keyPressed.empty() && keyPressed.size() != 0) {
        if (keyPressed.size() == 1 && keyPressed.at(0) >= 'A' && keyPressed.at(0) <= 'Z' && this->components.empty() != true) {
            Component::Text *text = dynamic_cast<Component::Text *>(findInComponents(this->components, "Name"));
            std::string name = text->getText();
            name += keyPressed;
            text->setText(name);
            text->setState(Component::State::UPDATE);
            addInUpdateList(findInComponents(this->components, "Name"));
        }
        else if (keyPressed.size() > 1 && this->components.empty() != true) {
            manageEventMenuStateOneNext(keyPressed);
        }
    }
    return 0;
}

int Core::manageEventMenu(std::string &keyPressed)
{
    switch (this->menuState)
    {
    case 1:
        manageEventMenuStateOne(keyPressed);
        break;
    case 2:
        manageEventMenuStateTwo(keyPressed);
        break;
    default:
        break;
    }
    manageSpecialEventKey();
    keyPressed = "";
    return 0;
}

int Core::initMenuGameSelection()
{
    std::vector<Components *> old = this->components;
    this->components.clear();
    this->components.push_back(dynamic_cast<Component::Audio *>(findInComponents(old, "menuAudio")));
    this->components.push_back(new Component::Audio("menuAudioSelect", "assets/Sound/Core/select.wav", Component::AudioState::STOP, false));
    this->components.push_back(new Component::Audio("menuAudioAccept2", "assets/Sound/Core/accept2.wav", Component::AudioState::PLAY, false));
    this->components.push_back(new Component::Sprite("Background#2", "assets/images/Core/menuGame.png", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    std::vector<Components *> gameMenuComponents = this->_currentGame->initMenuGame();
    for (size_t i = 0; i != gameMenuComponents.size(); i += 1) {
        this->components.push_back(gameMenuComponents.at(i));
    }
    this->start = time(0);
    this->_currentLib->initLib(this->components);
    this->menuState = 2;
    resetListUpdateComponent();
    return 0;
}

int Core::initMenu()
{
    std::vector<Components *> old = this->components;
    this->components.clear();
    this->update.clear();
    if (findInComponents(old, "menuAudio") == NULL)
        this->components.push_back(new Component::Audio("menuAudio", randomMenuAudio(), Component::AudioState::PLAY, true));
    else
        this->components.push_back(dynamic_cast<Component::Audio *>(findInComponents(old, "menuAudio")));
    this->components.push_back(new Component::Audio("menuAudioCancel", "assets/Sound/Core/cancel.wav", Component::AudioState::STOP, false));
    this->components.push_back(new Component::Sprite("Background", "assets/images/Core/Home2.png", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    this->components.push_back(new Component::Sprite("Panel", "assets/images/Core/panel.png", std::pair<float, float>(1920 / 2 - 290, 1080/3 - 50), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    this->components.push_back(new Component::Text("Title", "What's your name ?", "assets/font/arcade.ttf", 30, Component::Color::White, std::pair<float, float>(1920 / 2 - 280, 1080/3), std::pair<int, int>(70, 15)));
    this->components.push_back(new Component::Text("Name", "", "assets/font/arcade.ttf", 40, Component::Color::White, std::pair<float, float>(1920 / 2 - 280, 1080/2 + 40), std::pair<int, int>(70, 20)));
    return 0;
}

int Core::menu()
{
    initMenu();
    this->_currentLib->initLib(this->components);
    while (this->_currentLib->isRunning && this->menuState != 3) {
        manageEventMenu(this->keyPressed);
        this->keyPressed = this->_currentLib->display(this->update);
        if (this->keyPressed != "") {
            //std::cout << this->keyPressed << std::endl;
        }
        resetStateComponents();
        resetListUpdateComponent();
    }
    return 0;
}

int Core::testMenu()
{
    this->components.push_back(new Component::Sprite("Background", "assets/images/Core/Home2.png", std::pair<float, float>(0, 0), std::pair<float, float>(1, 1), std::pair<std::string, std::pair<int, int>>("", std::pair<int, int>(-1, -1))));
    this->components.push_back(new Component::Text("Title", "Hello", "assets/font/arcade.ttf", 30, Component::Color::White, std::pair<float, float>(1920 / 2 - 280, 1080/3), std::pair<int, int>(70, 20)));
    this->_currentLib->initLib(this->components);
    
    while (this->_currentLib->isRunning) {
        this->keyPressed = this->_currentLib->display(this->update);
        if (!this->keyPressed.empty())
            std::cout << this->keyPressed << std::endl;
        resetStateComponents();
        resetListUpdateComponent();
    }
    return 0;
}

int Core::launch()
{
    //testMenu();
    while (1) {
        if (this->menuState != 3)
            menu();
        if (this->menuState >= 3) {
            game();
            if (this->menuState == 3)
                break;
        }
        else {
            break;
        }
    }
    return 0;
}

Core::Core()
{
    this->graph_lib = recup_lib("lib/");
    this->games_lib = recup_games("games/");
    this->actual_lib = 0;
    this->_currentGame = NULL;
}

Core::Core(std::string lib)
{
    this->graph_lib = recup_lib(lib.c_str());
    this->games_lib = recup_games("games/");
    this->actual_lib = get_actual_lib(lib, this->graph_lib);
    if (this->actual_lib == -1) {
        std::cout << "Lib not found" << std::endl;
        exit(84);   
    }
    this->actual_game = 1;
    this->_currentGame = getGame("createGame", load(this->games_lib.at(this->actual_game), 1));
    this->_currentLib = getGLib("createLib", load(this->graph_lib.at(this->actual_lib), 0));
    this->_currentLib->isRunning = true;
    this->menuState = 1;
}

Core::~Core()
{
    delete this->_currentGame;
    delete this->_currentLib;
    for (size_t i = 0; i != this->components.size(); i++) {
        this->components.at(i)->~Components();
    }
    dlclose(this->handle_game);
    dlclose(this->handle_lib);
}
