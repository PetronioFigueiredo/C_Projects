/*
 * =====================================================================================
 *
 *       Filename:  ball.c
 *
 *    Description:  declaration of variables and functions of ball.h
 *
 *        Version:  1.0
 *        Created:  04/26/2023 10:38:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Petronio da Silva Figueiredo
 *   Organization:  NONE
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "ball.h"
#include <SDL2/SDL.h>



void ball_behavior(struct Ball* ball)
{
    if(ball->x <=0)
    {
        ball->going_up = FALSE;
    }
    else if(ball->x >=WINDOW_HEIGHT - ball->height)
    {
        ball->going_up = TRUE;
    }
    if(ball->y <=0)
    {
        ball->going_right = TRUE;
        ball->ball_R = 255;
        ball->ball_G = 255;
        ball->ball_B = 255;
    }
    else if(ball->y >=WINDOW_WIDTH - ball->width)
    {
        ball->going_right = FALSE;
        ball->ball_R = 255;
        ball->ball_G = 255;
        ball->ball_B = 255;
    }

    if(ball->going_up)
    {
        ball->x -= BALL_VELOCITY;
    }
    else ball->x += BALL_VELOCITY;
 
    if(ball->going_right)
    {
        ball->y += BALL_VELOCITY;
    }
    else ball->y -= BALL_VELOCITY;
    printf("BALL_VELOCITY: %d\n",BALL_VELOCITY);
    printf("BALL R:%d | G:%d | B:%d\n",ball->ball_R, ball->ball_G, ball->ball_B);
}

void fps_controller(void)
{
    // The code bellow control the flow of FPS's
    int last_frame_time = SDL_GetTicks();
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    if(time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
       SDL_Delay(time_to_wait);
    }

}
