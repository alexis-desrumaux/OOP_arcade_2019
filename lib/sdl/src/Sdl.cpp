/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sdl
*/

#include "../include/SDL.hpp"

SDL_Color convertColorFromComponent(Component::Color::Color color)
{
    switch (color) {
        case Component::Color::White:
            return {255, 255, 255, 0};
        case Component::Color::Black:
            return {0, 0, 0, 0};
        case Component::Color::Red:
            return {255, 0, 0, 0};
        case Component::Color::Green:
            return {0, 128, 0, 0};
        case Component::Color::Blue:
            return {0, 0, 255, 0};
    }
    return {0, 0, 0, 0};
}

std::string SDLKeyToString(unsigned int keycode)
{
    std::string keyStr;

    switch(keycode) {
        case SDLK_a: keyStr = "A"; break;
        case SDLK_b: keyStr = "B"; break;
        case SDLK_c: keyStr = "C"; break;
        case SDLK_d: keyStr = "D"; break;
        case SDLK_e: keyStr = "E"; break;
        case SDLK_f: keyStr = "F"; break;
        case SDLK_g: keyStr = "G"; break;
        case SDLK_h: keyStr = "H"; break;
        case SDLK_i: keyStr = "I"; break;
        case SDLK_j: keyStr = "J"; break;
        case SDLK_k: keyStr = "K"; break;
        case SDLK_l: keyStr = "L"; break;
        case SDLK_m: keyStr = "M"; break;
        case SDLK_n: keyStr = "N"; break;
        case SDLK_o: keyStr = "O"; break;
        case SDLK_p: keyStr = "P"; break;
        case SDLK_q: keyStr = "Q"; break;
        case SDLK_r: keyStr = "R"; break;
        case SDLK_s: keyStr = "S"; break;
        case SDLK_t: keyStr = "T"; break;
        case SDLK_u: keyStr = "U"; break;
        case SDLK_v: keyStr = "V"; break;
        case SDLK_w: keyStr = "W"; break;
        case SDLK_x: keyStr = "X"; break;
        case SDLK_y: keyStr = "Y"; break;
        case SDLK_z: keyStr = "Z"; break;
        case SDLK_ESCAPE: keyStr = "Escape"; break;
        case SDLK_LCTRL: keyStr = "LControl"; break;
        case SDLK_LSHIFT: keyStr = "LShift"; break;
        case SDLK_LALT: keyStr = "LAlt"; break;
        case SDLK_RCTRL: keyStr = "RControl"; break;
        case SDLK_RSHIFT: keyStr = "RShift"; break;
        case SDLK_RALT: keyStr = "RAlt"; break;
        case SDLK_MENU: keyStr = "Menu"; break;
        case SDLK_LEFTBRACKET: keyStr = "LBracket"; break;
        case SDLK_RIGHTBRACKET: keyStr = "RBracket"; break;
        case SDLK_SEMICOLON: keyStr = ";"; break;
        case SDLK_COMMA: keyStr = ","; break;
        case SDLK_PERIOD: keyStr = "."; break;
        case SDLK_QUOTE: keyStr = "\'"; break;
        case SDLK_SLASH: keyStr = "/"; break;
        case SDLK_BACKSLASH: keyStr = "\\"; break;
        case SDLK_EQUALS: keyStr = "="; break;
        case SDLK_MINUS: keyStr = "-"; break;
        case SDLK_SPACE: keyStr = "Space"; break;
        case SDLK_RETURN: keyStr = "Return"; break;
        case SDLK_BACKSPACE: keyStr = "Back"; break;
        case SDLK_TAB: keyStr = "Tab"; break;
        case SDLK_PAGEUP: keyStr = "Page Up"; break;
        case SDLK_PAGEDOWN: keyStr = "Page Down"; break;
        case SDLK_END: keyStr = "End"; break;
        case SDLK_HOME: keyStr = "Home"; break;
        case SDLK_INSERT: keyStr = "Insert"; break;
        case SDLK_DELETE: keyStr = "Delete"; break;
        case SDLK_PLUS: keyStr = "+"; break;
        case SDLK_KP_MINUS: keyStr = "-"; break;
        case SDLK_ASTERISK: keyStr = "*"; break;
        case SDLK_KP_MULTIPLY: keyStr = "*"; break;
        case SDLK_KP_DIVIDE: keyStr = "/"; break;
        case SDLK_LEFT: keyStr = "Left"; break;
        case SDLK_RIGHT: keyStr = "Right"; break;
        case SDLK_UP: keyStr = "Up"; break;
        case SDLK_DOWN: keyStr = "Down"; break;
        case SDLK_0: keyStr = "NP 0"; break;
        case SDLK_1: keyStr = "NP 1"; break;
        case SDLK_2: keyStr = "NP 2"; break;
        case SDLK_3: keyStr = "NP 3"; break;
        case SDLK_4: keyStr = "NP 4"; break;
        case SDLK_5: keyStr = "NP 5"; break;
        case SDLK_6: keyStr = "NP 6"; break;
        case SDLK_7: keyStr = "NP 7"; break;
        case SDLK_8: keyStr = "NP 8"; break;
        case SDLK_9: keyStr = "NP 9"; break;
        case SDLK_F1: keyStr = "F1"; break;
        case SDLK_F2: keyStr = "F2"; break;
        case SDLK_F3: keyStr = "F3"; break;
        case SDLK_F4: keyStr = "F4"; break;
        case SDLK_F5: keyStr = "F5"; break;
        case SDLK_F6: keyStr = "F6"; break;
        case SDLK_F7: keyStr = "F7"; break;
        default:
        keyStr = "";
    }
    return keyStr;
}

