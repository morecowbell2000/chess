#include <string>
#include <iostream>
#include "board.h"
//to fix any build errors between versions simply retarget the solution. Right click it, and click re-target


using namespace std;

int 
main(int argc, char *argv)
{
	Board *board = new Board();

	board->print();
	string move;

	while (board->playing() == true)
	{
		if (board->isWhiteMove()) {
			if (board->isWhiteCheck()) {
				cout << "\n\n***WHITE*** YOUR KING IS IN CHECK\nMove: ";
			}
			else {
				cout << "\n\n***White*** Please make a move\nMove: ";
			}
		}
		else {
			if (board->isBlackCheck()) {
				cout << "\n\n***BLACK*** YOUR KING IS IN CHECK\nMove: ";
			}
			else {
				cout << "\n\n***Black*** Please make a move\nMove: ";
			}
		}

		cin >> move;

		board->move(move);

		board->print();

	}
}