#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "tic_tac_toe_board.h"

class TicTacToeData
{
public:
	std::vector<std::unique_ptr<TicTacToeBoard>> get_games();
	void save_pegs(std::vector<Peg>& pegs);
private:
	std::vector<std::string> pegs;
	const std::string file_name{ "tic_tac_toe.dat" };
};

#endif //TIC_TAC_TOE_DATA_H