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

## Example
Although the Chomp class contains all of the logic one might need in order to implement Chomp Solver, I've included a simple example using the console.

