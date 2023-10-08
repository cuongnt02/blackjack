#include "button.h"
#include "SDL_events.h"
#include "SDL_mouse.h"
#include "SDL_render.h"
#include "game.h"

Button::Button() {

    m_position = {0, 0};
    m_container = {
        {0, 0, BUTTON_WIDTH, BUTTON_HEIGHT},
        {0xFF, 0xFF, 0xFF, 0xFF}
    };
    m_text = {
        "",
        {0x00, 0x00, 0x00, 0xFF}
    };

}

Button::~Button() {

}

void Button::set_position(int x, int y) {

    m_position.x = x;
    m_position.y = y;   
    m_container.rect.x = x;
    m_container.rect.y = y;

}

void Button::set_color(SDL_Color color) {

    m_container.color.r = color.r;
    m_container.color.g = color.g;
    m_container.color.b = color.b;
    m_container.color.a = color.a;

}

void Button::set_text(TextSprite text) {
    m_text.text = text.text; 
    m_text.color = text.color;
}

void Button::handle_event(SDL_Event* e) {
    
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP ) {

        int x, y;
        SDL_GetMouseState(&x, &y);

        bool inside = true;
        if (x < m_position.x) {
            inside = false;
        }
        else if (x > m_position.x + BUTTON_WIDTH) {
            inside = false;
        }
        else if (y < m_position.y) {
            inside = false;
        }
        else if (y > m_position.y + BUTTON_HEIGHT) {
            inside = false;
        }

        if (!inside) {
            set_color({0xFF, 0xFF, 0xFF, 0xFF});
        }
        else {

            switch ( e-> type) {

                case SDL_MOUSEMOTION:
                    set_color({0x00, 0xFF, 0x00, 0xFF});
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    
                    switch (m_event) {
                        case DRAW:
                            player.draw_card(&deck);
                            if (player.get_hand_value() > 21) {
                                end = true;
                            }
                            break;
                        case STAND:
                            end = true;
                            break;
                        case RESET:
                            game_reset();
                            break;
                        default:
                            break;

                    }

            }

        }
    }

}

void Button::render() {
    if (m_visible) {
        SDL_SetRenderDrawColor(renderer,
                m_container.color.r,
                m_container.color.g,
                m_container.color.b,
                m_container.color.a);
        SDL_RenderFillRect(renderer, &m_container.rect);
        font_texture.load_from_redered_text(m_text.text, m_text.color);
        font_texture.render(m_position.x + (BUTTON_WIDTH - font_texture.get_width()) / 2
                , m_position.y + (BUTTON_HEIGHT - font_texture.get_height()) / 2);
    }
}

void Button::set_event(ButtonEvent evt) {
    m_event = evt;
}

void Button::set_visible(bool visible) {
    m_visible = visible;
}
