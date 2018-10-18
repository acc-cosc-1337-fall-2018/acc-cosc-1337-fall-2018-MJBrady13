#include<iostream>
#include"tic_tac_toe_board.h"

using namespace std;

int main()
{
	string again = "y";
	cout << "Welcome to Tic-Tac-Toe" << endl;
	while (again == "y")
	{
		TicTacToeBoard board;
		string first_player;
		cout << "Who goes first? (X or O): ";
		cin >> first_player;
		board.start_game(first_player);
		board.display_board();
		while (board.game_over() == false)
		{
			cout << "Player " << board.get_player() << " make your mark.(1-9)" << endl;
			int move;
			cin >> move;
			board.mark_board(move);
			board.display_board();
		}
		cout << "Game Over!" << endl;
		cout << "Do you want to play again?: ";
		cin >> again;
	}
	return 0;
}