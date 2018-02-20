#include <iostream>
#include "TicTacToePlayer.h"

using namespace std;

int main()
{
	int row, column, flag, isFirstPlayer;

	cout << "Enter 1 if you want to be 1st player or 0 for 2nd player:" << endl;
	cin >> isFirstPlayer;
	TicTacToePlayer player(isFirstPlayer);

	player.printBoard();
	if (isFirstPlayer)
	{
		while (1)
		{
			do
			{
				cout << "Enter row and column for matrix possition:" << endl;
				cin >> row >> column;
				flag = player.checkPoss(row, column);
			} while (flag != 0);
			player.makeMove(row, column);
			if (player.checkGameStatus())
			{
				break;
			}
			player.printBoard();
			player.automateMove();
			if (player.checkGameStatus())
			{
				break;
			}
			player.printBoard();
		}
		player.printBoard();
	}
	else
	{
		while (1)
		{
			player.automateMove();
			if (player.checkGameStatus())
			{
				break;
			}
			player.printBoard();
			do
			{
				cout << "Enter row and column for matrix possition:" << endl;
				cin >> row >> column;
				flag = player.checkPoss(row, column);
			} while (flag != 0);
			player.makeMove(row, column);
			if (player.checkGameStatus())
			{
				break;
			}
			player.printBoard();
		}
		player.printBoard();
	}

	return 0;
}