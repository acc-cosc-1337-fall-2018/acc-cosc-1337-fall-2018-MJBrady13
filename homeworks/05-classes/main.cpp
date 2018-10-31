#include<iostream>
#include"tic_tac_toe_board.h"
#include<vector>
#include"tic_tac_toe_3.h"

using namespace std;

int main()
{
	TicTacToe3 a;
	TicTacToe3 b;
	TicTacToe3 c;
	
	cout << "Game for board 'a': " << endl;
	string first_player;
	cout << "Who goes first? (X or O): ";
	cin >> first_player;
	a.start_game(first_player);
	while (a.game_over() == false)
	{
		cout << "Player " << a.get_player() << " make your mark.(1-9)" << endl;
		cin >> a.position;
		a.mark_board(a.position);
		cout << a;
	}

	cout << "Game for board 'b': " << endl;
	cout << "Who goes first? (X or O): ";
	cin >> first_player;
	b.start_game(first_player);
	while (b.game_over() == false)
	{
		cout << "Player " << b.get_player() << " make your mark.(1-9)" << endl;
		cin >> b.position;
		b.mark_board(b.position);
		cout << b;
	}

	cout << "Game for board 'c': " << endl;
	cout << "Who goes first? (X or O): ";
	cin >> first_player;
	c.start_game(first_player);
	while (c.game_over() == false)
	{
		cout << "Player " << c.get_player() << " make your mark.(1-9)" << endl;
		cin >> c.position;
		c.mark_board(c.position);
		cout << c;
	}
	
	vector <TicTacToe3> vect_of_boards{ a, b, c };
	TicTacToe3 result;
	for (auto i : vect_of_boards)
	{
		result = result + i;
	}

	cout << result;
	return 0;
}

/*void TicTacToeBoard::display_board()
{
	cout << pegs[0] << "|" << pegs[1] << "|" << pegs[2] << "\n";
	cout << pegs[3] << "|" << pegs[4] << "|" << pegs[5] << "\n";
	cout << pegs[6] << "|" << pegs[7] << "|" << pegs[8] << "\n";	
}*/

/*string again = "y";
	cout << "Welcome to Tic-Tac-Toe" << endl;
	while (again == "y")
	{
		TicTacToeBoard board;
		string first_player;
		cout << "Who goes first? (X or O): ";
		cin >> first_player;
		board.start_game(first_player);
		while (board.game_over() == false)
		{
			cout << "Player " << board.get_player() << " make your mark.(1-9)" << endl;
			int move;
			cin >> move;
			board.mark_board(move);
			
		}
		cout << "Game Over!" << endl;
		cout << "Do you want to play again?: ";
		cin >> again;
	}*/