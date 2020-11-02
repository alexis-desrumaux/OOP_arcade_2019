/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "IGLib.hpp"

namespace SDL
{
    class LComponents {
        public:
        //functions
            LComponents() = default;
            virtual ~LComponents() = default;
            virtual void draw(SDL_Surface *window) = 0;
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
                void draw(SDL_Surface *window);
            private:
            //settings
                SDL_Surface *sprite;
                SDL_Rect position;
                SDL_Rect crop;
                bool isCropped;
        };
        class Text : public LComponents {
            public:
            //functions
                Text(Component::Text *);
                virtual ~Text();
                virtual int update(Component::Text *);
                void draw(SDL_Surface *window);
            private:
            //settings
                SDL_Surface *text;
                TTF_Font *font;
                SDL_Rect position;
        };
        class Audio : public LComponents {
            public:
            //functions
                Audio(Component::Audio *, int &channel);
                ~Audio();
                virtual int update(Component::Audio *);
                void draw(SDL_Surface *window);
            private:
            //settings
                Mix_Chunk *sound;
                int loop;
                int myChannel;
                bool onPlaying;
                bool reload;
                int audioState;
        };
    }
    class SDL : public IGLib {
        public:
            SDL();
            virtual ~SDL();
            virtual std::string display(std::vector<Components *>);
            virtual int initLib(std::vector<Components *>);
            int manageUpdate(std::vector<Components *>);
            int draw(void);
        protected:
        private:
        //settings
            SDL_Surface *window;
            std::vector<LComponents *> lComponents;
            int channel;
            float lastrender;
    };
}

SDL_Color convertColorFromComponent(Component::Color::Color color);
SDL::LComponents *findInLComponents(std::vector<SDL::LComponents *> &lcomponents, std::string name);

#endif /* !SDL_HPP_ */
