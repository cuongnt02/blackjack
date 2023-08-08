#pragma once
#ifndef GAME_UTILS
#define GAME_UTILS 
#include <iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "texture.h"
#include "game.h"
#include "cards.h"
#include "player.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern SDL_Renderer* gRenderer;
extern SDL_Window* gWindow;
extern LTexture cardTexture;
extern SDL_Rect cardSprites[4][13];

bool init();
void close();
bool loadMedia();
void drawPlayerCards(Player player, bool isPlayer);
void drawOpponentCards();

#endif
