# Chomp Solver
## Introduction
In a game of Chomp, each player must take a piece from the board, and in doing so also remove all pieces above and to the right of said piece.
An interactive example could be found [here](https://www.math.ucla.edu/~tom/Games/chomp.html) 
![Chomp Grid Example](../images/ChompGridExample.PNG?raw=true)
This game was introduced in a math class when I was asked to find a viable strategy for winning a game of Chomp on a 4x7 grid (4 rows, 7 columns).
I have found that there are strategies for winning with square (nxn) grids, as well as 2xn (and more recently 3xn) grids, but there exists no consistent strategy for winning with 4xn grids.
Thus, after being frustrated by the many losses I've endured against the bot linked above, I decided to write a program that will tell me what the best move is given any grid configuration.
Using this program, I was able to find winning strategies more easily, and complete the original assignment.
## Explanation
The Chomp class contains all of the logic to draw a board, play turns, and of course find the best possible move given the current configuration.
Since there are many repeated calculations in finding the best possible move, I have used dynamic programming techniques to solve this problem.
The following is an explanation of the two main functions using pseudocode, where pairi is defined as pair<int, int> and gridi is defined as vector<vector<int>>:

pairi Chomp::checkGrid(gridi testGrid)
{
	If have already seen this grid in knownGrids
		return bestMove from knownGrids

	Otherwise, initialize bestMove to be (-1, -1) (no guaranteed win)

	Iterate through every piece on the grid except the poisoned piece
		If the current piece is a 1 (has not been eaten yet)
			Call simulateTurn with the current grid and piece
				If it returns true, bestMove is current piece

	Add this grid, as well as coordinates of best move, to knownGrids

	return bestMove
}

 bool Chomp::simulateTurn(gridi testGrid, int row, int col)
{
	Simulate the move at row and col (removing appropriate 1s)

	Call checkGrid on this new grid

	If checkGrid returned (-1,-1)
		return true, as other player cannot win after this move

	return false, other player has moves that could guarantee a win
}

If you have any questions please don't hesitate to ask!

## Example
Although the Chomp class contains all of the logic one might need in order to implement Chomp Solver, I've included a simple example using the console.
![Chomp Output Example](../images/ChompConsole_Ouput_1.PNG?raw=true)
![Chomp Output Example](../images/ChompConsole_Ouput_2.PNG?raw=true)
