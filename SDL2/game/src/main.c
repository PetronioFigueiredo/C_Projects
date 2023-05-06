#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


#include "constants.h"
#include "ball.h"
#include "paddles.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Renderer* renderer2 = NULL;
int game_is_running = FALSE;
int color = 235;

// BALL OBJECT
Ball ball;

// PADDLE OBJECTS

Paddle paddle1;
Paddle paddle2;


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
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    game_is_running = FALSE;
                    break;

                case SDLK_w:
                    //TODO: handle the movement of the right paddle up.
                    paddle_Up(&paddle1);
                    break;

                case SDLK_s:
                    //TODO: hanle the movement of the right paddle down.
                    paddle_Down(&paddle1);
                    break;
                case SDLK_u:
                    //TODO: handle the movement of the right paddle up.
                    paddle_Up(&paddle2);
                    break;

                case SDLK_j:
                    //TODO: hanle the movement of the right paddle down.
                    paddle_Down(&paddle2);
                    break;
            }
           
            break;
    }

}

void update()
{
    fps_controller();
    ball_behavior(&ball);
    printf("BALL x position %d, BALL y posiotn %d\n", (int)ball.x,(int)ball.y);
    printf("PAddle1 X_pos: %.2f\n", paddle1.x);
    system("clear");
}


void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderClear(renderer2);
    
    // Draw a rectangle
    SDL_Rect ball_rect = {
        (int)ball.y,
        (int)ball.x,
        (int)ball.width,
        (int)ball.height
    };

    // Draw paddle1
    SDL_Rect paddle1_rect ={
        (int)paddle1.y,
        (int)paddle1.x,
        (int)paddle1.width,
        (int)paddle1.height
    };
    
    // Draw paddle2
    SDL_Rect paddle2_rect ={
        (int)paddle2.y,
        (int)paddle2.x,
        (int)paddle2.width,
        (int)paddle2.height
    };
    
    // SDL set render draw for objects
    SDL_SetRenderDrawColor(renderer,ball.ball_R,ball.ball_G,ball.ball_B, 255);
    SDL_RenderFillRect(renderer, &ball_rect);

    SDL_SetRenderDrawColor(renderer,paddle1.collor_R,paddle1.collor_G,paddle1.collor_B, 255);
    SDL_RenderFillRect(renderer, &paddle1_rect);

    SDL_SetRenderDrawColor(renderer,paddle2.collor_R,paddle2.collor_G,paddle2.collor_B,255);
    SDL_RenderFillRect(renderer, &paddle2_rect);

    SDL_RenderPresent(renderer);

    if (SDL_HasIntersection(&ball_rect, &paddle1_rect))
    {
        ball.going_right = TRUE;
        ball.ball_R = 0;
        ball.ball_G = 0;
        ball.ball_B = 255;

    }
    else if (SDL_HasIntersection(&ball_rect, &paddle2_rect))
    {
        ball.going_right = FALSE;
        ball.ball_R = 255;
        ball.ball_G = 0;
        ball.ball_B = 0;

    }

    //SDL_RenderFillRect(renderer, &paddle2_rect);
}

void setup()
{
    // Ball setup
    ball.x = 15;
    ball.y = 15;
    ball.width = 15;
    ball.height = 15;
    ball.ball_R = 255;
    ball.ball_G = 255;
    ball.ball_B = 255;

    // Paddle 1 setup
    paddle1.x = (WINDOW_HEIGHT / 2) - (paddle1.height / 2);
    paddle1.y = 20;
    paddle1.width = 20;
    paddle1.height = WINDOW_HEIGHT / 5;
    paddle1.collor_R = 0;
    paddle1.collor_G = 0;
    paddle1.collor_B = 255;

    // Paddle 2 setup
    paddle2.x = (WINDOW_HEIGHT / 2) - (paddle2.height / 2);
    paddle2.y = (WINDOW_WIDTH - (paddle2.width + 40));
    paddle2.width = 20;
    paddle2.height = WINDOW_HEIGHT / 5;
    paddle2.collor_R = 255;
    paddle2.collor_G = 0;
    paddle2.collor_B = 0;
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
