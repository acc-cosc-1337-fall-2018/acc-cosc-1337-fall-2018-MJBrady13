#ifndef TIC_TAC_TOE_4_H
#define TIC_TAC_TOE_4_H

#include"tic_tac_toe_board.h"

class TicTacToe4 : public TicTacToeBoard
{
public:
	TicTacToe4();
	TicTacToe4(std::vector<Peg> p);
protected:
	bool check_column_win() const override;
	bool check_diagonal_win() const override;
	bool check_row_win() const override;	
	void display_board(std::ostream& out) const override;
	void get_input(std::istream& in) override;
};

#endif // !TIC_TAC_TOE_4_H