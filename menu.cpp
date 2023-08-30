#include <ncurses.h>
#include <iostream>
#include <unistd.h>

void Menu()
{
	initscr();
	int row, col;
	getmaxyx(stdscr, row, col);
	curs_set(0);
	move(row/2, col/2);
	const char msg[] = {"Hello, World!!!"};
	addstr(msg);
	refresh();
	sleep(5);
	endwin();
	return;
}

