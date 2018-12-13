#include<iostream>
#include"tic_tac_toe_board.h"
#include<vector>
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
#include"tic_tac_toe_manager.h"


int main() 
{
	std::unique_ptr<TicTacToeManager> manager = std::make_unique<TicTacToeManager>();
	std::string keep_playing = "y";
	std::cout << "Welcome to Tic-Tac-Toe \n" << std::endl;
		
	while (keep_playing == "y")
	{
		std::string game_choice;
		std::cout << "Please choose a game.\n" << "Press 4 to play 4x4 Tic-Tac-Toe-Foe \n"
			<< "or anything else for Classic 3x3 Tic-Tac-Toe.\n" << std::endl;
		std::cin >> game_choice;
		std::unique_ptr<TicTacToeBoard> board;
		if (game_choice == "4")
		{
			board = manager->get_game(tic_tac_toe_4);
			
		}
		else
		{
			board = manager->get_game(tic_tac_toe_3);
			
		}
		std::string first_player;
		std::cout << "Who goes first? (X or O): ";
		std::cin >> first_player;
		board->start_game(first_player);

		while (board.game_over() == false)
		{
			std::cout << "Player " << board.get_player() << "'s turn: " << std::endl;
			std::cin >> board;
			std::cout << board << std::endl;

		}

		manager->save_game(move(board));

		std::cout << "Game Over!" << std::endl;
		std::cout << "Do you want to keep playing?('y' for yes, anything else for no): ";
		std::cin >> keep_playing;
	}

	std::cout << *manager;
	return 0;
}