int SDL::SDL::draw(void)
{
    for (size_t i = 0; i != this->lComponents.size(); i += 1) {
        //std::cout << "DRAWING " << this->lComponents.at(i)->componentName << std::endl;
        this->lComponents.at(i)->draw(this->window);
    }
    //std::cout << "--------------------------------------" << std::endl;
    return 0;
}

int SDL::SDL::manageUpdate(std::vector<Components *> update)
{
    for (size_t i = 0; i != update.size(); i += 1) {
        if (findInLComponents(this->lComponents, update.at(i)->componentName) != NULL) {
            findInLComponents(this->lComponents, update.at(i)->componentName)->display = update.at(i)->display;
            switch (update.at(i)->type)
            {
            case listComponent::TEXT:
            {
                Component::Text *text = dynamic_cast<Component::Text *>(update.at(i));
                if (text->getState().first == Component::State::UPDATE) {
                   LComponent::Text *c = dynamic_cast<LComponent::Text *>(findInLComponents(this->lComponents, text->componentName));
                   c->update(text);
                }
                break;
            }
            case listComponent::SPRITE:
            {
                Component::Sprite *sprite = dynamic_cast<Component::Sprite *>(update.at(i));
                if (sprite->getState().first == Component::State::UPDATE) {
                   LComponent::Sprite *c = dynamic_cast<LComponent::Sprite *>(findInLComponents(this->lComponents, sprite->componentName));
                   c->update(sprite);
                }
                break;
            }
            case listComponent::AUDIO:
            {
                Component::Audio *audio = dynamic_cast<Component::Audio *>(update.at(i));
                if (audio->getState().first == Component::State::UPDATE) {
                    LComponent::Audio *c = dynamic_cast<LComponent::Audio *>(findInLComponents(this->lComponents, audio->componentName));
                    c->update(audio);
                }
                break;
            }
            default:
                break;
            }
        }
    }
    return 0;
}

