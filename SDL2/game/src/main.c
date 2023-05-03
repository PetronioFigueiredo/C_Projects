#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constants.h"
#include "ball.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int game_is_running = FALSE;
int color = 235;

Ball ball;

int initialize_window(void)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error intializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_BORDERLESS
    );
    if(!window)
    {
        fprintf(stderr, "Error creating SDL Window\n");
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
        fprintf(stderr, "Error creatind Renderer!\n");
        return FALSE;
    }

    return TRUE;
    
}

void process_input()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            game_is_running = FALSE;
            break;
        
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                game_is_running = FALSE;
            }
            break;
    }

}

void update()
{
    fps_controller();
    ball_behavior(&ball);
    printf("BALL x position %d, BALL y posiotn %d\n", (int)ball.x,(int)ball.y);
    system("clear");
}


void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Draw a rectangle
    SDL_Rect ball_rect = {
        (int)ball.y,
        (int)ball.x,
        (int)ball.width,
        (int)ball.height
    };

    SDL_SetRenderDrawColor(renderer,ball.ball_R,ball.ball_G,ball.ball_B, 255);

    SDL_RenderFillRect(renderer, &ball_rect);
    SDL_RenderPresent(renderer);
}

void setup()
{
    ball.x = 15;
    ball.y = 15;
    ball.width = 15;
    ball.height = 15;
    ball.ball_R = 255;
    ball.ball_G = 255;
    ball.ball_B = 255;
}

void destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
int main()
{
    game_is_running = initialize_window();

    setup();
    while(game_is_running)
    {
        process_input();
        update();
        render();
    }
    return 0;
}
