#include "Player_00.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Player_00::Player_00()
{
    name_of_developer = std::string("Playername_001");
	player_no = 223;
}

Player_00::~Player_00()
{
}

int Player_00::getNextMove(int fld_status[])
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

