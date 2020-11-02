/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Components
*/

#include "Components.hpp"

bool isOnChangeExist(std::vector<int> *onChange, int def)
{
    bool check = false;

    if (onChange->empty())
        return false;
    else {
        for (size_t i = 0; i != onChange->size(); i += 1) {
            if (onChange->at(i) == def)
                check = true;
        }
        if (check == false)
            return false;
    }
    return true;
}

/*-------------------------AUDIO-----------------------*/

void Component::Audio::resetState()
{
    this->state.first = Component::State::NONE;
    this->state.second.clear();
}

void Component::Audio::setState(Component::State::State state)
{
    this->state.first = state;
}

const std::pair<Component::State::State, std::vector<Component::Audio::onChange>>
&Component::Audio::getState(void) const
{
    return this->state;
}

void Component::Audio::setLoop(bool state)
{
    this->loop = state;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_loop) == false)
        this->state.second.push_back(this->_loop);
}

bool Component::Audio::isLoop(void)
{
    return this->loop;
}

void Component::Audio::setAudioState(AudioState::AudioState state)
{
    this->audioState = state;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_audioState) == false)
        this->state.second.push_back(this->_audioState);
}

Component::AudioState::AudioState Component::Audio::getAudioState()
{
    return this->audioState;
}

void Component::Audio::setAudioPath(std::string path)
{
    this->path = path;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_path) == false)
        this->state.second.push_back(this->_path);
}

std::string Component::Audio::getAudioPath()
{
    return this->path;
}

Component::Audio::Audio(std::string componentName, std::string path, AudioState::AudioState state, bool loop)
{
    this->componentName = componentName;
    this->type = listComponent::AUDIO;
    this->display = true;
    this->path = path;
    this->audioState = state;
    this->loop = loop;
    this->state.first = Component::State::ADD;
}

Component::Audio::~Audio()
{

}

/*-------------------------SPRITE-----------------------*/

void Component::Sprite::resetState(void)
{
    this->state.first = Component::State::NONE;
    this->state.second.clear();
}

void Component::Sprite::setState(Component::State::State state)
{
    this->state.first = state;
}

const std::pair<Component::State::State, std::vector<Component::Sprite::onChange>>
&Component::Sprite::getState(void) const
{
    return this->state;
}

void Component::Sprite::setAscii(std::pair<std::string, std::pair<int, int>> ascii)
{
    this->ascii = ascii;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_ascii) == false)
        this->state.second.push_back(this->_ascii);
}

std::pair<std::string, std::pair<int, int>> Component::Sprite::getAscii()
{
    return this->ascii;
}

void Component::Sprite::setRect(int x, int size_x, int y, int size_y)
{
    this->rect.first.first = x;
    this->rect.first.second = size_x;
    this->rect.second.first = y;
    this->rect.second.second = size_y;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_rect) == false)
        this->state.second.push_back(this->_rect);
}

std::pair<std::pair<int, int>, std::pair<int, int>> Component::Sprite::getRect()
{
    return this->rect;
}

void Component::Sprite::setScale(std::pair<float, float> scale)
{
    this->scale = scale;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_scale) == false)
        this->state.second.push_back(this->_scale);
}

std::pair<float, float> Component::Sprite::getScale()
{
    return this->scale;
}

void Component::Sprite::setPosition(std::pair<float, float> pos)
{
    this->pos = pos;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_pos) == false)
        this->state.second.push_back(this->_pos);
}

std::pair<float, float> Component::Sprite::getPosition()
{
    return this->pos;
}

void Component::Sprite::setSpritePath(std::string path)
{
    this->path = path;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_path) == false)
        this->state.second.push_back(this->_path);
}

std::string Component::Sprite::getSpritePath(void)
{
    return this->path;
}

