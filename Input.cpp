#include <ncurses.h>
#include "global_var.hpp"

void Input()
{
    int ch; 
    //nodelay(stdscr, true);
    keypad (stdscr, true);
    halfdelay(SPEED);
    ch = getch();
    switch(ch)
    {
        case ERR:
            break;
        case 'w':
            button = UP;
            break;
        case 's':
            button = DOWN;
            break;
        case 'a':
            button = LEFT;
            break;
        case 'd':
            button = RIGHT;
            break;
        case KEY_BACKSPACE:
            break;
        case 'q':
            button = QUIT;
            break;
    }
        
}

    
