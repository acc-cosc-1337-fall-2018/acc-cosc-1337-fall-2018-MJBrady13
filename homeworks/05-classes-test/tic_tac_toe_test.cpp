#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include"tic_tac_toe_board.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"


TEST_CASE("Test game over", "Game begins not over")
{
	TicTacToe3 board;
	REQUIRE(board.game_over() == false);

}

TEST_CASE("Test set first player X", "Start game with first player X")
{
	TicTacToe3 board;
	board.start_game("X");
	REQUIRE(board.get_player() == "X");

}

TEST_CASE("Test set first player O", "Start game with first player O")
{
	TicTacToe3 board;
	board.start_game("O");
	REQUIRE(board.get_player() == "O");
}

TEST_CASE("Test win by first column", "[X wins first column]")
{
	TicTacToe3 board;
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
	TicTacToe3 board;
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
	TicTacToe3 board;
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
	TicTacToe3 board;
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
	TicTacToe3 board;
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
	TicTacToe3 board;
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
	TicTacToe3 board;
	board.start_game("X");
	board.mark_board(1);//X 
	board.mark_board(4);//O 
	board.mark_board(5);//X 
	board.mark_board(2);//O 
	board.mark_board(9);//X 
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test other win diagonally", "[X wins from bottom right diagonally]")
{
	TicTacToe3 board;
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
	TicTacToe3 board;
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

//END TIC TAC TOE 3 TESTING

//BEGIN TIC TAC TOE 4 TESTING
TEST_CASE("Test game over 4", "Game begins not over")
{
	TicTacToe4 board;
	REQUIRE(board.game_over() == false);

}

TEST_CASE("Test set first player X 4", "Start game with first player X")
{
	TicTacToe4 board;
	board.start_game("X");
	REQUIRE(board.get_player() == "X");

}

TEST_CASE("Test set first player O 4", "Start game with first player O")
{
	TicTacToe4 board;
	board.start_game("O");
	REQUIRE(board.get_player() == "O");
}

TEST_CASE("Test win by first column 4", "[X wins first column]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(1);//X 
	board.mark_board(2);//O 
	board.mark_board(5);//X 
	board.mark_board(3);//O 
	board.mark_board(9);//X
	board.mark_board(4);//O
	board.mark_board(13);//X
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by second column 4", "[X wins second column]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(2);//X 
	board.mark_board(1);//O 
	board.mark_board(6);//X 
	board.mark_board(3);//O 
	board.mark_board(10);//X
	board.mark_board(4);//O
	board.mark_board(14);//X
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by third column 4", "[X wins third column]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(3);//X 
	board.mark_board(2);//O 
	board.mark_board(7);//X 
	board.mark_board(1);//O 
	board.mark_board(11);//X
	board.mark_board(4);//O
	board.mark_board(15);//X
	//X wins  

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by forth column 4", "[X wins third column]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(4);//X 
	board.mark_board(2);//O 
	board.mark_board(8);//X 
	board.mark_board(1);//O 
	board.mark_board(12);//X
	board.mark_board(3);//O
	board.mark_board(16);//X
	//X wins  

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by first row 4", "[X wins first row]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(1);//X 
	board.mark_board(7);//O 
	board.mark_board(2);//X 
	board.mark_board(5);//O 
	board.mark_board(3);//X
	board.mark_board(13);//O
	board.mark_board(4);//X
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by second row 4", "[X wins second row]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(5);//X 
	board.mark_board(1);//O 
	board.mark_board(6);//X 
	board.mark_board(9);//O 
	board.mark_board(7);//X
	board.mark_board(13);//O
	board.mark_board(8);//X
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by third row 4", "[X wins third row]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(9);//X 
	board.mark_board(7);//O 
	board.mark_board(10);//X 
	board.mark_board(5);//O 
	board.mark_board(11);//X
	board.mark_board(13);//O
	board.mark_board(12);//X
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win by forth row 4", "[X wins third row]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(13);//X 
	board.mark_board(7);//O 
	board.mark_board(14);//X 
	board.mark_board(5);//O 
	board.mark_board(15);//X
	board.mark_board(12);//O
	board.mark_board(16);//X
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test win diagonally 4", "[X wins from top left diagonally]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(1);//X 
	board.mark_board(4);//O 
	board.mark_board(6);//X 
	board.mark_board(2);//O 
	board.mark_board(11);//X
	board.mark_board(9);//O
	board.mark_board(16);//X
	//X wins 

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test other win diagonally 4", "[X wins from bottom right diagonally]")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(13);//X 
	board.mark_board(8);//O 
	board.mark_board(10);//X 
	board.mark_board(2);//O 
	board.mark_board(7);//X
	board.mark_board(9);//O
	board.mark_board(4);//X
	//X wins

	REQUIRE(board.game_over() == true);

}

TEST_CASE("Test no winner 4", "Board filled with no winner")
{
	TicTacToe4 board;
	board.start_game("X");
	board.mark_board(1);//X
	board.mark_board(2);//O
	board.mark_board(3);//X
	board.mark_board(4);//O
	board.mark_board(5);//X
	board.mark_board(7);//O
	board.mark_board(6);//X
	board.mark_board(9);//O
	board.mark_board(10);//X
	board.mark_board(8);//O
	board.mark_board(12);//X
	board.mark_board(11);//O
	board.mark_board(13);//X
	board.mark_board(14);//O
	board.mark_board(15);//X
	board.mark_board(16);//O
	//No Winner

	REQUIRE(board.game_over() == true);
}