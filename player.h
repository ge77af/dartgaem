
// Accuracy of both players when aiming for anything but the center.
// want functions to be inlineable.


#define Accuracy 72 //i set it to the average of amongst each player 


const int board[20] = { 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5 };

class Player
{
private:

	const int basic_accuracy = Accuracy;
	int bull_hitRate;


	int State();
	int Aim();
	int Throw();
	int Score_Counter();

public:
	int score;
	int state;
	int score_hit;
	int aiming;
	bool win;
	Player(int);
	void Play();
	int throw_count;
	int wins;
};
