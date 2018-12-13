#include "tic_tac_toe_data.h"
#include<iostream>
#include<vector>

vector<std::unique_ptr<TicTacToeBoard>> TicTacToeData::get_games()
{
	std::vector < std::unique_ptr<TicTacToeBoard>> boards;
	std::ifstream save_file(file_name);
	std::string file_line;

	if (save_file.is_open())
	{
		while (getline(save_file, file_line))
		{
			std::vector<Peg> pegs;
			for (auto i : file_line)
			{
				std::string val(1, i);
				pegs.push_back(Peg(val));
			}

			std::unique_ptr<TicTacToeBoard> board;

			if (pegs.size() == 9)
			{
				boards.push_back(std::make_unique<TicTacToe3>(pegs));
			}
			else
			{
				boards.push_back(std::make_unique<TicTacToe4>(pegs));
			}
		}

		save_file.close();
	}

	return games;
}

void TicTacToeData::save_pegs(std::vector<Peg>& pegs)
{
	std::ofstream file(file_name, std::ios::app);
	for (auto i : pegs)
	{
		file << i.val;
	}
	file << "\n";

	file.close();
}
