/*
 * =====================================================================================
 *
 *       Filename:  ball.h
 *
 *    Description:  Definitions of funtions and variables of ball.c 
 *                including behavior and another troblesome shit
 *
 *        Version:  1.0
 *        Created:  04/26/2023 10:38:51 PM
 *       Revision:  Petronio da Silva Figueiredo
 *       Compiler:  gcc
 *
 *         Author:  Petronio da SIlva Figueiredo
 *   Organization:  NONE
 *
 * =====================================================================================
 */

#include "constants.h"
#include <stdio.h>

#ifndef BALL_H
#define BALL_H




void color_looper(int* color);

// This function controls the flux of FPS stabelising the veloity in the game.
void fps_controller(void);
    // Struct responsable for the elements for the ball object
typedef struct Ball
{
    float x;
    float y;
    float width;
    float height;
    int going_right;
    int going_up;
    int ball_R;
    int ball_G;
    int ball_B;

}Ball;

void ball_behavior(struct Ball* ball);

#endif
