// Yuval Bar
// Chomp Analysis

#include <iostream>

#include "Chomp.h"

using namespace std;

void wonGame(bool playerWon);

int main()
{
	// Temporary code to demonstrate Chomp class on console
	cout << "Yuval Bar's Chomp\nNote: 1s represent an uneaten piece, 0s are empty spaces, 2 is the poisoned piece!\n\n";

	int numOfRows = 0;
	int numOfColumns = 0;

	cout << "Number of rows: ";
	cin >> numOfRows;

	cout << "Number of columns: ";
	cin >> numOfColumns;

	cout << "\n";

	Chomp game(numOfRows, numOfColumns);
	game.printGrid();

	int inrow = 0;
	int incol = 0;

	// True when it is the player's turn, false when is AI's turn
	bool isPlayerTurn = true;

	while (inrow != -1)
	{
		if (isPlayerTurn)
		{
			pair<int, int> bestMove = game.findBestMove(game.getGrid());

			if (bestMove.first == -1)
			{
				cout << "There is no way to win unless the other player makes a mistake.\n";
			}
			else
			{
				cout << "The best move is: " << bestMove.first << " " << bestMove.second << endl;
			}
		}
		else
		{
			cout << "What was the AI's move?\n";
		}

		cout << "Row: ";
		cin >> inrow;

		while (inrow == 0 || inrow < -1)
		{
			cout << "Invalid. Row: ";
			cin >> inrow;
		}

		cout << "Col: ";
		cin >> incol;

		while (incol == 0 || incol < -1)
		{
			cout << "Invalid. Col: ";
			cin >> incol;
		}

		cout << "\n";

		// Ate poisoned piece
		if (inrow == 1 && incol == 1)
		{
			wonGame(!isPlayerTurn);
			return 1;
		}

		if (game.playMove(inrow, incol))
		{
			game.printGrid();

			if (game.checkWin())
			{
				wonGame(isPlayerTurn);
				return 0;
			}

			isPlayerTurn = !isPlayerTurn;
		}
	}
}

void wonGame(bool playerWon)
{
	if (playerWon)
	{
		cout << "You won! Good job!\n";
	}
	else
	{
		cout << "You lost :( Why didn't you listen to me...\n";
	}
}