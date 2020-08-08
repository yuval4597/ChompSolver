#pragma once

#include <vector>
#include <map>
#include <utility>

using gridi = std::vector<std::vector<int>>;
using pairi = std::pair<int, int>;

class Chomp
{
private:
	gridi grid;

	// Grid when there is no way to win
	gridi endGameGrid;

	// Keeps track of encountered grids when searching for best move
	std::map<gridi, pairi> knownGrids;

	void InitializeGrid(int numOfRows, int numOfColumns);

	bool playMove(gridi& testGrid, int row, int col);

	// Used to determine best move given current configuration
	pairi checkGrid(gridi testGrid);

	bool simulateTurn(gridi testGrid, int row, int col);

	// Overloaded function used for testing and debugging purposes
	void printGrid(gridi testGrid);

public:
	Chomp(int r, int c);

	gridi getGrid();

	void printGrid();

	// Use when playing
	bool playMove(int row, int col);

	// Wrapper for checkGrid, resulting in numbers corresponding to what user understands
	pairi findBestMove(gridi testGrid);

	// Returns true when someone won
	bool checkWin();
};