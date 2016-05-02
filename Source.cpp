#include <iostream>
#include <cstdlib> 
#include <stdlib.h> //for random number generation
#include <string>
#include <time.h>
#include <Windows.h>


#include "player.h"

using namespace std;

int main()
{


	Player joe(71); //Joe with Bull Accuracy
	Player sid(73); //Sid with Bull Accuracy

	int throws[7] = { 0 }; //Players have seven throws each 
	int player_switch = 0;

	srand(time(NULL)); // for random nums


	// game loop
	for (int game_loops = 0; game_loops < 100; game_loops++)
	{
		//set score for both players// 
		joe.score = 501;
		sid.score = 501;
		joe.throw_count = 0;
		sid.throw_count = 0;
		

		while ((joe.win == false) && (sid.win == false))
		{
			if ((sid.score != 0) && (player_switch == 0))
			{

				cout << "Joe's turn: \n";
				cout << "Joe has " << joe.score << " points left.\n"; //grabs joes score and prints 
				joe.Play();
				cout << "Joe aims for " << joe.aiming << ",  hits " << joe.score_hit << "\n\n";
				player_switch = 1;
			}
			if ((joe.score != 0) && (player_switch == 1))
			{

				cout << "Sid's turn: \n" << endl;
				cout << "Sid has " << sid.score << endl;	//grabs sids score and prints 
				sid.Play();
				cout << "Sid aims for " << sid.aiming << "  hits " << sid.score_hit << "\n\n";
				player_switch = 0;
			}
		}

		cout << "";
		if (sid.win == true)
		{
			cout << "Sid won the game!!\n ";
			cout << "\n";
			sid.wins++;
			sid.score = 501; //score for both players starting 
			joe.score = 501;
			sid.win = false;
		}
		else
		{
			cout << "Joe won the game!!\n";
			cout << "\n";
			joe.wins++;
			sid.score = 501;
			joe.score = 501;
			joe.win = false;
		}

		//logic of array 
		if (joe.throw_count == 7)
			throws[0] += 1;
		else if (joe.throw_count == 8)
			throws[1] += 1;
		else if (joe.throw_count == 9)
			throws[2] += 1;
		else if (joe.throw_count == 10)
			throws[3] += 1;
		else if (joe.throw_count == 11)
			throws[4] += 1;
		else if (joe.throw_count == 12)
			throws[5] += 1;
		else
			throws[6] += 1; // once past 6+1 joes throw ends; count++// 
	}



	
	float game_loops=0;
		cout << "Joe won:" << joe.wins << "\n";
		cout << "Sid won:" << sid.wins << "\n";
		/// win ratio
		int winratiojoe = joe.wins/10;
		int winRatiosid = sid.wins/10;
		cout << "win ratio for the game    Sid::Joe" << endl;
		cout << "                            " << winRatiosid << "::" << winratiojoe << endl;

		// frequency
		float sets = ((double)joe.wins + (double)sid.wins) / (double)game_loops; //cant figure out why it doesnt work  :/
		float Sets = ((double)joe.wins + (double)sid.wins) / (double)game_loops;

		cout << "Sets won                  Joe::Sid" << endl;
		cout << "                            " << sets << "::" << Sets << endl;



	


	getchar();

	return 0;
}
