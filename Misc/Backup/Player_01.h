#include "Player.h"

class Player_01:
	public Player
{
public:
	Player_01();
	Player_01(int no);
	~Player_01();

	int getNextMove(int fld_status[]);
};
