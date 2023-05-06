/*
 * =====================================================================================
 *
 *       Filename:  padles.h
 *
 *    Description: header to declare the behavior for the Paddles 
 *
 *        Version:  1.0
 *        Created:  05/04/2023 02:05:01 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Petronio da Silva Figueiredo
 *   Organization:  NONE
 *
 * =====================================================================================
 */

#ifndef PADDLES_H
#define PADDLES_H
#include "constants.h"

typedef struct {
    float height;
    float width;
    float x;
    float y;
    int collor_R;
    int collor_G;
    int collor_B;

}Paddle;


// function that move paddle (N)*x UP
void paddle_Up(Paddle* self);

// function that move paddle (N)*x DOWN
void paddle_Down(Paddle* self);


#endif
