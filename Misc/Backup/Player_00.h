#include "Player.h"

class Player_00 : public Player
{
public:
	Player_00();
	Player_00(int no);
	~Player_00();

	int getNextMove(int fld_status[]);
};
