#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include<string>
#include<vector>
#include"peg.h"

class TicTacToeBoard
{
public:
	TicTacToeBoard() = default;
	TicTacToeBoard(int x, int o, int c) : x_win(x), o_win(o), c_win(c) {}

	bool game_over();
	std::string get_player();
	//std::string get_winner();
	void mark_board(int position);
	void start_game(std::string player);
	int position;
	const std::vector<Peg>& get_pegs()
	
	
	friend std::istream& operator >>(std::istream& in, TicTacToeBoard& d);
	friend std::ostream& operator <<(std::ostream& out, const TicTacToeBoard& d);
	
protected:
	bool check_board_full() const;	
	virtual bool check_column_win() const =0;
	virtual bool check_diagonal_win() const = 0;
	virtual bool check_row_win() const =0;
	void clear_board();
	virtual void get_input(std::istream& in) = 0;
	virtual void display_board(std::ostream& out) const = 0;	
	void set_next_player();
		
	std::vector<Peg> pegs;
	std::string next_player;
	std::string winner;
	
	

};

#endif // !TIC_TAC_TOE_BOARD_H