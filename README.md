# dartgaem
dart gaem

#include "player.h"


#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>


Player::Player(int accuracy)
{
	wins = 0;
	throw_count = 0;
	bull_hitRate = accuracy;
	state = 0;
	aiming = 0;
	wins = 0;
	win = false;

}

//Player state. aiminf for 50 or more	
//
int Player::State()
{
	if (score > 70)
	{
		state = 0;
	}

	else if (score > 50 && score <= 70) // if greater than 50 or equal to 70 state 1; how the other states work. 
	{
		state = 1;
	}

	else if ((score == 50) || (score == 0))
	{
		state = 2;
	}

	return (state);
}


int Player::Aim()
{
	if (state == 0)
	{
		if ((score - 50) > 50)
		{
			aiming = 50;
		}
		else
		{
			aiming = 20;
		}
	}

	if (state == 1)
	{
		aiming = score - 50;
	}
	else if (state == 2) //Player can only aim at the Bull since he has a score of 50
	{
		aiming = 50;

	}

	return (aiming);
}

//Logic for aiming// 

int Player::Throw()
{
	int chance = 0, aiming_position = 0, left_position = 0, right_position = 0;

	chance = rand() % 100 + 1; //chance between 1 and 100// 
	if (aiming == 50)
	{
		if (chance <= bull_hitRate)
		{
			score_hit = aiming;
		}
		else // if player misses the targer,do this function// 
		{
			aiming_position = rand() % 19;
			score_hit = board[aiming_position];
		}
	}
	else if (aiming != 50)
	{
		if (chance <= Accuracy)// if the chance is equal to the auccary:score hit=aiming.//
		{
			score_hit = aiming;
		}
		else // logic for a miss// 
		{
			for (int i = 0; i <= 19; i++)
			{
				if (board[i] == aiming)
				{
					aiming_position = i;
				}
			}

			if (aiming_position == 0)
			{
				left_position = 19;
				right_position = aiming_position + 1;
			}

			else if (aiming_position == 19)
			{
				left_position = aiming_position - 1;
				right_position = 0;
			}

			chance = rand() % 2;

			if (chance == 0)
			{
				score_hit = board[left_position];
			}
			else if (chance == 1)
			{
				score_hit = board[right_position];
			}
		}
	}
	return score_hit;
}

//when player throws darts this will update the players score, three states used for
// this function 
//if greater than 50 ,hit; if less than minus from score, if equal to minus from score//
int Player::Score_Counter()
{
	if (state == 0)
	{
		if ((score - score_hit) < 50)
		{
			score = score;
		}
		else
		{
			score = score - score_hit;
		}
	}
	if (state == 1)
	{
		if ((score - score_hit) < 50)
		{
			score = score;
		}
		else if ((score - score_hit) >= 50)
		{
			score = score - score_hit;
		}
	}
	if ((state == 2) && (score_hit == 50))
	{
		score = score - score_hit;
	}
	else
	{
		score = score;
	}

	return score;
}


void Player::Play()
{
	State();
	Aim();
	Throw();
	Score_Counter();
	throw_count++;

	if (score == 0)
		win = true;
}
