#include <iostream>
#include <ncurses.h>
#include "global_var.hpp"
#include "NewFood.hpp"

void Logic()
{
    unsigned int prev_x = tail_x[0];
    unsigned int prev_y = tail_y[0];
    unsigned int prev_x2, prev_y2;
    tail_x[0] = head_x;
    tail_y[0] = head_y;


    switch(button)
    {
        case UP:
            --head_y;
            break;
        case DOWN:
            ++head_y;
            break;
        case LEFT:
            --head_x;
            break;
        case RIGHT:
            ++head_x;
            break;
        case STOP:
            break;
        case QUIT:
            snake_dead = true;
            endwin();
            break;
    }
    if (head_x > WIDTH || head_x < MIN_X || head_y > HEIGHT || head_y < MIN_Y)
    {
       snake_dead = true; 
       endwin();
    }

    for (int i = 0; i < score; i++)
    {
        if (head_x == tail_x[i] && head_y == tail_y[i])
        {
            snake_dead = true;
            endwin();
        }
    }
    if (head_x == food_x && head_y == food_y)
    {
        ++score;
        NewFood();
    }

    for (int i = 1; i < score; ++i)
    {
        prev_x2 = tail_x[i];
        prev_y2 = tail_y[i];
        tail_x[i] = prev_x;
        tail_y[i] = prev_y;
        prev_x = prev_x2;
        prev_y = prev_y2;
    }
    
}
 
