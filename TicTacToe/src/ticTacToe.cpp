//============================================================================
// Name        : TicTacToe.cpp
// Author      : Mike Kelso
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================


//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip>
#include <random>
#include "ticTacToe.h"

using namespace std;

void ticTacToe::play()
{
	bool done = false;
	char player = 'X';
	displayBoard();

	while (!done)
	{

		done = getXOMove(player);

		displayBoard();


		//test if win or draw
		if (gameStatus() == 0)
		{
			cout << "Player " << player << " wins!";
			done = true;
		}

		else if ( gameStatus() == 1 )
		{
			cout << "It's a draw!";
			done = true;
		}

		if (player == 'X')
		{
			player = 'O';
		}
		else
		{
			player = 'X';
		}

	}

}


void ticTacToe::displayBoard() const

{
	const int rowCount = 9;
	const int colCount = 15;

	// initialize the game board
	char fullBoard[rowCount][colCount];
	for (int row = 0; row < rowCount; row++){
		for (int col = 0; col < colCount;col++){
			fullBoard[row][col] = ' ';
		}
	}

	//make pound sign
	for (int colIndex = 2; colIndex < colCount;colIndex ++)
	{
		fullBoard[3][colIndex] = fullBoard[6][colIndex] = '_';
	}
	for (int rowIndex = 2; rowIndex < rowCount; rowIndex ++)
	{
		fullBoard[rowIndex][5] = fullBoard[rowIndex][10]= '|';
	}

	// place the 1, 2, 3 on the top and side
	fullBoard[0][3] = fullBoard[2][0] = '1';
	fullBoard[0][8] = fullBoard[5][0] = '2';
	fullBoard[0][13] = fullBoard[8][0] = '3';

	// map 3x3 board onto full board
	int rowSpacer = 2;
	int colSpacer = 3;

	for (int row = 0; row < 3; row++){
		colSpacer = 3;
		for (int col = 0; col < 3;col++){
			fullBoard[row + rowSpacer][ col + colSpacer] = board[row][col];
			colSpacer += 4;
		}
		rowSpacer += 2;
	}

	//print full board
	for (int row = 0; row < rowCount; row++){

		for (int col = 0; col < colCount;col++){
			cout << fullBoard[row][col];
		}
		cout <<endl;
	}


}








bool ticTacToe::isValidMove(int row, int col) const
{
	if ((row > 2) || (col >2))
	{
		cout << "Out of bounds! Choose a move 1-3 x 1-3." << endl;
		return false;
	}
	else if (( board[row][col] == 'X') || ( board[row][col] == 'O'))
	{
		cout << "There is already a character in that spot. Pick an empty space." << endl;
		return false;
	}
	else
		return true;
}


bool ticTacToe::getXOMove(char playerSymbol)
{
	int moveRow,moveCol;

	//loop that will request move until valid input
	do
	{
		cout << "Player " << playerSymbol << " enter move: ";
		cin >> moveRow >> moveCol;
		moveRow--;
		moveCol--;
	} while (!isValidMove(moveRow, moveCol));

	board[moveRow][moveCol] = playerSymbol;
	noOfMoves++;


	return false;
}



status ticTacToe::gameStatus()
{
	status gameStatus = CONTINUE;


	for (int i = 0; i <=2; i++)
	{
		// horizontal wins
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			if (board[i][1] != ' ')
			{
				return gameStatus = WIN;
			}

		}
		//vertical wins
		else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i] ))
		{
			if (board[1][i] != ' ')
			{
				return gameStatus = WIN;
			}
		}

	}

	//diagonal wins
	if ( ( (board[0][0] == board[1][1]) && (board[1][1]  == board[2][2]) ) || ( (board[0][2] == board[1][1]) && (board[0][2] == board[2][0])))
	{
		if ( (board[1][1] == 'X') || (board[1][1] == 'O'))
		{
			return gameStatus = WIN;
		}
	}

	if (noOfMoves == 9)
		return gameStatus = DRAW;


	return gameStatus;

}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}




