#pragma once
#ifndef GAME_UTILS
#define GAME_UTILS 

#include<SDL.h>
#include<SDL_image.h>
#include "texture.h"
#include "cards.h"
#include "player.h"
#include "button.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern TTF_Font* font;
extern Texture card_texture;
extern Texture font_texture;
extern SDL_Rect card_sprites[4][13];
extern Player player;
extern Player opponent;
extern bool end;

bool init();
void close();
bool load_media();
void draw_cards(Player player, bool is_player);
void draw_background();
int get_result(Player player, Player opponent);
void draw_result(int result_code);
void game_reset();




#endif
