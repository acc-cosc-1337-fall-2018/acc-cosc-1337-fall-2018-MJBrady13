#include "tic_tac_toe_board.h"
#include<iostream>

using namespace std;

void TicTacToeBoard::start_game(std::string player)
{
	next_player = player;
	clear_board();
}

void TicTacToeBoard::mark_board(int position)
{
	pegs[position - 1] = next_player;
	set_next_player();
}

string TicTacToeBoard::get_player()
{
	return next_player;
}

void TicTacToeBoard::display_board()
{
	cout << "TIC TAC TOE!" << "\n";
	cout << "Current player: " << next_player << "\n";
	cout << "Board Positions: ";
	
	for (int i = 0; i < 9; i += 1)
	{
		string mark = pegs[i];
		cout << i+1 << ": " << mark;
	}
	


}

void TicTacToeBoard::set_next_player()
{
	if (next_player == "X") 
	{
		next_player = "O";
	}else next_player = "X";
}

bool TicTacToeBoard::check_column_win()
{
	if (pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X")
	{
		return true;
	}
	if (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X")
	{
		return true;
	}
	if (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X")
	{
		return true;
	}
	if (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O")
	{
		return true;
	}
	if (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O")
	{
		return true;
	}
	if (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O")
	{
		return true;
	}
	return false;
}

bool TicTacToeBoard::check_row_win()
{
	if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X")
	{
		return true;
	}
	if (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X")
	{
		return true;
	}
	if (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")
	{
		return true;
	}
	if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O")
	{
		return true;
	}
	if (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O")
	{
		return true;
	}
	if (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O")
	{
		return true;
	}
	return false;
}

bool TicTacToeBoard::check_diagonal_win()
{
	if (pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")
	{
		return true;
	}
	if (pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X")
	{
		return true;
	}
	if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
	{
		return true;
	}
	if (pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O")
	{
		return true;
	}
	return false;
}

void TicTacToeBoard::clear_board()
{
	for (int i =0; i < 9; i+=1)
	{
		pegs[i] = "";
	}
}

bool TicTacToeBoard::check_board_full()
{
	for (int i = 0; i < 9; i += 1)
	{
		if (pegs[i]=="")
		{
			return false;
		}
		else return true;
	}
}
