#ifndef PLAYER_ADEEL_HEADER
#define PLAYER_ADEEL_HEADER

//#pragma once
#include "Player.h"

class Player_adeel :
	public Player
{
public:
	Player_adeel();
	~Player_adeel();

	int getNextMove(int fld_status[]);

private:


	int runMiniMax(int fld_status[], int depth, bool isMaximizing);

	enum class Result { NoResult, WonPlayer1, WonPlayer2, Tie };

	static Result getResultIfGameOver(int fld_status[]);
	static bool areValuesEqual(int first, int second, int third, int fourth);
	// Penalty or reward. {Tie, Won, Lost}
	const int miniMaxWinnerScore[3] = { 0, 10, -10 };
	static const int depth_cutoff = 3;

	friend class PlayerAdeelUnitTest;
};

#endif // !PLAYER_ADEEL_HEADER
//Adeel Ahmed RCSE