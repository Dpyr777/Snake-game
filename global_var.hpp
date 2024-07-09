#pragma once
#ifndef GLOBAL_VAR_HPP
#define GLOBAL_VAR_HPP

enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN, QUIT};
extern Direction button;

extern unsigned int WIDTH; 
extern unsigned int HEIGHT; 
extern unsigned int MIN_X;
extern unsigned int MIN_Y;
extern bool snake_dead;
extern unsigned int head_x, head_y;
extern unsigned int food_x, food_y; 
extern unsigned int tail_x[100];
extern unsigned int tail_y[100];
extern unsigned int score;
extern unsigned int SPEED;

#endif

