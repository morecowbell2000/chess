#include <string>
#include <iostream>
#include "board.h"

using namespace std;

int 
main(int argc, char *argv)
{

	Board *board = new Board();

	

	board->print();
	string move;


	while (board->playing() == true)
	{
		if (board->isWhiteMove())
			cout << "\n\n***White*** Please make a move\nMove: ";
		else
			cout << "\n\n***Black*** Please make a move\nMove: ";

		cin >> move;

		board->move(move);

		board->print();

	}
}