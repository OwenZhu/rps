#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <array>
#include <string>

class Controller
{
    enum Move
    {
        Scissor,
        Rock,
        Paper
    };

    enum GameState
    {
        Lose,
        Win,
        Tie
    };

public:
    Controller() : single_player_mode(true), counter(0) {}
    void start();
    void loop();

    static GameState step(Move, Move);
    static Move parse_input(char ch) { return Move(ch - '0'); }

private:
    bool single_player_mode;
    int counter;

    static const std::array<std::string, 3> move_type;
};

#endif // CONTROLLER_H
