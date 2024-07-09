#include <functional>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <random>
#include "playing_field.hpp"

static bool SNAKE_DEAD = false;

bool SnakeFood(int &h_x,  int &h_y, int &f_x, int &f_y)
{
    return !(h_x == f_x && h_y == f_y);
}

bool SnakeCrached(const int &h_x, const int &h_y,
                  const int &min_x, const int &max_x,
                  const int &min_y, const int &max_y)
{    
      return (h_x == min_x || h_x == max_x || h_y == min_y || h_y == max_y); 
}



void Plaing_field()
{
    initscr();
    curs_set(0); 
    noecho();


    constexpr int WIDTH = 80;
    constexpr int HEIGHT = 24;
    //getmaxyx(stdscr, HEIGHT, WIDTH);
    constexpr int MIN_X = 0;
    constexpr int MIN_Y = 0;
    unsigned int score = 0;

    
    //int field[HEIGHT][WIDTH] {};

    // starting point
    int head_x = WIDTH / 2;
    int head_y = HEIGHT / 2;

    char button = 'd';
    std::thread tr([&button]() { while (true) { button = getch();}});
    tr.detach();

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLUE);
    init_pair(2, COLOR_RED, COLOR_WHITE);
    attrset(COLOR_PAIR(1));

    std::random_device rd;
    std::mt19937 rnd (rd());
    // std::uniform_int_distribution <int> distrib(1, 10);
    // std::cout << distrib(rnd) << std::endl;
    bool food = false;
    int f_x{};
    int f_y{};



    while (SNAKE_DEAD == false)
    {
 
        clear();
        refresh();
        if (food == false)
        {
            f_x = rnd() % 77 + 1;
            if (f_x % 2 == 1)
                ++f_x;
            f_y = rnd() % 22 + 1;
            food = true;
        }



        for (int i {}; i <= HEIGHT; ++i)
        {
           for (int j {}; j <= WIDTH; ++j)
           {
              if (i == MIN_X || j == MIN_X || i == HEIGHT || j == WIDTH)
                 addch('#');

              else if (head_y == i && head_x == j)
                 addch('@' | A_BOLD);

              else if (i == f_y && j == f_x)
                 addch('$');

              else
                 addch(' ');
           }
           printw("\n");
        }
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        switch (button) {
            case 'q':
                endwin();
                return;
            case 'w':
                if (head_y > MIN_Y)
                {
                    --head_y;
                }
                break;

            case 's':
                if (head_y < HEIGHT)
                {
                    ++head_y; 
                }
                break;

            case 'd':
                if (head_x < WIDTH)
                {
                    ++head_x;
                    ++head_x;
                }
                break;

            case 'a':
                if (head_x > MIN_X)
                {
                    --head_x;
                    --head_x;
                }
                break;
        }

        food = SnakeFood(head_x, head_y, f_x, f_y);
        SNAKE_DEAD = SnakeCrached(head_x, head_y, MIN_X, WIDTH, MIN_Y, HEIGHT);
    
    }
    clear();
    move(25, 25);
    attrset(COLOR_PAIR(2));
    addstr("YOU DEAD!!!");
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    endwin();
    return;
}
