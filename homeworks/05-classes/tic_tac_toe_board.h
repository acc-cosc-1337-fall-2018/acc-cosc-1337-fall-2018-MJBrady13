#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include<string>
#include<vector>
using namespace std;

class TicTacToeBoard
{
public:
	TicTacToeBoard() = default;
	TicTacToeBoard(int x, int o, int c) : x_win(x), o_win(o), c_win(c) {}

	bool game_over();
	int position;
	void start_game(string player);
	void mark_board(int position);
	string get_player();
	friend istream& operator >>(istream& in, TicTacToeBoard& d);
	friend ostream& operator <<(ostream& out, const TicTacToeBoard& d);
	friend TicTacToeBoard operator + (const TicTacToeBoard& b, const TicTacToeBoard& b2);

private:
	void set_next_player();
	bool check_column_win();
	bool check_row_win();
	bool check_diagonal_win();
	void clear_board();
	bool check_board_full();
	vector<string> pegs{ 9," "};
	string next_player;
	int x_win = 0;
	int o_win = 0;
	int c_win = 0;
	

};

#endif // !TIC_TAC_TOE_BOARD_H