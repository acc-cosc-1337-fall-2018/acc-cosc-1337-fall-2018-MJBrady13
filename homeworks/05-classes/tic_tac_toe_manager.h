#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include<vector>
#include<string>
#include<iostream>





#include "tic_tac_toe_board.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"

enum GameType
{
	tic_tac_toe_3,
	tic_tac_toe_4
};

class TicTacToeManager
{
public:
	TicTacToeManager();
	std::unique_ptr<TicTacToeBoard> get_game(GameType game_type);
	void save_game(unique_ptr<TicTacToeBoard> board);
	friend std::ostream& operator <<(std::ostream& out, const TicTacToeManager& manager);
private:
	vector<std::unique_ptr<TicTacToeBoard>> boards;
	int c_win{ 0 };
	int o_win{ 0 };
	int x_win{ 0 };
	void update_winner_count(string& winner);
		
	
};


#endif // !TIC_TAC_TOE_MANAGER_H