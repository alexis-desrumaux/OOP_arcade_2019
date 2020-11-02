/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sdl_c
*/

#include "../include/SDL.hpp"

/*--------------------------------AUDIO-----------------------------------*/

void SDL::LComponent::Audio::draw(SDL_Surface *window)
{
    window = window;
    //std::cout << "P1" << std::endl;
    if (this->audioState == Component::AudioState::RELOAD && this->reload == true) {
        //std::cout << "P1-1 " << this->componentName << " channel: " << this->myChannel << std::endl;
        Mix_PlayChannel(this->myChannel, this->sound, this->loop);
        this->reload = false;
        this->onPlaying = true;
    }
    if (this->onPlaying == false && this->audioState == Component::AudioState::PLAY && this->display == true) {
        //std::cout << "P1-2 " << this->componentName << " channel: " << this->myChannel << " " << this->loop << std::endl;
        Mix_PlayChannel(this->myChannel, this->sound, this->loop);
        this->onPlaying = true;
    }
    if (this->audioState == Component::AudioState::STOP) {
        //std::cout << "P1-3 " << this->componentName << " channel: " << this->myChannel << std::endl;
        Mix_HaltChannel(this->myChannel);
        this->onPlaying = false;
    }
    if (this->audioState == Component::AudioState::PAUSE  || this->display == false) {
        //std::cout << "P1-4 "<< this->componentName << " channel: " << this->myChannel << std::endl;
        Mix_Pause(this->myChannel);
        this->onPlaying = false;
    }
}

int SDL::LComponent::Audio::update(Component::Audio *audio)
{
    std::pair<Component::State::State, std::vector<Component::Audio::onChange>> state = audio->getState();
    Component::AudioState::AudioState audioState = audio->getAudioState();

    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i))
        {
        case Component::Audio::onChange::_path:
        {
            Mix_HaltChannel(this->myChannel);
            Mix_FreeChunk(this->sound);
            this->sound = Mix_LoadWAV(audio->getAudioPath().c_str());
            break;
        }
        case Component::Audio::onChange::_audioState:
        {
            if (audioState == Component::AudioState::PAUSE)
                this->audioState = Component::AudioState::PAUSE;
            else if (audioState == Component::AudioState::PLAY)
                this->audioState = Component::AudioState::PLAY;
            else if (audioState == Component::AudioState::STOP)
                this->audioState = Component::AudioState::STOP;
            else if (audioState == Component::AudioState::RELOAD) {
                this->audioState = Component::AudioState::RELOAD;
                this->reload = true;
            }
            break;
        }
        case Component::Audio::onChange::_loop:
            if (audio->isLoop() == true)
                this->loop = -1;
            else
                this->loop = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}

SDL::LComponent::Audio::Audio(Component::Audio *audio, int &channel)
{
    this->componentName = audio->componentName;
    this->display = audio->display;
    this->sound = Mix_LoadWAV(audio->getAudioPath().c_str());
    this->myChannel = channel;
    channel++;
    Mix_AllocateChannels(channel + 1);
    if (audio->isLoop() == true)
        this->loop = -1;
    else
        this->loop = 0;
    this->audioState = audio->getAudioState();
}

SDL::LComponent::Audio::~Audio()
{
    //std::cout << "P2 " << this->componentName << " channel: " << this->myChannel << std::endl;
    Mix_HaltChannel(this->myChannel);
    Mix_FreeChunk(this->sound);
}

/*--------------------------------SPRITE-----------------------------------*/

void SDL::LComponent::Sprite::draw(SDL_Surface *window)
{
    if (this->display == true) {
        if (this->isCropped == true)
            SDL_BlitSurface(this->sprite, &this->crop, window, &this->position);
        if (this->isCropped == false)
            SDL_BlitSurface(this->sprite, NULL, window, &this->position);
    }
}

