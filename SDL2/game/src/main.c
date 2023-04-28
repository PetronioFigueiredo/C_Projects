#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "constants.h"
#include "ball.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int game_is_running = FALSE;
int color = 235;

int last_frame_time = 0;
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
    /* 
    // Calculate how muich we have to wair until we reach the target frame time
    int time_to_wait = FRAME_TERGET_TIME - (SDL_GetTicks() - last_frame_time);

    // Only delay if we are too fast to update this frame
    if(time_to_wait > 0 && time_to_wait <= FRAME_TERGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }
    */
    
    // Get a delta time factor converted to seconds to be used to update my objects 
    //last_frame_time = SDL_GetTicks();

    //color_looper(&color);
    ball_behavior(&ball);
    printf("BALL x position %f, BALL y posiotn %f\n", ball.x,ball.y);
    system("clear");
    //ball.x += 70 *  24;
    //ball.y += 50 * 24;
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

    SDL_SetRenderDrawColor(renderer,color,color,color, 255);

    SDL_RenderFillRect(renderer, &ball_rect);
    SDL_RenderPresent(renderer);
}

void setup()
{
    ball.x = 0;
    ball.y = 0;
    ball.width = 15;
    ball.height = 15;
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
