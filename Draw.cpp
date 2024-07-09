#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include "global_var.hpp"
#include "Draw.hpp"


void Draw()
{
    initscr();
    noecho();
    curs_set(0);
    clear();
    int offsetx = (COLS - WIDTH) / 2;
    int offsety = (LINES - HEIGHT) / 2;

    bool work_color = has_colors();
    if (work_color)
    {
        start_color();
    }
    init_pair(1, COLOR_GREEN, COLOR_BLUE);
    init_pair(2, COLOR_RED, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(5, COLOR_YELLOW, COLOR_WHITE);

    move(8, 30);
    attrset(COLOR_PAIR(3) | A_BLINK);
    attron(A_BOLD);
    printw(" SNAKE!!! ");

    attrset(COLOR_PAIR(1));
    for (int i {}; i <= HEIGHT; ++i)
    {
       move(10 + i, 20);
       for (int j {}; j <= WIDTH; ++j)
       {
          if (head_y == i && head_x == j)
             addch('@' | A_BOLD | COLOR_PAIR(4));

          else if (i == food_y && j == food_x)
             addch('$' | A_BOLD | COLOR_PAIR(2));

          else
          {
              bool print_tail = true;
              for (unsigned int k = 0; k < score; ++k)
              {
                  if (tail_x[k] == j && tail_y[k] == i)
                  {
                      addch('o' | A_BOLD);
                      print_tail = false;
                  }

              }
              if (print_tail)
                  addch(' ');
          }
       }
       printw("\n");
    }
    //attrset(COLOR_PAIR(5));
    attrset(0);
    attron(A_BOLD);
    move(31, 30);
    printw(" SCORE: %d ", score);
    refresh();
    //std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
