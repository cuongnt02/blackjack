#include "game.h"
#include "button.h"

// Global properties
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
bool end = false;

// Graphics properties
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// Global font
TTF_Font* font = NULL;

// Graphic defined textures
Texture card_texture;
Texture font_texture;
SDL_Rect card_sprites[4][13];

// Global Objects
Player player = Player();
Player opponent = Player();

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
        window = SDL_CreateWindow("Black Jack",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   SCREEN_WIDTH, SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);
        if (window == NULL)
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

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
            {
                printf("Could not create renderer! SDL_Error: %s", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int img_flag = IMG_INIT_PNG;
                if (!(IMG_Init(img_flag) & img_flag))
                {
                    printf("Could not initialize SDL_image! SDL_image Error: %s", IMG_GetError());
                    success = false;
                }

                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}

void close()
{
    // Destroy graphics components
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    TTF_CloseFont(font);
    font = NULL;

    // Quits SDL
    SDL_Quit();
    IMG_Quit();
}

// Load static assets
bool load_media()
{
    bool success = true;
    if (!card_texture.load_from_file("../assets/images/spritesheet_poker_assets.png"))
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
                SDL_Rect card_rect;
                card_rect.x = 60 + 138 * number;
                card_rect.y = card_pos_y;
                card_rect.h = 202;
                card_rect.w = 130;
                if (number > 0)
                    card_sprites[suit][13 - number] = card_rect;
                else card_sprites[suit][number] = card_rect;
            }
        }
    }

    font = TTF_OpenFont("../assets/fonts/lostina.otf", 62);
    if (font == NULL) {
        printf("Failed to load font: Lostina! SDL_ttf error: %s\n", TTF_GetError());
        success = false;
    }

    return success;
}

void draw_cards(Player player, bool is_player)
{
    Card *hand = player.get_hand();
    for (int i = 0; i < player.get_hand_size(); i++)
    {
        SDL_Rect *card_sprite = hand[i].get_sprite();
        if (is_player)
            card_texture.render((SCREEN_WIDTH - card_sprite->w * 5) / 2 + card_sprite->w * i, SCREEN_HEIGHT - card_sprite->h - 30, card_sprite);
        else
            // No need to rotate because it will be ugly
            card_texture.render((SCREEN_WIDTH - card_sprite->w * 5) / 2 + card_sprite->w * i, 30, card_sprite);
    }
}

void draw_background() {
    SDL_SetRenderDrawColor(renderer, 0x61, 0x7A, 0x55, 0xFF);
    SDL_Rect screen_rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &screen_rect);
}

int get_result(Player player, Player opponent) {
    int player_marks = player.get_hand_value();
    int opponent_marks = opponent.get_hand_value();
    int result = -2;

    if (player_marks > 21) result = -1;
    if (opponent_marks > 21) {
        if (result == -1) result = 0;
        else result = 1;
    }
    if (player_marks <= 21 && opponent_marks <= 21) {
        if (player_marks > opponent_marks) result = 1;
        else if (player_marks < opponent_marks) result = -1;
        else result = 0;
    }

    return result;

}

void draw_result(int result_code) {
    std::string result_text;
    if (result_code == 1) result_text = "You win";
    else if (result_code == -1) result_text = "You lose";
    else if (result_code == 0) result_text = "Tie";

    font_texture.load_from_redered_text(result_text, {0x00, 0x00, 0x00, 0xFF});
    font_texture.render(SCREEN_WIDTH / 2 - BUTTON_WIDTH, (SCREEN_HEIGHT - BUTTON_HEIGHT) / 2);
}
