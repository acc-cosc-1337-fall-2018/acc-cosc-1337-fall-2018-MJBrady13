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
	int position;
	void start_game(std::string player);
	void mark_board(int position);
	std::string get_player();
	friend std::istream& operator >>(std::istream& in, TicTacToeBoard& d);
	friend std::ostream& operator <<(std::ostream& out, const TicTacToeBoard& d);
	
protected:
	void set_next_player();
	virtual bool check_column_win() const =0;
	virtual bool check_row_win() const =0;
	virtual bool check_diagonal_win() const =0;
	virtual void display_board(std::ostream& out) const = 0;
	virtual void get_input(std::istream& in) = 0;

	bool check_board_full() const;
	void clear_board();	
	std::vector<Peg> pegs;
	std::string next_player;
	int x_win{0};
	int o_win{0};
	int c_win{0};
	

};

#endif // !TIC_TAC_TOE_BOARD_H