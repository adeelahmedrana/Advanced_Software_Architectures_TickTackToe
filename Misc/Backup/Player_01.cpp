#include "Player_01.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Player_01::Player_01()
{
    name_of_developer = std::string("Player_002");
	player_no = 7625;
}

Player_01::~Player_01()
{
}

int Player_01::getNextMove(int fld_status[])
{
	srand((unsigned)time(NULL));
	int toplace_pos = -1;

	if(fields_left(fld_status))
	{
		do
		{
			toplace_pos = (rand() % 16) + 1;

		} while(fld_status[toplace_pos] == 1 ||
			fld_status[toplace_pos] == 2 ||
			fld_status[toplace_pos] == 3);
	}
	return toplace_pos;
}
