#pragma once

class Player
{
    char sign_;
    bool turn_;

public:
    Player(char sign);

    bool getTurn() const;
    void setTurn(bool value);
    char getSign() const;
};
