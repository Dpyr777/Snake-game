#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include "global_var.hpp"

void Menu()
{
	initscr();
    noecho();
	int row, col;
	getmaxyx(stdscr, row, col);
	curs_set(0);
	const char msg[] = {"Welcome to the game!!!"};

	move(row/2, (col - sizeof(msg) - 1) / 2);
    bool work_color = has_colors();
    if (work_color)
    {
        start_color();
    }

    //init_pair(2, COLOR_RED, COLOR_WHITE);
    attrset(0);
    attron(A_BOLD);
    addstr(msg);
	refresh();
	sleep(3);
    clear();
    short choice = 0;
    const char item[3][7]
    {
        "HIGH",
        "NORMAL",
        "LOW"
    };

    while (true)
    {
        mvaddstr(24, 25, "SPEED:");

        for (int i{1}; i <= 3; ++i)
        {
            move(25 + i, 25);
            if (SPEED == i)
            {
                addch ('>');
            }
            else
            {
                addch(' ');
            }
            printw("%s", item[i - 1]);
        }

        keypad(stdscr, true);
        switch(getch())
        {
            case KEY_UP:
                if (SPEED > 1)
                    --SPEED;
                break;
            case KEY_DOWN:
                if (SPEED < 3)
                    ++SPEED;
                break;
            case '\n':
                endwin();
                return;
        }
    }
}
