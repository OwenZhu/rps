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

    static inline Move convert_ch_to_move(char ch) { return Move(ch - '0'); }
    static inline std::string convert_move_to_str(Move v)
    {
        switch (v)
        {
        case Scissor:
            return "Scissor";
        case Rock:
            return "Rock";
        case Paper:
            return "Paper";
        default:
            return "[Unknown Move Type]";
        }
    }

private:
    bool single_player_mode;
    int counter;
};

#endif // CONTROLLER_H
