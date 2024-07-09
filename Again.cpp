#include <ncurses.h>
#include "Again.hpp"
#include "global_var.hpp"

bool Again()
{
    char key;
    nodelay(stdscr, FALSE);
    move(5, 10);
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    //attrset(COLOR_PAIR(1));
    attrset(0);
    attron(A_BOLD);

    if (button == QUIT)
    {
        printw("YOU SCORE: %d\n", score); 
        //attrset(COLOR_PAIR(2));
        addstr("Do you want to quit the game? y/n: ");
        do {
        key = getch();
        if (key == 'y' || key == 'Y' || key == 'q' || key == 'Q')
        {
            clear();
            endwin();
            return false;
        }
        else if (key == 'n' || key == 'N')
        {
            clear();
            endwin();
            return true;
        }
        } while (true);
    }
    attrset(COLOR_PAIR(3) | A_BOLD);
    addstr("YOU DEAD!!!");
    attrset(0);
    attron(A_BOLD);
    //attrset(COLOR_PAIR(2) | A_BOLD);
    printw("\nYOU SCORE: %d\n", score); 
    addstr("Would you like to try again? y/n: ");
    do {
    key = getch();
    if (key == 'y' || key == 'Y')
    {
        clear();
        endwin();
        return true;
    }
    else if (key == 'n' || key == 'N')
    {
        clear();
        endwin();
        return false;
    }
    } while (true);
}

