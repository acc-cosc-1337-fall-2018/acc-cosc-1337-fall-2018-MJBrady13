#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager()
{
	boards = tic_tac_toe_data.get_games();

}

std::unique_ptr<TicTacToeBoard> TicTacToeManager::get_game(GameType game_type)
{
	if (game_type == tic_tac_toe_4)
	{
		return std::make_unique<TicTacToe4>();
	}
	else
	{
		return std::make_unique<TicTacToe3>();
	}
	
}

void TicTacToeManager::save_game(unique_ptr<TicTacToeBoard> board)
{
	update_winner_count(board->get_winner());
	boards.push_back(std::move(board));
}

const std::vector<std::unique_ptr<TicTacToeBoard>>& TicTacToeManager::get_games()
{
	// TODO: insert return statement here
}

void TicTacToeManager::get_winner_totals(int & x, int & o, int & c)
{
	x = x_win;
	o = o_win;
	c = c_win;
}

void TicTacToeManager::update_winner_count(string & game_winner)
{
	if (game_winner == "X")
	{
		x_win += 1;
	}
	else if (game_winner == "O")
	{
		o_win += 1;
	}
	else
	{
		c_win += 1;
	}
}

std::ostream & operator<<(std::ostream & out, const TicTacToeManager & manager)
{
	for (auto &board : manager.boards)
	{
		out << *board;
	}

	out << "Tic-Tac-Toe History\n";
	out << "X wins: " << manager.x_win << "O wins: " << manager.o_win << "Ties: " << manager.c_win;

	return out;
}
