#ifndef H_TicTacToePlayer
#define H_TicTacToePlayer

class TicTacToePlayer
{
public:
	TicTacToePlayer(int isFirstPlayer);
	/* prints the board */
	void printBoard();
	/* user made move */
	void makeMove(int m, int n);
	/* computer made move */
	void automateMove();
	/* checks if position in the
	board is ocupied,
	returns 1 for occupied
	0 for not occupied */
	int checkPoss(int m, int n);
	/* checks and prints the status of game,
	with the help of checkWin()
	retuns  0 for inprogress
	1 for end of game */
	int checkGameStatus();
private:
	/* Use an appropriate data structure
	for storing the board */
	static char board[3][3];
	int symbol;
	/* Checks who won
	returns 0 for X win
	1 for O win
	2 for draw */
	int checkWin();
	int moves = 0;
};



#endif H_TicTacToePlayer