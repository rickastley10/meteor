#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

/* ============================================================
   CONFIG
   ============================================================ */
#define WINDOW_WIDTH  400
#define WINDOW_HEIGHT 400

/* ============================================================
   GLOBALS
   ============================================================ */
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Texture* backbuffer = NULL;
static uint32_t* backbuffer_memory = NULL;
static int running = 1;

/* ============================================================
   RENDERER
   ============================================================ */
void clear_screen(uint32_t color)
{
    for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
        backbuffer_memory[i] = color;
}

void draw_rect(int x, int y, int w, int h, uint32_t color)
{
    for (int py = 0; py < h; py++)
    {
        int sy = y + py;
        if (sy < 0 || sy >= WINDOW_HEIGHT) continue;

        for (int px = 0; px < w; px++)
        {
            int sx = x + px;
            if (sx < 0 || sx >= WINDOW_WIDTH) continue;

            backbuffer_memory[sy * WINDOW_WIDTH + sx] = color;
        }
    }
}

/* ============================================================
   BACKBUFFER
   ============================================================ */
int init_backbuffer(void)
{
    backbuffer_memory = (uint32_t*)malloc(WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(uint32_t));
    if (!backbuffer_memory)
    {
        printf("Failed to allocate backbuffer memory\n");
        return 0;
    }

    backbuffer = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WINDOW_WIDTH,
        WINDOW_HEIGHT
    );

    if (!backbuffer)
    {
        printf("Failed to create texture: %s\n", SDL_GetError());
        free(backbuffer_memory);
        return 0;
    }

    return 1;
}

