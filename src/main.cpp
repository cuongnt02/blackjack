#include "SDL_mutex.h"
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

            

            // Card rendering demo - remove later
            if (player.draw_first_hand() || opponent.draw_first_hand())
                end = true;


            Button button = Button();
            button.set_text({
                    "Draw",
                    {0x00, 0x00, 0x00, 0xFF}
            });
            button.set_position((SCREEN_WIDTH - BUTTON_WIDTH) / 5, SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2);
            button.set_event(ButtonEvent::DRAW);

            Button stand_button = Button();
            stand_button.set_text({
                    "Stand",
                    {0x00, 0x00, 0x00, 0xFF}
                    });
            stand_button.set_position(SCREEN_WIDTH * 4 / 5 - BUTTON_WIDTH, SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2);
            stand_button.set_event(ButtonEvent::STAND);

            Button again_button = Button();
            again_button.set_text({
                    "Play",
                    {0x00, 0x00, 0x00, 0xFF}
                    });
            again_button.set_position(SCREEN_WIDTH * 4 / 5 - BUTTON_WIDTH / 2, SCREEN_HEIGHT / 2 - BUTTON_HEIGHT / 2);
            again_button.set_event(ButtonEvent::RESET);


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
                    stand_button.handle_event(&e);
                    again_button.handle_event(&e);
                    
                }


                // Clear screen
                SDL_RenderClear(renderer);

                // Draw background
                draw_background();

                // Draw cards
                draw_cards(player, 1);
                draw_cards(opponent, 0);


                // Draw buttons
                button.render();
                stand_button.render();
                again_button.render();

                // Render on screen



                // Update
                if (end) {
                    opponent.draw_card_auto();
                    int result = get_result(player, opponent);
                    draw_result(result);
                    button.set_visible(false);
                    stand_button.set_visible(false);
                    again_button.set_visible(true);
                } else {
                    button.set_visible(true);
                    stand_button.set_visible(true);
                    again_button.set_visible(false);
                }

                SDL_RenderPresent(renderer);

            }
            close();
        }
    }
    return 0;
}
