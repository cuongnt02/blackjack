#pragma once
#ifndef GAME_UTILS
#define GAME_UTILS 

#include<SDL.h>
#include<SDL_image.h>
#include "texture.h"
#include "cards.h"
#include "player.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern TTF_Font* font;
extern Texture card_texture;
extern Texture font_texture;
extern SDL_Rect card_sprites[4][13];

bool init();
void close();
bool load_media();
void draw_cards(Player player, bool is_player);
void draw_background();

struct TextSprite {
    std::string text;
    SDL_Color color;
};

#include "button.h"

#endif
