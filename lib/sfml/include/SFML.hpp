/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include "IGLib.hpp"



namespace SFML
{
    class LComponents {
        public:
        //functions
            LComponents() = default;
            virtual ~LComponents() = default;
            virtual void draw(sf::RenderWindow *) = 0;
        //settings
            std::string componentName;
            bool display;
    };
    namespace LComponent {
        class Sprite : public LComponents {
            public:
            //functions
                Sprite(Component::Sprite *);
                virtual ~Sprite();
                int update(Component::Sprite *);
                void draw(sf::RenderWindow *);
            private:
            //settings
                sf::Sprite sprite;
                sf::Texture texture;
        };
        class Text : public LComponents {
            public:
            //functions
                Text(Component::Text *);
                virtual ~Text();
                virtual int update(Component::Text *);
                void draw(sf::RenderWindow *);
            private:
            //settings
                sf::Text *text;
                sf::Font *font;
        };
        class Audio : public LComponents {
            public:
            //functions
                Audio(Component::Audio *);
                ~Audio();
                virtual int update(Component::Audio *);
                void draw(sf::RenderWindow *);
            private:
            //settings
                sf::SoundBuffer buffer;
                sf::Sound sound;
                bool onPlaying;
                bool reload;
                int audioState;
        };
    }
    class SFML : public IGLib {
        public:
            SFML();
            virtual ~SFML();
            virtual std::string display(std::vector<Components *>);
            virtual int initLib(std::vector<Components *>);
            virtual int getEventKey();
            virtual void setEventKey(int);
            int manageEventOnKeyboard(sf::Event event);
            int manageUpdate(std::vector<Components *>);
            int draw(void);
        protected:
        private:
            //settings
                sf::RenderWindow *window;
                sf::CircleShape shape;
                int eventKey;
                std::vector<LComponents *> lComponents;
    };
}

sf::Color convertColorFromComponent(Component::Color::Color color);
std::string SFKeyToString(unsigned int keycode);
SFML::LComponents *findInLComponents(std::vector<SFML::LComponents *> &lcomponents, std::string name);

#endif /* !SFML_HPP_ */
