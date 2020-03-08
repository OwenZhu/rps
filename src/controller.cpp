#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "controller.h"

const std::array<std::string, 3> Controller::move_type =
    {"scissor", "rock", "paper"};

void Controller::start()
{
    std::cout << "Press any key to start...";
    std::cin.get();

    std::cout << "Select game mode... ｜ 0 single-player mode  ｜ 1 multi-player mode: ";
    char mode;
    std::cin.get(mode);

    switch (mode)
    {
    case '1':
        single_player_mode = false;
        std::cout << "Are you kidding me???" << std::endl;
        break;
    default:
        single_player_mode = true;
        break;
    }
}

Move Controller::parse_input(char ch)
{
    switch (ch)
    {
    case '0':
        return scissor;
    case '1':
        return rock;
    default:
        return paper;
    }
}

int Controller::step(Move move_1, Move move_2)
{
    int tmp = 1;
    if (move_1 - move_2 == 1 || move_1 - move_2 == -2)
    {
        tmp = 2;
    }

    std::cout << "Player 1: " << move_type[move_1] << std::endl;
    std::cout << "Player 2: " << move_type[move_2] << std::endl;

    switch (tmp)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 3;
    }
}

void Controller::loop()
{
    start();
    if (single_player_mode)
    {
        for (;; counter++)
        {
            int game_status;
            char action, ai_action;

            srand(time(NULL));
            ai_action = char(rand() % 3 + 48);

            std::cout << "---- ROUND " << counter << "----" << std::endl;
            std::cout << "Please input a number from 0 to 2: ";
            std::cin >> action;

            game_status = step(parse_input(action),
                               parse_input(ai_action));

            if (game_status == 1)
            {
                std::cout << "YOU LOSE :(" << std::endl;
                continue;
            }
            else
            {
                std::cout << "YOU WIN :D" << std::endl;
                break;
            }
            std::cout << "---------------------------" << std::endl;
        }
    }
}
