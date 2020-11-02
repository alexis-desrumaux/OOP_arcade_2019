/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sfml_c
*/

#include "SFML.hpp"

/*--------------------------------AUDIO-----------------------------------*/

void SFML::LComponent::Audio::draw(sf::RenderWindow *)
{
    if (this->audioState == Component::AudioState::RELOAD && this->reload == true) {
        this->sound.play();
        this->reload = false;
        this->onPlaying = true;
    }
    if (this->onPlaying == false && this->audioState == Component::AudioState::PLAY && this->display == true) {
        this->sound.play();
        this->onPlaying = true;
    }
    if (this->audioState == Component::AudioState::STOP) {
        this->sound.stop();
        this->onPlaying = false;
    }
    if (this->audioState == Component::AudioState::PAUSE  || this->display == false) {
        this->sound.pause();
        this->onPlaying = false;
    }
}

int SFML::LComponent::Audio::update(Component::Audio *audio)
{
    std::pair<Component::State::State, std::vector<Component::Audio::onChange>> state = audio->getState();
    Component::AudioState::AudioState audioState = audio->getAudioState();

    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i))
        {
        case Component::Audio::onChange::_path:
        {
            this->sound.stop();
            this->buffer.loadFromFile(audio->getAudioPath());
            this->sound.setBuffer(this->buffer);
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
            this->sound.setLoop(audio->isLoop());
            break;
        default:
            break;
        }
    }
    return 0;
}

SFML::LComponent::Audio::Audio(Component::Audio *audio)
{
    this->componentName = audio->componentName;
    this->display = audio->display;
    this->buffer.loadFromFile(audio->getAudioPath());
    this->sound.setBuffer(this->buffer);
    this->sound.setLoop(audio->isLoop());
    this->audioState = audio->getAudioState();
}

SFML::LComponent::Audio::~Audio()
{
    this->sound.stop();
}

/*--------------------------------SPRITE-----------------------------------*/


void SFML::LComponent::Sprite::draw(sf::RenderWindow *window)
{
    window = window;
    if (this->display == true)
        window->draw(this->sprite);
}

int SFML::LComponent::Sprite::update(Component::Sprite *sprite)
{
    std::pair<Component::State::State, std::vector<Component::Sprite::onChange>> state = sprite->getState();

    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i))
        {
        case Component::Sprite::onChange::_path:
        {
            this->texture.loadFromFile(sprite->getSpritePath());
            this->texture.setSmooth(true);
            this->sprite.setTexture(this->texture);
            break;
        }
        case Component::Sprite::onChange::_pos:
        {
            std::pair<float, float> xy = sprite->getPosition();
            this->sprite.setPosition(sf::Vector2f(xy.first, xy.second));
            break;
        }
        case Component::Sprite::onChange::_rect:
        {
            std::pair<std::pair<int, int>, std::pair<int, int>> rect = sprite->getRect();
            sf::IntRect sfRect;

            if (rect.first.first != -1 && rect.first.second != -1 && rect.second.first != -1 &&
            rect.second.second != -1) {
                sfRect.left = rect.first.first;
                sfRect.width = rect.first.second;
                sfRect.top = rect.second.first;
                sfRect.height = rect.second.second;
                this->sprite.setTextureRect(sfRect);
            }
            break;
        }
        case Component::Sprite::onChange::_scale:
        {
            std::pair<float, float> scale = sprite->getScale();
            this->sprite.setScale(sf::Vector2f(scale.first, scale.second));
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

SFML::LComponent::Sprite::Sprite(Component::Sprite *sprite)
{
    std::pair<float, float> xy = sprite->getPosition();
    std::pair<float, float> scale = sprite->getScale();
    std::pair<std::pair<int, int>, std::pair<int, int>> rect = sprite->getRect();
    sf::IntRect sfRect;

    this->texture.loadFromFile(sprite->getSpritePath());
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(sf::Vector2f(xy.first, xy.second));
    this->sprite.setScale(sf::Vector2f(scale.first, scale.second));
    if (rect.first.first != -1 && rect.first.second != -1 && rect.second.first != -1 &&
    rect.second.second != -1) {
        sfRect.left = rect.first.first;
        sfRect.width = rect.first.second;
        sfRect.top = rect.second.first;
        sfRect.height = rect.second.second;
        this->sprite.setTextureRect(sfRect);
    }
    this->componentName = sprite->componentName;
    this->display = sprite->display;
}

SFML::LComponent::Sprite::~Sprite()
{
    
}

/*--------------------------------TEXT-----------------------------------*/

void SFML::LComponent::Text::draw(sf::RenderWindow *window)
{
    if (this->display == true) {
        window->draw(*this->text);
    }
}

int SFML::LComponent::Text::update(Component::Text *text)
{
    std::pair<Component::State::State, std::vector<Component::Text::onChange>> state = text->getState();
    
    for (size_t i = 0; i != state.second.size(); i += 1) {
        switch (state.second.at(i)) {
            case Component::Text::onChange::_color:
            {
                sf::Color color = convertColorFromComponent(text->getColor());
                this->text->setFillColor(color);
                break;
            }
            case Component::Text::onChange::_fontPath:
            {
                this->font->loadFromFile(text->getFontPath());
                this->text->setFont(*this->font);
                break;
            }
            case Component::Text::onChange::_pos:
            {
                std::pair<float, float> xy = text->getPosXY();
                this->text->setPosition(sf::Vector2f(xy.first, xy.second));
                break;
            }
            case Component::Text::onChange::_size:
            {
                this->text->setCharacterSize(text->getFontSize());
                break;
            }
            case Component::Text::onChange::_str:
            {
                this->text->setString(text->getText());
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

SFML::LComponent::Text::Text(Component::Text *text)
{
    sf::Color color;
    this->font = new sf::Font();
    this->text = new sf::Text();
    this->font->loadFromFile(text->getFontPath());
    this->text->setFont(*font);
    this->text->setString(sf::String(text->getText()));
    std::pair<float, float> xy = text->getPosXY();
    this->text->setPosition(sf::Vector2f(xy.first, xy.second));
    this->text->setCharacterSize(text->getFontSize());
    color = convertColorFromComponent(text->getColor());
    this->text->setFillColor(color);
    this->componentName = text->componentName;
    this->display = text->display;
}

SFML::LComponent::Text::~Text()
{
    delete this->text;
    delete this->font;
}

/*---------------------------LComponents-----------------------------------*/

SFML::LComponents *findInLComponents(std::vector<SFML::LComponents *> &lcomponents, std::string name)
{
    for (size_t i = 0; i != lcomponents.size(); i += 1) {
        if (lcomponents.at(i)->componentName == name)
            return lcomponents.at(i);
    }
    return NULL;
}