std::string SDL::SDL::display(std::vector<Components *> update)
{
    SDL_Event event;
    std::string keyPressed = "";

    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            this->isRunning = false;
            SDL_Quit();
            TTF_Quit();
            Mix_CloseAudio();
            return keyPressed;
        case SDL_KEYDOWN:
            keyPressed = SDLKeyToString(event.key.keysym.sym);
            if (keyPressed == "F4" || keyPressed == "F5") {
                SDL_Quit();
                TTF_Quit();
                Mix_CloseAudio();
                return keyPressed;
            }
            break;
        default:
            break;
    }
    manageUpdate(update);
    SDL_FillRect(this->window, NULL, 0x000000);
    draw();
    SDL_UpdateRect(this->window, 0, 0, 0, 0);
    if (SDL_GetTicks() < (this->lastrender + 1000 / 60))
        SDL_Delay((this->lastrender + 1000 / 60) - SDL_GetTicks());
    this->lastrender = SDL_GetTicks();
    return keyPressed;
}

void deleteUnusedLComponents(std::vector<SDL::LComponents *>&lComponents, std::vector<size_t> listLComponentSavedIndex)
{
    for (size_t j = 0; j != lComponents.size(); j += 1) {
        bool found = false;
        for (size_t i = 0; i != listLComponentSavedIndex.size(); i += 1) {
            if (j == listLComponentSavedIndex.at(i)) {
                found = true;
                break;
            }
        }
        if (!found)
            delete lComponents.at(j);
    }
}

size_t initLibFindLComponentsIndex(std::vector<SDL::LComponents *>&lcomponent, std::string name)
{
    for (size_t i = 0; !lcomponent.empty() && i != lcomponent.size(); i += 1) {
        if (lcomponent.at(i)->componentName == name)
            return i;
    }
    return 0;
}

SDL::LComponents *initLibFindLComponentsExist(std::vector<SDL::LComponents *>&lcomponent, std::string name)
{
    for (size_t i = 0; !lcomponent.empty() && i != lcomponent.size(); i += 1) {
        if (lcomponent.at(i)->componentName == name)
            return lcomponent.at(i);
    }
    return NULL;
}

int SDL::SDL::initLib(std::vector<Components *> components)
{
    std::vector<size_t> listLComponentSavedIndex;
    std::vector<LComponents *> newList;

    for (size_t i = 0; i != components.size(); i += 1) {
        switch (components.at(i)->type)
        {
        case listComponent::TEXT:
            if (initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName) != NULL) {
                listLComponentSavedIndex.push_back(initLibFindLComponentsIndex(this->lComponents, components.at(i)->componentName));
                LComponent::Text *txt = dynamic_cast<LComponent::Text *>(initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName));
                newList.push_back(txt);
            }
            else
                newList.push_back(new LComponent::Text(dynamic_cast<Component::Text *>(components.at(i))));
            break;
        case listComponent::SPRITE:
            if (initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName) != NULL) {
                listLComponentSavedIndex.push_back(initLibFindLComponentsIndex(this->lComponents, components.at(i)->componentName));
                LComponent::Sprite *sprite = dynamic_cast<LComponent::Sprite *>(initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName));
                newList.push_back(sprite);
            }
            else {
                newList.push_back(new LComponent::Sprite(dynamic_cast<Component::Sprite *>(components.at(i))));
            }
            break;
        case listComponent::AUDIO:
            if (initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName) != NULL) {
                listLComponentSavedIndex.push_back(initLibFindLComponentsIndex(this->lComponents, components.at(i)->componentName));
                LComponent::Audio *audio = dynamic_cast<LComponent::Audio *>(initLibFindLComponentsExist(this->lComponents, components.at(i)->componentName));
                newList.push_back(audio);
            }
            else
                newList.push_back(new LComponent::Audio(dynamic_cast<Component::Audio *>(components.at(i)), this->channel));
            break;
        default:
            break;
        }
    }
    deleteUnusedLComponents(this->lComponents, listLComponentSavedIndex);
    this->lComponents = newList;
    return 0;
}

SDL::SDL::SDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
        exit(84);
    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    SDL_WM_SetCaption("ARCADE", NULL);
    this->window = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE);
    this->name = "";
    this->channel = 1;
    this->lastrender = 0;
}

SDL::SDL::~SDL()
{
}

extern "C"
{
	IGLib *createLib()
	{
		return new SDL::SDL();
	}
}