int SDL::LComponent::Sprite::update(Component::Sprite *sprite)
{
    std::pair<Component::State::State, std::vector<Component::Sprite::onChange>> state = sprite->getState();

    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i))
        {
        case Component::Sprite::onChange::_path:
        {
            this->sprite = IMG_Load(sprite->getSpritePath().c_str());
            break;
        }
        case Component::Sprite::onChange::_pos:
        {
            std::pair<float, float> xy = sprite->getPosition();
            this->position.x = xy.first;
            this->position.y = xy.second;
            break;
        }
        case Component::Sprite::onChange::_rect:
        {
            std::pair<std::pair<int, int>, std::pair<int, int>> rect = sprite->getRect();

            if (rect.first.first != -1 && rect.first.second != -1 && rect.second.first != -1 &&
            rect.second.second != -1) {
                this->crop.x = rect.first.first;
                this->crop.w = rect.first.second;
                this->crop.y = rect.second.first;
                this->crop.h = rect.second.second;
                this->isCropped = true;
            }
            else
                this->isCropped = false;
            break;
        }
        case Component::Sprite::onChange::_scale:
        {
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

SDL::LComponent::Sprite::Sprite(Component::Sprite *sprite)
{
    std::pair<float, float> xy = sprite->getPosition();
    std::pair<std::pair<int, int>, std::pair<int, int>> rect = sprite->getRect();


    this->isCropped = false;
    this->sprite = IMG_Load(sprite->getSpritePath().c_str());
    this->position.x = xy.first;
    this->position.y = xy.second;
    if (rect.first.first != -1 && rect.first.second != -1 && rect.second.first != -1 &&
    rect.second.second != -1) {
        this->crop.x = rect.first.first;
        this->crop.w = rect.first.second;
        this->crop.y = rect.second.first;
        this->crop.h = rect.second.second;
        this->isCropped = true;
    }
    this->componentName = sprite->componentName;
    this->display = sprite->display;
}

SDL::LComponent::Sprite::~Sprite()
{

}

/*--------------------------------TEXT-----------------------------------*/

void SDL::LComponent::Text::draw(SDL_Surface *window)
{
    if (this->display == true)
        SDL_BlitSurface(this->text, NULL, window, &this->position);
}

int SDL::LComponent::Text::update(Component::Text *text)
{
    std::pair<Component::State::State, std::vector<Component::Text::onChange>> state = text->getState();
    
    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i)) {
            case Component::Text::onChange::_color:
            {
                this->text = TTF_RenderText_Blended(this->font, text->getText().c_str(), convertColorFromComponent(text->getColor()));
                break;
            }
            case Component::Text::onChange::_fontPath:
            {
                this->font = TTF_OpenFont(text->getFontPath().c_str(), text->getFontSize());
                this->text = TTF_RenderText_Blended(this->font, text->getText().c_str(), convertColorFromComponent(text->getColor()));
                break;
            }
            case Component::Text::onChange::_pos:
            {
                std::pair<float, float> xy = text->getPosXY();
                this->position.x = xy.first;
                this->position.y = xy.second;
                break;
            }
            case Component::Text::onChange::_size:
            {
                this->font = TTF_OpenFont(text->getFontPath().c_str(), text->getFontSize());
                this->text = TTF_RenderText_Blended(this->font, text->getText().c_str(), convertColorFromComponent(text->getColor()));
                break;
            }
            case Component::Text::onChange::_str:
            {
                this->text = TTF_RenderText_Blended(this->font, text->getText().c_str(), convertColorFromComponent(text->getColor()));
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

SDL::LComponent::Text::Text(Component::Text *text)
{
    this->font = TTF_OpenFont(text->getFontPath().c_str(), text->getFontSize());
    this->text = TTF_RenderText_Blended(font, text->getText().c_str(), convertColorFromComponent(text->getColor()));
    std::pair<float, float> xy = text->getPosXY();
    this->position.x = xy.first;
    this->position.y = xy.second;
    this->componentName = text->componentName;
    this->display = text->display;
}

SDL::LComponent::Text::~Text()
{

}

/*---------------------------LComponents-----------------------------------*/

SDL::LComponents *findInLComponents(std::vector<SDL::LComponents *> &lcomponents, std::string name)
{
    for (size_t i = 0; i != lcomponents.size(); i += 1) {
        if (lcomponents.at(i)->componentName == name)
            return lcomponents.at(i);
    }
    return NULL;
}
