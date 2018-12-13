#include "tic_tac_toe_3.h"
#include<iostream>
#include<string>

TicTacToe3::TicTacToe3() 
{
	for (int i = 0; i < 9; i++)
	{
		Peg peg;
		pegs.push_back(peg);
	}
}

TicTacToe3::TicTacToe3(std::vector<Peg> p) : TicTacToeBoard(p)
{
	int x = 0;
	int o = 0;
	string winner = " ";
	for (auto i : pegs)
	{
		if (i.val == "X")
		{
			x += 1;
		}
		else {
			o += 1;
		}

		if (x > o)
		{
			winner = "X";
		}
		else
		{
			winner = "O";
		}

		if (check_board_full() && check_row_win() == false && check_column_win() == false && check_diagonal_win() == false)
		{
			winner = "Tie";
		}
	}
}


void TicTacToe3::display_board(std::ostream& out) const
{
	for (unsigned i = 0; i < pegs.size(); i += 3)
	{
		out << pegs[i].val << "|" << pegs[i + 1].val << "|" << pegs[i + 2].val << std::endl;
	}
	out << x_win << o_win << c_win << std::endl;
}

void TicTacToe3::get_input(std::istream & in)
{
	int position;
	std::cout << "Enter position (1-9): ";
	in >> position;
	mark_board(position);
}

bool TicTacToe3::check_column_win() const
{
	if (pegs[0].val == "X" && pegs[3].val == "X" && pegs[6].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[1].val == "X" && pegs[4].val == "X" && pegs[7].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[2].val == "X" && pegs[5].val == "X" && pegs[8].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[0].val == "O" && pegs[3].val == "O" && pegs[6].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	if (pegs[1].val == "O" && pegs[4].val == "O" && pegs[7].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	if (pegs[2].val == "O" && pegs[5].val == "O" && pegs[8].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	return false;
}

bool TicTacToe3::check_row_win() const
{
	if (pegs[0].val == "X" && pegs[1].val == "X" && pegs[2].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[3].val == "X" && pegs[4].val == "X" && pegs[5].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[6].val == "X" && pegs[7].val == "X" && pegs[8].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[0].val == "O" && pegs[1].val == "O" && pegs[2].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	if (pegs[3].val == "O" && pegs[4].val == "O" && pegs[5].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	if (pegs[6].val == "O" && pegs[7].val == "O" && pegs[8].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	return false;
}

bool TicTacToe3::check_diagonal_win() const
{
	if (pegs[0].val == "X" && pegs[4].val == "X" && pegs[8].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[6].val == "X" && pegs[4].val == "X" && pegs[2].val == "X")
	{
		std::cout << "X Wins!" << std::endl;
		return true;
	}
	if (pegs[0].val == "O" && pegs[4].val == "O" && pegs[8].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	if (pegs[6].val == "O" && pegs[4].val == "O" && pegs[2].val == "O")
	{
		std::cout << "O Wins!" << std::endl;
		return true;
	}
	return false;
}
