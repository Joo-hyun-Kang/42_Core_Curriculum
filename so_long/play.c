#include "so_long.h"

void move_north(t_game *g)
{
	//북쪽으로 움직였을 때
	
	// 
}


int	catch_move(int keycode, t_game *g)
{
	if (keycode == DIR_NORTH)
		move_north(g);
}