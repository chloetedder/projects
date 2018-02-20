#include "TicTacToePlayer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

char TicTacToePlayer::board[3][3] = { { ' ',' ',' ' },{ ' ',' ',' ' },{ ' ',' ',' ' } };

TicTacToePlayer::TicTacToePlayer(int isFirstPlayer)
{
	if (isFirstPlayer)
		symbol = 'X';
	else
		symbol = 'O';
}
void TicTacToePlayer::printBoard()
{
	cout << "Current board status" << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << endl;
}

void TicTacToePlayer::makeMove(int m, int n)
{
	board[m - 1][n - 1] = symbol;
	if (symbol == 'X')
	{
		symbol = 'O';
		moves++;
	}
	else
	{
		symbol = 'X';
		moves++;
	}
}

void TicTacToePlayer::automateMove()
{
	char comp;
	char play;
	if (symbol == 'X')
	{
		comp = 'X';
		play = 'O';
	}
	else
	{
		comp = 'O';
		play = 'X';
	}
	if (board[0][0] == play && board[0][1] == play && board[0][2] == ' ')
	{
		board[0][2] = comp;
		symbol = play;
		moves++;
	}

	else if (board[1][0] == play && board[1][1] == play && board[1][2] == ' ')
	{
		board[1][2] = comp;
		symbol = play;
		moves++;
	}
	else if (board[2][0] == play && board[2][1] == play && board[2][2] == ' ')
	{
		board[2][2] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == play && board[1][0] == play && board[2][0] == ' ')
	{
		board[2][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][1] == play && board[1][1] == play && board[2][1] == ' ')
	{
		board[2][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][2] == play && board[1][2] == play && board[2][2] == ' ')
	{
		board[2][2] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == play && board[1][1] == play && board[2][2] == ' ')
	{
		board[2][2] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][2] == play && board[1][1] == play && board[2][0] == ' ')
	{
		board[2][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == play && board[1][1] == ' ' && board[2][2] == play)
	{
		board[1][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][2] == play && board[1][1] == ' ' && board[2][0] == play)
	{
		board[1][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == ' ' && board[1][1] == play && board[2][2] == play)
	{
		board[0][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][2] == ' ' && board[1][1] == play && board[2][0] == play)
	{
		board[0][2] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == play && board[0][1] == ' ' && board[0][2] == play)
	{
		board[0][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[1][0] == play && board[1][1] == ' ' && board[1][2] == play)
	{
		board[1][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[2][0] == play && board[2][1] == ' ' && board[2][2] == play)
	{
		board[2][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == play && board[1][0] == ' ' && board[2][0] == play)
	{
		board[1][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][1] == play && board[1][1] == ' ' && board[2][1] == play)
	{
		board[1][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][2] == play && board[1][2] == ' ' && board[2][2] == play)
	{
		board[1][2] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == ' ' && board[0][1] == play && board[0][2] == play)
	{
		board[0][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[1][0] == ' ' && board[1][1] == play && board[1][2] == play)
	{
		board[1][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[2][0] == ' ' && board[2][1] == play && board[2][2] == play)
	{
		board[2][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == ' ' && board[1][0] == play && board[2][0] == play)
	{
		board[0][0] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][1] == ' ' && board[1][1] == play && board[2][1] == play)
	{
		board[0][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][2] == ' ' && board[1][2] == play && board[2][2] == play)
	{
		board[0][2] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][0] == play && (board[1][2] == play || board[2][1] == play) && board[1][1] == ' ')
	{
		board[1][1] = comp;
		symbol = play;
		moves++;
	}
	else if (board[0][2] == play && (board[1][0] == play || board[2][1] == play) && board[1][1] == ' ')
	{
		board[1][1] == comp;
		symbol = play;
		moves++;
	}
	else if (board[2][0] == play && (board[1][2] == play || board[0][1]) && board[1][1] == ' ')
	{
		board[1][1] == comp;
		symbol = play;
		moves++;
	}
	else if (board[2][2] == play && (board[1][0] == play || board[0][1] == play) && board[1][1] == ' ')
	{
		board[1][1] = comp;
		symbol = play;
		moves++;
	}
	else
	{
		bool flag = true;
		while (flag)
		{
			int random = rand() % 10;
			switch (random)
			{
			case 0:
				if (board[0][0] == ' ')
				{
					board[0][0] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 1:
				if (board[0][1] == ' ')
				{
					board[0][1] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 2:
				if (board[0][2] == ' ')
				{
					board[0][2] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 3:
				if (board[1][0] == ' ')
				{
					board[1][0] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 4:
				if (board[1][1] == ' ')
				{
					board[1][1] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 5:
				if (board[1][2] == ' ')
				{
					board[1][2] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 6:
				if (board[2][0] == ' ')
				{
					board[2][0] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 7:
				if (board[2][1] == ' ')
				{
					board[2][1] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}

			case 8:
				if (board[2][2] == ' ')
				{
					board[2][2] = comp;
					symbol = play;
					moves++;
					flag = false;
					break;
				}
			default:
				flag = true;

			}
		}
	}


}

int TicTacToePlayer::checkPoss(int m, int n)
{
	if (board[m - 1][n - 1] == ' ')
		return 0;
	else
		return 1;
}

int TicTacToePlayer::checkGameStatus()
{
	switch (checkWin())
	{
	case -1:
		return 0;
		break;
	case 0:
		cout << "X win" << endl;
		return 1;
		break;
	case 1:
		cout << "O win" << endl;
		return 1;
		break;
	case 2:
		cout << "draw" << endl;
		return 1;
		break;
	default:
		cout << "error in game" << endl;
	}


}

int TicTacToePlayer::checkWin()
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return 0;
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return 1;

	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		return 0;
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		return 1;

	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		return 0;
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		return 1;

	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		return 0;
	if (board[0][0] == 'O' && board[2][0] == 'O' && board[2][0] == 'O')
		return 1;

	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		return 0;
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		return 1;

	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		return 0;
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		return 1;

	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return 0;
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return 1;

	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		return 0;
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		return 1;
	else
	{
		if (moves > 8)
		{
			return 2;
		}
		else
			return -1;
	}
}
