#include "Chomp.h"

#include <iostream>

using namespace std;

Chomp::Chomp(int r, int c)
{
	InitializeGrid(r, c);
}

gridi Chomp::getGrid()
{
	return grid;
}

void Chomp::InitializeGrid(int numOfRows, int numOfColumns)
{
	gridi tempGrid(numOfRows, vector<int>(numOfColumns, 1));
	tempGrid.back()[0] = 2;

	grid = tempGrid;

	gridi tempEndGrid(numOfRows, vector<int>(numOfColumns, 0));
	tempEndGrid.back()[0] = 2;

	endGameGrid = tempEndGrid;
}

void Chomp::printGrid()
{
	for (auto i = 0; i <= grid.size(); i++)
	{
		if (i == 0)
		{
			cout << "   ";
		}
		else
		{
			cout << grid.size() - i + 1 << ": ";
		}

		for (auto j = 0; j < grid[0].size(); j++)
		{
			if (i == 0)
			{
				cout << j + 1 << " ";
			}
			else
			{
				cout << grid[i - 1][j] << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n";
}

void Chomp::printGrid(gridi testGrid)
{
	for (auto i = 0; i <= testGrid.size(); i++)
	{
		if (i == 0)
		{
			cout << "   ";
		}
		else
		{
			cout << testGrid.size() - i + 1 << ": ";
		}

		for (auto j = 0; j < testGrid[0].size(); j++)
		{
			if (i == 0)
			{
				cout << j + 1 << " ";
			}
			else
			{
				cout << testGrid[i - 1][j] << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n";
}

// Returns true when move was successful
bool Chomp::playMove(int row, int col)
{
	row = grid.size() - row;
	col--;

	if (row >= grid.size() || col >= grid[0].size())
	{
		cout << "Invalid number of rows or columns. Didn't play move.\n";
		return false;
	}

	if (grid[row][col] == 0)
	{
		cout << "Invalid move. Cannot eat 0 piece. Didn't play move.\n";
		return false;
	}

	for (auto i = 0; i < grid.size(); i++)
	{
		for (auto j = 0; j < grid[0].size(); j++)
		{
			if (i <= row && j >= col)
			{
				grid[i][j] = 0;
			}
		}
	}

	return true;
}

bool Chomp::playMove(gridi &testGrid, int row, int col)
{
	if (row >= testGrid.size() || col >= testGrid[0].size())
	{
		return false;
	}

	if (testGrid[row][col] == 0)
	{
		return false;
	}

	for (auto i = 0; i < testGrid.size(); i++)
	{
		for (auto j = 0; j < testGrid[0].size(); j++)
		{
			if (i <= row && j >= col)
			{
				testGrid[i][j] = 0;
			}
		}
	}

	return true;
}

pairi Chomp::checkGrid(gridi testGrid)
{
	auto iter = knownGrids.find(testGrid);

	// Already seen this grid before, no need to recalculate answer
	if (iter != knownGrids.end())
	{
		return iter->second;
	}

	pairi bestMove = { -1, -1 };

	for (auto i = 0; i < testGrid.size(); i++)
	{
		for (auto j = 0; j < testGrid[0].size(); j++)
		{
			if (i == testGrid.size() - 1 && j == 0)
			{
				continue;
			}

			if (testGrid[i][j] == 1)
			{
				if (simulateTurn(testGrid, i, j))
				{
					bestMove = { i, j };
					break;
				}
			}
		}
	}

	// Add to list of known grids to avoid recalculation
	knownGrids.emplace(testGrid, bestMove);

	return bestMove;
}

 bool Chomp::simulateTurn(gridi testGrid, int row, int col)
{
	// Simulate the move (removing appropriate 1s)
	playMove(testGrid, row, col);

	// Check what the best move the next player would have
	pairi checkCoords = checkGrid(testGrid);

	// Next player has no moves
	if (checkCoords.first == -1)
	{
		// Returning true because this leaves next player with no moves
		return true;
	}

	// False because next player has moves left
	return false;
}

 pairi Chomp::findBestMove(gridi testGrid)
 {
	pairi bestMove = checkGrid(testGrid);

	if (bestMove.first != -1)
	{
		bestMove.first = testGrid.size() - bestMove.first;
		bestMove.second++;
	}

	return bestMove;
 }

 bool Chomp::checkWin()
 {
	 if (grid == endGameGrid)
	 {
		 return true;
	 }

	 return false;
 }