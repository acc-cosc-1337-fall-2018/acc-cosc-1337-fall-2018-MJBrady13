#include "tic_tac_toe_board.h"
#include<iostream>



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
	pegs[position - 1].val = next_player;
	set_next_player();
}

std::string TicTacToeBoard::get_player()
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


void TicTacToeBoard::clear_board()
{
	for (int i =0; i < 9; i+=1)
	{
		pegs[i].val = " ";
	}
}

bool TicTacToeBoard::check_board_full() const
{
	bool full = true;
	for (auto i : pegs)
	{
		if (i.val == " ") 
		{
			full = false;
		}
	}
	return full;
}

std::istream & operator>>(std::istream & in, TicTacToeBoard & board)
{
	board.get_input(in);
	return in;
}

std::ostream & operator<<(std::ostream & out, const TicTacToeBoard & board)
{
	board.display_board(out);
	return out;
}

