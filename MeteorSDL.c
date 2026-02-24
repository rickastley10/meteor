#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

void draw_rect(SDL_Surface *surface, int x, int y, int w, int h, Uint32 color) {
    SDL_Rect rect = {x, y, w, h};
    SDL_FillRect(surface, &rect, color);
}

int main(int argc, char* argv[]) {
    SDL_Window *window;
    SDL_Surface *surface;
    SDL_Event event;
    int running = 1;
    
    srand(time(NULL));
    
    int px = 200, py = 300;
    int m1x = (rand()%20+1)*20, m1y = (rand()%10+1)*20;
    int m2x = (rand()%20+1)*20, m2y = (rand()%10+1)*20;
    int m3x = (rand()%20+1)*20, m3y = (rand()%10+1)*20;
    int m4x = (rand()%20+1)*20, m4y = (rand()%10+1)*20;
    int m5x = (rand()%20+1)*20, m5y = (rand()%10+1)*20;
    int m6x = (rand()%20+1)*20, m6y = (rand()%10+1)*20;
    int m7x = (rand()%20+1)*20, m7y = (rand()%10+1)*20;
    int m8x = (rand()%20+1)*20, m8y = (rand()%10+1)*20;
    int m9x = (rand()%20+1)*20, m9y = (rand()%10+1)*20;
    int m10x = (rand()%20+1)*20, m10y = (rand()%10+1)*20;
    int w = 20, h = 20;
    int score = 0, count = 0;
    
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Meteor", SDL_WINDOWPOS_UNDEFINED, 
                              SDL_WINDOWPOS_UNDEFINED, 
                              WINDOW_WIDTH, WINDOW_HEIGHT, 
                              SDL_WINDOW_SHOWN);
    surface = SDL_GetWindowSurface(window);
    
    int touch_x = 0;
    int touch_active = 0;
    
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_FINGERDOWN) {
                touch_x = event.tfinger.x * WINDOW_WIDTH;
                touch_active = 1;
            }
            if (event.type == SDL_FINGERUP) {
                touch_active = 0;
            }
            if (event.type == SDL_FINGERMOTION && touch_active) {
                touch_x = event.tfinger.x * WINDOW_WIDTH;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT) {
                    if (px > 0) px -= w;
                }
                if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT) {
                    if (px < 380) px += w;
                }
            }
        }
        
        if (touch_active) {
            if (touch_x < px && px > 0) px -= w;
            if (touch_x > px + w && px < 380) px += w;
        }
        
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 135, 206, 235));
        
        draw_rect(surface, px, py, w, h, SDL_MapRGB(surface->format, 0, 0, 0));
        
        draw_rect(surface, m1x, m1y, w, h, SDL_MapRGB(surface->format, 255, 165, 0));
        draw_rect(surface, m1x, m1y - h, w, h, SDL_MapRGB(surface->format, 255, 0, 0));
        
        m1y = m1y + h; if(m1y == 400 + h) { m1y = 0; m1x = (rand()%20+1)*20; count++; }
        m2y = m2y + h; if(m2y == 400 + h) { m2y = 0; m2x = (rand()%20+1)*20; count++; }
        m3y = m3y + h; if(m3y == 400 + h) { m3y = 0; m3x = (rand()%20+1)*20; count++; }
        m4y = m4y + h; if(m4y == 400 + h) { m4y = 0; m4x = (rand()%20+1)*20; count++; }
        m5y = m5y + h; if(m5y == 400 + h) { m5y = 0; m5x = (rand()%20+1)*20; count++; }
        m6y = m6y + h; if(m6y == 400 + h) { m6y = 0; m6x = (rand()%20+1)*20; count++; }
        m7y = m7y + h; if(m7y == 400 + h) { m7y = 0; m7x = (rand()%20+1)*20; count++; }
        m8y = m8y + h; if(m8y == 400 + h) { m8y = 0; m8x = (rand()%20+1)*20; count++; }
        m9y = m9y + h; if(m9y == 400 + h) { m9y = 0; m9x = (rand()%20+1)*20; count++; }
        m10y = m10y + h; if(m10y == 400 + h) { m10y = 0; m10x = (rand()%20+1)*20; count++; }
        
        if(count >= 10) { score++; count = 0; }
        
        if((px == m1x && py == m1y) || (px == m2x && py == m2y) ||
           (px == m3x && py == m3y) || (px == m4x && py == m4y) ||
           (px == m5x && py == m5y) || (px == m6x && py == m6y) ||
           (px == m7x && py == m7y) || (px == m8x && py == m8y) ||
           (px == m9x && py == m9y) || (px == m10x && py == m10y)) {
            m1x = (rand()%20+1)*20; m1y = (rand()%10+1)*20;
            m2x = (rand()%20+1)*20; m2y = (rand()%10+1)*20;
            m3x = (rand()%20+1)*20; m3y = (rand()%10+1)*20;
            m4x = (rand()%20+1)*20; m4y = (rand()%10+1)*20;
            m5x = (rand()%20+1)*20; m5y = (rand()%10+1)*20;
            m6x = (rand()%20+1)*20; m6y = (rand()%10+1)*20;
            m7x = (rand()%20+1)*20; m7y = (rand()%10+1)*20;
            m8x = (rand()%20+1)*20; m8y = (rand()%10+1)*20;
            m9x = (rand()%20+1)*20; m9y = (rand()%10+1)*20;
            m10x = (rand()%20+1)*20; m10y = (rand()%10+1)*20;
            score = 0;
        }
        
        char buf[32];
        sprintf(buf, "Score: %d", score);
        
        SDL_UpdateWindowSurface(window);
        SDL_Delay(100);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
