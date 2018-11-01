#include "tic_tac_toe_4.h"
#include <iostream>

TicTacToe4::TicTacToe4()
{
	for (int i = 0; i < 16; i++)
	{
		Peg peg;
		pegs.push_back(peg);
	}
}

bool TicTacToe4::check_column_win() const
{
	for (int i = 0; i < 4; ++i)
	{
		if (pegs[i].val == pegs[i + 4].val && pegs[i].val == pegs[i + 8].val && 
			pegs[i].val == pegs[i + 12].val && pegs[i + 12].val != " ")
			return true;
	}

	return false;
}

bool TicTacToe4::check_row_win() const
{
	for (int i = 0; i < 12; i += 4)
	{
		if (pegs[i].val == pegs[i + 1].val && pegs[i].val == pegs[i + 2].val && 
			pegs[i].val == pegs[i + 3].val && pegs[i + 3].val != " ")
			return true;
	}

	return false;
}

bool TicTacToe4::check_diagonal_win() const
{
	if (pegs[0].val == pegs[5].val && pegs[5].val == pegs[10].val && pegs[10].val == pegs[15].val && 
		pegs[15].val != " ")
		return true;
	else if (pegs[12].val == pegs[9].val && pegs[9].val == pegs[6].val && pegs[6].val == pegs[3].val &&
		pegs[3].val != " ")
		return true;

	return false;
}

void TicTacToe4::display_board(std::ostream & out) const
{
	for (unsigned i = 0; i < pegs.size(); i += 4)
	{
		std::cout << pegs[i].val << "|" << pegs[i + 1].val << "|" << pegs[i + 2].val << "|" << pegs[i + 3].val << std::endl;
	}
	std::cout << x_win << o_win << c_win << std::endl;
}

void TicTacToe4::get_input(std::istream & in)
{
	int position;
	std::cout << "Enter position (1-16): ";
	in >> position;
	mark_board(position);
}