void flip_backbuffer(void)
{
    SDL_UpdateTexture(backbuffer, NULL, backbuffer_memory, WINDOW_WIDTH * sizeof(uint32_t));
    SDL_RenderCopy(renderer, backbuffer, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void cleanup(void)
{
    if (backbuffer_memory)
        free(backbuffer_memory);
    if (backbuffer)
        SDL_DestroyTexture(backbuffer);
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

/* ============================================================
   MAIN LOOP
   ============================================================ */
int main(int argc, char* argv[])
{
    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    /* Create window */
    window = SDL_CreateWindow(
        "Meteor",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    /* Create renderer */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        cleanup();
        return 1;
    }

    /* Initialize backbuffer */
    if (!init_backbuffer())
    {
        cleanup();
        return 1;
    }

    /* ============================================================
       YOUR GAME VARIABLES GO HERE
       ============================================================ */
    

    int playerX = 200;
    int playerY = 300;
    srand(time(NULL));

    int m1x = 200;
    int m1y = 400;
    int m2x = 200;
    int m2y = 400;
    int m3x = 200;
    int m3y = 400;
    int m4x = 200;
    int m4y = 400;
    int m5x = 200;
    int m5y = 400;
    int m6x = 200;
    int m6y = 400;
    int m7x = 200;
    int m7y = 400;
    int m8x = 200;
    int m8y = 400;
    int m9x = 200;
    int m9y = 400;
    int m10x = 200;
    int m10y = 400;


    SDL_Event event;
    const uint8_t* keyboard_state;

    /* ============================================================
       MAIN GAME LOOP
       ============================================================ */
    while (running)
    {
        /* Handle events */
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = 0;
                }
            }
        }

        /* Get keyboard state */
        keyboard_state = SDL_GetKeyboardState(NULL);

        /* ===== INPUT HANDLING ===== */
        
        if (keyboard_state[SDL_SCANCODE_D] || keyboard_state[SDL_SCANCODE_RIGHT])
        {   
            if(playerX<400){
                playerX = playerX + 20;
            }
            
        }
        if (keyboard_state[SDL_SCANCODE_A] || keyboard_state[SDL_SCANCODE_LEFT])
        {
            if(playerX>0){
                playerX = playerX - 20;
            }
            
        }

        m1y=m1y+20;
        m2y=m2y+20;
        m3y=m3y+20;
        m4y=m4y+20;
        m5y=m5y+20;
        m6y=m6y+20;
        m7y=m7y+20;
        m8y=m8y+20;
        m9y=m9y+20;
        m10y=m10y+20;

        if(m1y>= 400){
            m1y =0 + (rand()%(5))*20;
            m1x = (rand()%20+1)*20;
        }
        if(m2y>= 400){
            m2y =0 + (rand()%(5))*20;
            m2x = (rand()%20+1)*20;
        }
        if(m3y>= 400){
            m3y =0 + (rand()%(5))*20;
            m3x = (rand()%20+1)*20;
        }
        if(m4y>= 400){
            m4y =0 + (rand()%(5))*20;
            m4x = (rand()%20+1)*20;
        }
        if(m5y>= 400){
            m5y =0 + (rand()%(5))*20;
            m5x = (rand()%20+1)*20;
        }
        if(m6y>= 400){
            m6y =0 + (rand()%(5))*20;
            m6x = (rand()%20+1)*20;
        }
        if(m7y>= 400){
            m7y =0 + (rand()%(5))*20;
            m7x = (rand()%20+1)*20;
        }
        if(m8y>= 400){
            m8y =0 + (rand()%(5))*20;
            m8x = (rand()%20+1)*20;
        }
        if(m9y>= 400){
            m9y =0 + (rand()%(5))*20;
            m9x = (rand()%20+1)*20;
        }
        if(m10y>= 400){
            m10y =0 + (rand()%(5))*20;
            m10x = (rand()%20+1)*20;
        }



        if(
            (playerX == m1x && playerY == m1y)||
            (playerX == m2x && playerY == m2y)||
            (playerX == m3x && playerY == m3y)||
            (playerX == m4x && playerY == m4y)||
            (playerX == m5x && playerY == m5y)||
            (playerX == m6x && playerY == m6y)||
            (playerX == m7x && playerY == m7y)||
            (playerX == m8x && playerY == m8y)||
            (playerX == m9x && playerY == m9y)||
            (playerX == m10x && playerY == m10y)
        ){

            m1x = 200;
            m1y = 400;
            m2x = 200;
            m2y = 400;
            m3x = 200;
            m3y = 400;
            m4x = 200;
            m4y = 400;
            m5x = 200;
            m5y = 400;
            m6x = 200;
            m6y = 400;
            m7x = 200;
            m7y = 400;
            m8x = 200;
            m8y = 400;
            m9x = 200;
            m9y = 400;
            m10x = 200;
            m10y = 400;

        }
        
        
        /* ===== RENDERING ===== */
        clear_screen(0xFF87CEEB); /* Light blue background */
        
        /* Draw player as red rectangle */
        draw_rect(playerX, playerY, 20, 20, 0xFF000000);

        draw_rect(m1x, m1y, 20, 20, 0xFFFF0000);
        draw_rect(m2x, m2y, 20, 20, 0xFFFF0000);
        draw_rect(m3x, m3y, 20, 20, 0xFFFF0000);
        draw_rect(m4x, m4y, 20, 20, 0xFFFF0000);
        draw_rect(m5x, m5y, 20, 20, 0xFFFF0000);
        draw_rect(m6x, m6y, 20, 20, 0xFFFF0000);
        draw_rect(m7x, m7y, 20, 20, 0xFFFF0000);
        draw_rect(m8x, m8y, 20, 20, 0xFFFF0000);
        draw_rect(m9x, m9y, 20, 20, 0xFFFF0000);
        draw_rect(m10x, m10y, 20, 20, 0xFFFF0000);


        draw_rect(m1x, m1y+20, 20, 20, 0xFFFFA500);
        draw_rect(m2x, m2y+20, 20, 20, 0xFFFFA500);
        draw_rect(m3x, m3y+20, 20, 20, 0xFFFFA500);
        draw_rect(m4x, m4y+20, 20, 20, 0xFFFFA500);
        draw_rect(m5x, m5y+20, 20, 20, 0xFFFFA500);
        draw_rect(m6x, m6y+20, 20, 20, 0xFFFFA500);
        draw_rect(m7x, m7y+20, 20, 20, 0xFFFFA500);
        draw_rect(m8x, m8y+20, 20, 20, 0xFFFFA500);
        draw_rect(m9x, m9y+20, 20, 20, 0xFFFFA500);
        draw_rect(m10x, m10y+20, 20, 20, 0xFFFFA500);

        
        /* Flip the backbuffer to the screen */
        flip_backbuffer();

        /* Frame timing (optional) */
        SDL_Delay(100);
    }

    /* Cleanup and exit */
    cleanup();
    return 0;
}