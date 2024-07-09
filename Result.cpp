#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unistd.h>
#include "global_var.hpp"

void Result()
{
    initscr();
    echo();
    curs_set(1);
    std::ifstream file1;
    std::ofstream file2;
    file1.open("result.data",  std::ios_base::in);

    std::string str{};
    std::string name{};
    std::string my_score{};
    unsigned num_score{};
    std::multimap <unsigned, std::string> record_all;
    
    if (file1.is_open())
    {
        clear();
        unsigned i = 10;
        attrset(0);
        attron(A_BOLD);
        move (7, 25);
        printw ("THE BEST TOP 10\n");
        move (8, 20);
        printw ("Name\t      Score\n");
        unsigned num_score{};
        while (std::getline(file1, str))
        {
            std::istringstream record(str);
            record >> name >> my_score;
            num_score = stoi(my_score);
            record_all.emplace(num_score, name);
            move (i++, 20);
            printw("%-10s\t\t%d\n", name.c_str(), num_score); 
        }
        printw("\n\nYour result: %u\n", score);

        file1.close();
        refresh();
        
        if (num_score < score)
        {
            clear();
            printw("\nWhat is your name??? (10 symbols)\n Your result: %u\n", score);

            refresh();
            file2.open("result.data",  std::ios_base::out);
            char my_name[11];
            scanw("%10s", my_name);
            record_all.emplace(score, my_name);
            move (7, 25);
            printw ("THE BEST TOP 10\n");
            move (8, 20);
            printw ("Name\t      Score\n");

            std::multimap <unsigned, std::string>::const_reverse_iterator it_beg = record_all.crbegin(); 
            std::multimap <unsigned, std::string>::const_reverse_iterator it_end = record_all.crend(); 
            i = 10;
            unsigned count_top {};
            for (;it_beg != it_end; ++it_beg)
            {
                if (count_top == 10)
                {
                    break;
                }
                ++count_top;
                move (i++, 20);
                printw("%-10s\t\t%d\n", it_beg->second.c_str(), it_beg->first);
                file2 << it_beg->second << "\t" << it_beg->first << "\n";

            }
            refresh();
            //sleep(6);
            file2.close();
            getch();
        }
        else
        {
            sleep(7);
            std::cin.get();
        }
       
    }
    endwin();
}
