#pragma once
#ifndef BUTTON

#include "SDL.h"
#include "game.h"

const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 100;

enum ButtonEvent {
    DRAW,
    STAND,
    RESET
};

struct ButtonRect {
    SDL_Rect rect;
    SDL_Color color;
};

class Button {

    public: 
        Button();
        ~Button();
        void set_position(int x, int y);
        void set_color(SDL_Color color);
        void set_text(TextSprite text);
        void set_event(ButtonEvent event);
        void handle_event(SDL_Event* e);
        void render();

    private:
        SDL_Point m_position;
        ButtonRect m_container;
        TextSprite m_text;
        ButtonEvent m_event;
};

#endif
