#include <random>
#include "NewFood.hpp"
#include "global_var.hpp"

void NewFood()
{
    bool food = false;
    while (food == false)
    {
        std::random_device rd;
        std::mt19937 rnd(rd());
        food_x = rnd() % (WIDTH - 1) + 1;
        food_y = rnd() % (HEIGHT - 1) + 1;
        food = true;
        for (unsigned int i{}; i < score; ++i)
        {
            if (food_x == tail_x[i] && food_y == tail_y[i])
                food = false;
        }
    }
}
