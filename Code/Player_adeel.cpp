#include "Player_adeel.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

Player_adeel::Player_adeel()
{

    name_of_developer = std::string("Player_Adeel");
    player_no = 1994;
}

Player_adeel::~Player_adeel()
{
}

int Player_adeel::getNextMove(int fld_status[])
{
    player_no = get_own_Player_no();
    int toplace_pos = -1;
    int score;
    int bestScore = -std::numeric_limits<int>::max();
    for (unsigned int i = 1; i < 17; ++i) {
        if (fld_status[i] == 0) {
            fld_status[i] = player_no;
            score = runMiniMax(fld_status, 0, false);

            fld_status[i] = 0;
            if (score > bestScore) {
                bestScore = score;
                toplace_pos = i;
            }
        }
    }

    return toplace_pos;
}



int Player_adeel::runMiniMax(int fld_status[], int depth, bool isMaximizing)
{
    if (depth + 1 > depth_cutoff) {
        return 0;
    };
    const auto result = getResultIfGameOver(fld_status);
    if (result != Result::NoResult) {
        return miniMaxWinnerScore[static_cast<int>(result)];
    };
    
    if (isMaximizing) {
        int score;
        int bestScore = -std::numeric_limits<int>::max();
        for (unsigned int i = 1; i < 17; ++i) {
            if (fld_status[i] == 0) {
                fld_status[i] = player_no;

                score = runMiniMax(fld_status, depth + 1, false);

                fld_status[i] = 0;
                bestScore = std::max(score, bestScore);

            }
        }
        return bestScore;
    }
    else {
        int score;
        int bestScore = std::numeric_limits<int>::max();
        for (unsigned int i = 1; i < 17; ++i) {
            if (fld_status[i] == 0) {
                fld_status[i] = (player_no == 1) ? 2 : 1;

                score = runMiniMax(fld_status, depth + 1, true);

                fld_status[i] = 0;
                bestScore = std::min(score, bestScore);
            }
        }
        return bestScore;
    }
}

Player_adeel::Result Player_adeel::getResultIfGameOver(int fld_status[])
{
    auto winner = Result::NoResult;

    // Diagonals
    const bool isForwardDiagonal = areValuesEqual(fld_status[1], fld_status[6], fld_status[11], fld_status[16]);
    if (isForwardDiagonal) { return static_cast<Result>(fld_status[1]); };

    const bool isBackwardDiagonal = areValuesEqual(fld_status[4], fld_status[7], fld_status[10], fld_status[13]);
    if (isBackwardDiagonal) { return static_cast<Result>(fld_status[4]); };

    // Horizontal
    for (unsigned int i = 0; i < 4; ++i) {
        const bool isRow = areValuesEqual(fld_status[1 + i * 4], fld_status[2 + i * 4], fld_status[3 + i * 4], fld_status[4 + i * 4]);
        if (isRow) { return static_cast<Result>(fld_status[1 + i * 4]); };
    }

    // Vertical
    for (unsigned int i = 0; i < 4; ++i) {
        const bool isColumn = areValuesEqual(fld_status[1 + i], fld_status[5 + i], fld_status[9 + i], fld_status[13 + i]);
        if (isColumn) { return static_cast<Result>(fld_status[1 + i]); };
    }

    unsigned int numOfZeros = 0;
    for (unsigned int i = 1; i < 17; ++i) {
        if (fld_status[i] == 0) {
            numOfZeros++;
        }
    }

    if (winner == Result::NoResult && numOfZeros == 0) {
        return Result::Tie;
    }
    else {
        return winner;
    }
}


bool Player_adeel::areValuesEqual(int first, int second, int third, int fourth)
{
    return first != 0 && first == second && second == third && third == fourth;
}
//Adeel Ahmed RCSE
