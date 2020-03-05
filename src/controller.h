#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <array>
#include <string>

enum Move
{
    scissor,
    rock,
    paper
};

class Controller
{
public:
    Controller() : single_player_mode(true), counter(0) {}
    void start();
    void loop();
    int step(Move, Move);
    Move parse_input(char);

private:
    bool single_player_mode;
    int counter;
    std::array<std::string, 3> move_type = {"scissor", "rock", "paper"};
};
#endif // CONTROLLER_H
