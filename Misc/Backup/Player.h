#pragma once
#include <string>

class Player
{
public:
    Player();
    Player(int no);
    ~Player();

    /**
     * Calculates the next move.
     * Has to be overwritten. This is where the "AI" goes.
     * @param fld_status the model of the board
     * @return the index of the square of choice (1 to 16) or -1 if no placement is possible
     */
    virtual int getNextMove(int fld_status[]);

    /**
     * Checks if there are still empty squares on the board
     * @param fld_status the model of the board
     * @return true if a move can be made, false if the board is full
     */
    bool fields_left(int fld_status[]);

    /**
     * Returns the player number (1 or 2)
     * @return the player number
     */
    int get_own_Player_no();

    /**
     * Returns the developers name.
     * @return the developers name
     */
    std::string get_dev_name();

    /**
     * Sets the player number.
     * @param no the player number (1 or 2)
     */
    void setPlayerNumber(int no) { player_no = no; }

protected:

    /**
     * The name of the developer
     */
    std::string name_of_developer;

    /**
     * The player number(1 or 2)
     */
    int player_no;
};
