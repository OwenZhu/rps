#include "controller.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

void Controller::start()
{
    std::cout << "Press any key to start...";
    std::cin.get();

    std::cout << "Select game mode... ｜ "
                 "0 single-player mode  ｜ "
                 "1 multi-player mode: ";
    char mode;
    std::cin.get(mode);
    single_player_mode = !bool(mode - '0');

    if (!single_player_mode)
    {
        std::cout << "Are you kidding me???" << std::endl;
    }
}

Controller::GameState Controller::step(Move move_1, Move move_2)
{
    std::cout << "Player 1: " << convert_move_to_str(move_1) << std::endl;
    std::cout << "Player 2: " << convert_move_to_str(move_2) << std::endl;

    switch (move_1 - move_2 % 3)
    {
    case 0:
        return Tie;
    case 1:
        return Win;
    default:
        return Lose;
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

            std::cout << "---- ROUND " << counter << " ----" << std::endl;
            std::cout << "Please input a number from 0 to 2: ";
            std::cin >> action;

            game_status = step(convert_ch_to_move(action),
                               convert_ch_to_move(ai_action));

            if (game_status == Win)
            {
                std::cout << "YOU WIN :D" << std::endl;
                std::cout << "-----------------" << std::endl;
                break;
            }
            else if (game_status == Tie)
            {
                std::cout << "TIE :|" << std::endl;
                continue;
            }
            else
            {
                std::cout << "YOU LOSE :(" << std::endl;
                continue;
            }
        }
    }
}
