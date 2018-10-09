#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include"tic_tac_toe_board.h"




TEST_CASE("Test win by first column", "[X wins first column]")
{ 
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(1);//X 
	board.mark_board(2);//O 
	board.mark_board(4);//X 
	board.mark_board(5);//O 
	board.mark_board(7);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}