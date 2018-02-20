#include <iostream>
#include "TicTacToePlayer.h"

using namespace std;

int main()
{
	int isFirstPlayer = 1;
	TicTacToePlayer player1(isFirstPlayer);
	TicTacToePlayer player2(isFirstPlayer = 0);

	player1.printBoard();
	while (1)
	{
		player1.automateMove();
		if (player1.checkGameStatus())
		{
			player1.printBoard();
			break;
		}
		player1.printBoard();
		player2.automateMove();
		if (player2.checkGameStatus())
		{
			player2.printBoard();
			break;
		}
		player2.printBoard();
	}
	system("pause");
	return 0;
}