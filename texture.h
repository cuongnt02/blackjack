#pragma once
#ifndef SDL_TEXTURE
#define SDL_TEXTURE
#include<SDL.h>
#include<iostream>


class LTexture
{
    public:
        LTexture();
        ~LTexture();
        bool loadFromFile(std::string path);
        void free();
        void render(int x, int y, SDL_Rect* clip = NULL, double angle=0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
        int getWidth();
        int getHeight();

    private:
        int mWidth;
        int mHeight;
        SDL_Texture* mTexture;
};

#endif
