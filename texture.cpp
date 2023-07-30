#include<SDL.h>
#include<SDL_image.h>
#include"game.h"
#include"texture.h"


LTexture::LTexture()
{
    mWidth = 0;
    mHeight = 0;
    mTexture = NULL;
}

LTexture::~LTexture()
{
    free();
}

int LTexture::getHeight()
{
    return mHeight;
}

int LTexture::getWidth()
{
    return mWidth;
}

bool LTexture::loadFromFile(std::string path)
{
    free();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == NULL)
    {
        printf("Could not load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Could not create texture %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
        
    }

    mTexture = newTexture;
    return mTexture != NULL;

}

void LTexture::free()
{
    if (mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = { x, y, mWidth, mHeight};

    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}