Component::Sprite::Sprite(std::string componentName, std::string path, std::pair<float, float> pos, std::pair<float, float> scale, std::pair<std::string, std::pair<int, int>> ascii)
{
    this->componentName = componentName;
    this->type = listComponent::SPRITE;
    this->display = true;
    this->path = path;
    this->pos = pos;
    this->scale = scale;
    this->ascii = ascii;
    this->rect = std::pair<std::pair<int, int>,
    std::pair<int, int>>({-1, -1}, {-1, -1});
    this->state.first = Component::State::ADD;
}

Component::Sprite::~Sprite()
{

}

/*-------------------------TEXT-----------------------*/

void Component::Text::resetState(void)
{
    this->state.first = Component::State::NONE;
    this->state.second.clear();
}

void Component::Text::setState(Component::State::State state)
{
    this->state.first = state;
}

const std::pair<Component::State::State, std::vector<Component::Text::onChange>>
&Component::Text::getState(void) const
{
    return this->state;
}

void Component::Text::setAsciiPos(std::pair<int, int> pos)
{
    this->asciiPos = pos;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_asciiPos) == false)
        this->state.second.push_back(this->_asciiPos);
}

std::pair<int, int> Component::Text::getAsciiPos(void)
{
    return this->asciiPos;
}

void Component::Text::setPosXY(std::pair<float, float> pos)
{
    this->pos = pos;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_pos) == false)
        this->state.second.push_back(this->_pos);
}

std::pair<float, float> Component::Text::getPosXY(void)
{
    return this->pos;
}

void Component::Text::setFontSize(int size)
{
    this->size = size;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_size) == false)
        this->state.second.push_back(this->_size);
}

int Component::Text::getFontSize(void)
{
    return this->size;
}

void Component::Text::setFontPath(std::string path)
{
    this->fontPath = path;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_fontPath) == false)
        this->state.second.push_back(this->_fontPath);
}

std::string Component::Text::getFontPath(void)
{
    return this->fontPath;
}

void Component::Text::setText(std::string str)
{
    this->str = str;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_str) == false)
        this->state.second.push_back(this->_str);
}

std::string Component::Text::getText(void)
{
    return this->str;
}

void Component::Text::setColor(Color::Color color)
{
    this->color = color;

    std::vector<int> c;
    for (size_t i = 0; this->state.second.empty() == false
    && i != this->state.second.size(); c.push_back(this->state.second.at(i)), i += 1);
    if (isOnChangeExist(&c, this->_color) == false)
        this->state.second.push_back(this->_color);
}

Component::Color::Color Component::Text::getColor(void)
{
    return this->color;
}

Component::Text::Text(std::string componentName, std::string str, std::string fontPath,
int size, Color::Color color, std::pair<float, float> pos, std::pair<int, int> asciiPos)
{
    this->componentName = componentName;
    this->type = listComponent::TEXT;
    this->display = true;
    this->str = str;
    this->fontPath = fontPath;
    this->size = size;
    this->color = color;
    this->pos = pos;
    this->asciiPos = asciiPos;
    this->state.first = Component::State::ADD;
}

Component::Text::~Text()
{

}

/*-------------------------Components-----------------------*/


Components *findInComponents(std::vector<Components *> components, std::string name)
{
    for (size_t i = 0; i != components.size(); i += 1) {
        if (components.at(i)->componentName == name)
            return components.at(i);
    }
    return NULL;
}

/*Components *Components::find(std::string componentName)
{
    Components *it;

    it = this;
    if (it == NULL)
        return NULL;
    for (; it != NULL; it = it->next) {
        if (it->componentName == componentName)
            return it;
    }
    return NULL;
}

size_t Components::size()
{
    size_t s = 0;

    for (Components *it = this; it != NULL; it = it->next, s += 1);
    return s;
}

Components *Components::at(size_t index)
{
    Components *it = this;

    for (size_t i = 0; i != index && it != NULL; i += 1)
        it = it->next;
    return it;
}

Components *Components::last()
{
    Components *it = this;
    std::cout << "------------begin---------" << std::endl;
    for (; it->next != NULL; std::cout << it->componentName << std::endl, it = it->next);
    std::cout << "------------end---------" << std::endl;
    return it;
}*/

