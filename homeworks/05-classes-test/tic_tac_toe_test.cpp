#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include"tic_tac_toe_board.h"


TEST_CASE("Test game over", "Game begins not over")
{
	TicTacToeBoard board;
	REQUIRE(board.game_over() == false);

}

TEST_CASE("Test set first player X", "Start game with first player X")
{
	TicTacToeBoard board;
	board.start_game("X");
	REQUIRE(board.get_player() == "X");

}

TEST_CASE("Test set first player O", "Start game with first player O")
{
	TicTacToeBoard board;
	board.start_game("O");
	REQUIRE(board.get_player() == "O");
}

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

TEST_CASE("Test win by second column", "[X wins second column]")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(2);//X 
	board.mark_board(1);//O 
	board.mark_board(5);//X 
	board.mark_board(4);//O 
	board.mark_board(8);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by third column", "[X wins third column]")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(3);//X 
	board.mark_board(2);//O 
	board.mark_board(6);//X 
	board.mark_board(5);//O 
	board.mark_board(9);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by first row", "[X wins first row]")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(1);//X 
	board.mark_board(4);//O 
	board.mark_board(2);//X 
	board.mark_board(5);//O 
	board.mark_board(3);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by second row", "[X wins second row]")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(4);//X 
	board.mark_board(1);//O 
	board.mark_board(5);//X 
	board.mark_board(2);//O 
	board.mark_board(6);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by third row", "[X wins third row]")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(7);//X 
	board.mark_board(4);//O 
	board.mark_board(8);//X 
	board.mark_board(5);//O 
	board.mark_board(9);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win diagonally", "[X wins from top left diagonally]")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(1);//X 
	board.mark_board(4);//O 
	board.mark_board(5);//X 
	board.mark_board(2);//O 
	board.mark_board(9);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win diagonally", "[X wins from bottom right diagonally]")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(7);//X 
	board.mark_board(4);//O 
	board.mark_board(5);//X 
	board.mark_board(2);//O 
	board.mark_board(3);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test no winner", "Board filled with no winner")
{
	TicTacToeBoard board;
	board.start_game("X");
	board.mark_board(1);//X
	board.mark_board(2);//O
	board.mark_board(3);//X
	board.mark_board(4);//O
	board.mark_board(5);//X
	board.mark_board(7);//O
	board.mark_board(6);//X
	board.mark_board(9);//O
	board.mark_board(8);//X
	//No Winner

	REQUIRE(board.game_over() == true);
}