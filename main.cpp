#include <iostream>
#include <string>
#include <ncurses.h>
#include <chrono>
#include <random>
#include "main.hpp"
//#include "playing_field.hpp"

unsigned int WIDTH = 30;
unsigned int HEIGHT = 20;
unsigned int MIN_X = 0;
unsigned int MIN_Y = 0;
enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN, QUIT};
Direction button;
bool snake_dead;
unsigned int head_x, head_y;
unsigned int food_x, food_y; 
unsigned int n_tail;
unsigned int tail_x[100];
unsigned int tail_y[100];
unsigned int SPEED = 1;
unsigned int score;
bool again = true;


void Setup()
{
    snake_dead = false;
    button = STOP;
    head_x = WIDTH / 2 - 1; 
    head_y = HEIGHT / 2 - 1;
    n_tail = 0;
    score = 0;
    NewFood();
}
    

int main()
{
AGAIN:
	Menu();
    Setup();
    while(snake_dead == false)
    {
        Draw();
        Input();
        Logic();
    }
    again = Again();
    if (again == true)
    {
        goto AGAIN;
    }
    Result();
    //Plaing_field();
	return 0;
}
