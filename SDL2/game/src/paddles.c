#include "paddles.h"

void paddle_movement(Paddle* self)
{
    //TODO: config the behavior of the Paddles movements

}
// function that move paddle (N)*x UP
void paddle_Up(Paddle* self)
{
    if(self->x >= 0)
    {
        self->x -= PADDLE_VELOCITY;
    }
    if(self->x < 0)
    {
        self->x = 0;
    }
}

// function that move paddle (N)*x DOWN
void paddle_Down(Paddle* self)
{
    if(self->x <= (WINDOW_HEIGHT - self->height))
    {
        self->x += PADDLE_VELOCITY;
    }
    if(self->x > WINDOW_HEIGHT - self->height)
    {
        self->x = WINDOW_HEIGHT - self->height;
    }
}
