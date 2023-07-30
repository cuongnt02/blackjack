#include "game.h"
#include <random>
#include <algorithm>

int main(int argc, char *args[])
{
    if (!init())
    {
        printf("Failed to initialize!");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            // Randomize seed
            srand(time(0));

            // Quit flag
            bool quit = false;

            // Event to handle
            SDL_Event e;

            // Create players
            Player player;
            Player opponent;

            

            // Card rendering demo - remove later
            player.drawFirstHand();
            opponent.drawFirstHand();


            while (!quit)
            {
                // Handles input
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    if (e.type == SDL_KEYDOWN)
                    {
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_UP:
                            break;

                        default:
                            break;
                        }
                    }
                }

                // Game Logic




                // Display to screen

                // Draw table
                SDL_SetRenderDrawColor(gRenderer, 0x61, 0x7A, 0x55, 0xFF);

                // Clear screen
                SDL_RenderClear(gRenderer);

                // Card drawing demo - change later
                drawPlayerCards(player, 1);
                drawPlayerCards(opponent, 0);
                // Draw everything
                SDL_RenderPresent(gRenderer);
            }
            close();
            return 0;
        }
    }
}