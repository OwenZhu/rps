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

    static int step(Move, Move);
    static Move parse_input(char);

private:
    bool single_player_mode;
    int counter;

    static const std::array<std::string, 3> move_type;
};

#endif // CONTROLLER_H
