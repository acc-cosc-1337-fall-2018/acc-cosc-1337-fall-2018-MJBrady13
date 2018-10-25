#include "tic_tac_toe_board.h"
#include<iostream>

using namespace std;

bool TicTacToeBoard::game_over()
{
	if (check_column_win()==true) {
		if (next_player == "X")
		{
			o_win += 1;
		}
		else x_win += 1;
		return true;
	}
	else if (check_row_win()==true) {
		if (next_player == "X")
		{
			o_win += 1;
		}
		else x_win += 1;
		return true;
	}
	else if (check_diagonal_win()==true) {
		if (next_player == "X")
		{
			o_win += 1;
		}
		else x_win += 1;
		return true;
	}
	else if (check_board_full()==true) {
		c_win += 1;
		return true;
	}
	else return false;
}

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
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X")
	{
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X")
	{
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O")
	{
		cout << "O Wins!" << endl;
		return true;
	}
	if (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O")
	{
		cout << "O Wins!" << endl;
		return true;
	}
	if (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O")
	{
		cout << "O Wins!" << endl;
		return true;
	}
	return false;
}

bool TicTacToeBoard::check_row_win()
{
	if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X")
	{
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X")
	{
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")
	{
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O")
	{
		cout << "O Wins!" << endl;
		return true;
	}
	if (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O")
	{
		cout << "O Wins!" << endl;
		return true;
	}
	if (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O")
	{
		cout << "O Wins!" << endl;
		return true;
	}
	return false;
}

bool TicTacToeBoard::check_diagonal_win()
{
	if (pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")
	{
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X")
	{
		cout << "X Wins!" << endl;
		return true;
	}
	if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
	{
		cout << "O Wins!"<<endl;
		return true;
	}
	if (pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O")
	{
		cout << "O Wins!"<<endl;
		return true;
	}
	return false;
}

void TicTacToeBoard::clear_board()
{
	for (int i =0; i < 9; i+=1)
	{
		pegs[i] = " ";
	}
}

bool TicTacToeBoard::check_board_full()
{
	bool full = true;
	for (auto i : pegs)
	{
		if (i == " ") 
		{
			full = false;
		}
	}
	return full;
}

istream & operator>>(istream & in, TicTacToeBoard & d)
{
	cout << "Player " << d.get_player() << " make your mark.(1-9)" << endl;
	in >> d.position;
	return in;
}

ostream & operator<<(ostream & out, const TicTacToeBoard & d)
{
	cout << d.pegs[0] << "|" << d.pegs[1] << "|" << d.pegs[2] << "\n";
	cout << d.pegs[3] << "|" << d.pegs[4] << "|" << d.pegs[5] << "\n";
	cout << d.pegs[6] << "|" << d.pegs[7] << "|" << d.pegs[8] << "\n";
	cout << "X wins: " << d.x_win << ", O Wins: " << d.o_win << ", Cat Wins: "<<
		d.c_win<< endl;
	return out;
}

TicTacToeBoard operator+(const TicTacToeBoard & b, const TicTacToeBoard & b2)
{
	TicTacToeBoard total_wins;
	total_wins.x_win = b.x_win + b2.x_win;
	total_wins.o_win = b.o_win + b2.o_win;
	total_wins.c_win = b.c_win + b2.c_win;

	return total_wins;
}
