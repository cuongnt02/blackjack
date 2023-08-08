#include "game.h"
#include "SDL_render.h"
#include "player.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
LTexture cardTexture;
SDL_Rect cardSprites[4][13];
bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialize SDL! SDL_Error: %s", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("Black Jack",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Could not initialize window! SDL_Error: %s", SDL_GetError());
            success = false;
        }
        else
        {
            if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
            {
                printf("WARNING: Linear texture filtering not enabled!");
            }

            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Could not create renderer! SDL_Error: %s", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlag = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlag) & imgFlag))
                {
                    printf("Could not initialize SDL_image! SDL_image Error: %s", IMG_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_Quit();
    IMG_Quit();
}

bool loadMedia()
{
    bool success = true;
    if (!cardTexture.loadFromFile("images/spritesheet_poker_assets.png"))
    {
        printf("Failed to load texture.\n");
        success = false;
    }
    else
    {
        for (int suit = 0; suit < 4; suit++)
        {
            int card_pos_y = 12 + 213 * suit;
            for (int number = 0; number < 13; number++)
            {
                SDL_Rect cardRect;
                cardRect.x = 60 + 138 * number;
                cardRect.y = card_pos_y;
                cardRect.h = 202;
                cardRect.w = 130;
                cardSprites[suit][number] = cardRect;
            }
        }
    }
    return success;
}

void drawPlayerCards(Player player, bool isPlayer)
{
    Card *playerHand = player.getHand();
    for (int i = 0; i < player.getNumberOfCards(); i++)
    {
        SDL_Rect *cardSprite = playerHand[i].getSprite();
        if (isPlayer)
            cardTexture.render((SCREEN_WIDTH - cardSprite->w * 5) / 2 + cardSprite->w * i, SCREEN_HEIGHT - cardSprite->h - 30, cardSprite);
        else
            // No need to rotate because it will be ugly
            cardTexture.render((SCREEN_WIDTH - cardSprite->w * 5) / 2 + cardSprite->w * i, 30, cardSprite);
    }
}
