//#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	player_no = -1;
}

Player::Player(int no) : player_no(no)
{
}

Player::~Player()
{
}


int Player::getNextMove(int fld_status[])
{
    return -1;
}


bool Player::fields_left(int fld_status[])
{
    // Check to see if the whole grid is filled out.
	int i;
	bool leftfields = false;

	for(i = 1; i<17; i++)
	{
		// if at least one field is left open return true
		if(fld_status[i] == 0) leftfields = true;
	}
	return leftfields;
}

int Player::get_own_Player_no()
{
	return player_no;
}

std::string Player::get_dev_name()
{
    return name_of_developer;
}
