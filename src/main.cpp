#include "button.h"
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
        if (!load_media())
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
            player.draw_first_hand();
            opponent.draw_first_hand();


            Button button = Button();
            button.set_text({
                    "Draw",
                    {0x00, 0x00, 0x00, 0xFF}
            });

            button.set_position((SCREEN_WIDTH - BUTTON_WIDTH) / 5, SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2);

            while (!quit)
            {
                // Handles input
                while (SDL_PollEvent(&e))
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                
                    button.handle_event(&e);
                    
                }

                // Game Logic



                // Clear screen
                SDL_RenderClear(renderer);

                // Draw background
                draw_background();

                // Draw cards
                draw_cards(player, 1);
                draw_cards(opponent, 0);


                // Draw buttons
                button.render();

                // Render on screen
                SDL_RenderPresent(renderer);
            }
            close();
        }
    }
    return 0;
}
