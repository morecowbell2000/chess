#include "board.h"
#include <iostream>
//commit test

using namespace std;

char gInitBoard[][8] = {
							{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
							{ 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
							{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
							{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
							{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
							{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
							{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
							{ 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
};





//Flip X and Y because of definition above
Board::Board() : mIsWhite(true)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			mBoard[j][i] = gInitBoard[i][j];
		}
	}
}

Board::~Board()
{

}

bool
Board::isLegalKing(char i_piece, Location &i_src, Location &i_dst) {
	if (isLegalRook(i_piece, i_src, i_dst) == true || isLegalBishop(i_piece, i_src, i_dst) == true) {
		if (!(0 <= abs(i_src.x - i_dst.x) < 2) || !(0 <= abs(i_src.y - i_dst.y) < 2)) {
			return false;
		}
		else 
		{
			return true;
		}
	}
	else 
	{
		return false;
	}
}


bool 
Board::isLegalQueen(char i_piece, Location &i_src, Location &i_dst) {
	if (isLegalRook(i_piece, i_src, i_dst)) {
		return true;
	}
	else if (isLegalBishop(i_piece, i_src, i_dst)) {
		return true;
	}
	else {
		return false;
	}
}

bool
Board::isLegalRook(char i_piece, Location &i_src, Location &i_dst) {
	if (abs(i_src.x - i_dst.x) > 0 && i_src.y - i_dst.y == 0) {
		return true;
	}
	else if (abs(i_src.y - i_dst.y) > 0 && i_src.x - i_dst.x == 0) {
		return true;
	}
	else {
		return false;
	}

	
}


bool
Board::isLegalKnight(char i_piece, Location &i_src, Location &i_dst) 
{
	//if (isKnight(i_piece)) 
	//{
		if (abs(i_dst.x - i_src.x) == 2 && abs(i_dst.y - i_src.y) == 1) 
		{
			return true;
		}
		else if (abs(i_dst.y - i_src.y) == 2 && abs(i_dst.x - i_src.x) == 1) {
			return true;
		}
		else 
		{
			return false;
		}
	//}
	//else {
		//return false;
	//}
}


bool
Board::isLegalBishop(char i_piece, Location &i_src, Location &i_dst) {

	//int diff;
		
	if (abs((i_dst.x - i_src.x) / (i_dst.y - i_src.y)) != 1) {
		return false;
	}
	else {
		return true;
	}	


}


bool 
Board::isLegal(char i_piece,  Location &i_src, Location &i_dst) {
	
	


	if (isPawn(i_piece)) 
	{
		int diff;
		if (isWhite(i_piece))
		{

			

			//same column
			if (i_dst.x - i_src.x == 0) 
			{
				diff = i_dst.y - i_src.y;
				if (diff > 2 || diff <= 0)
					return false;

				if (mBoard[i_dst.x][i_dst.y] != ' ') {
					return false;
				}


				if (diff == 2 && i_src.y == 1) {
					if (mBoard[i_src.x][i_src.y + 1] != ' ') {
						return false;
					}

					return true;
				}
				if (diff == 1)
					return true;
			}
			else 
			{
				return  false;
			}


		}
		else
		{

			if (i_dst.x - i_src.x == 0) {

				diff = i_src.y - i_dst.y;
				if (diff > 2 || diff <= 0)
					return false;

				if (mBoard[i_dst.x][i_dst.y] != ' ') {
					return false;
				}

				if (diff == 2 && i_src.y == 6) {
					if (mBoard[i_src.x][i_src.y - 1] != ' ') {
						return false;
					}

					return true;
				}

				if (diff == 1)
					return true;

			}
			else {
				return false;
			}
		}



	}
	else {
		if (isBishop(i_piece)) {
			return isLegalBishop(i_piece, i_src, i_dst);
		}
		if (isKnight(i_piece)) {
			return isLegalKnight(i_piece, i_src, i_dst);
		}
		if (isRook(i_piece)) {
			return isLegalRook(i_piece, i_src, i_dst);
		}
		if (isQueen(i_piece)) {
			return isLegalQueen(i_piece, i_src, i_dst);
		}
		if (isKing(i_piece)) {
			return isLegalKing(i_piece, i_src, i_dst);
		}
	}

	return false;

	
}



bool 
Board::search(char i_piece, Location &o_src, Location &i_dst ) {


	for (int y = 0; y < 8; y++) 
	{
		for (int x = 0; x < 8; x++) 
		{
			if (mBoard[x][y] == i_piece) 
			{
				o_src.x = x;
				o_src.y = y;
				if (isLegal(i_piece, o_src, i_dst)) {
					return true;
				}
			}
		}
	}

	return false;
}





int
Board::toGrid(char x)
{

	if (x >= 'a' && x <= 'h') {
		return x - 'a';
	}


	return -1;
}




bool
Board::move(const std::string &i_move) 
{
	int xMoveTo;
	if (i_move.length() == 2) 
	{
		xMoveTo = toGrid(i_move[0]);
		Location dst, src;
		dst.x = xMoveTo;
		dst.y = i_move[1] -  '1';
		if (search(mIsWhite ? 'p' : 'P', src, dst))
		{
			mBoard[dst.x] [dst.y] = mBoard[src.x][src.y];
			mBoard[src.x][src.y] = ' ';

			mIsWhite = !mIsWhite;
		}
		else {
			cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
		}
	}
	else if (i_move.length() == 3) 
	{
		Location dst, src;
		dst.x = toGrid(i_move[1]);
		dst.y = i_move[2] - '1';

		if (search(mIsWhite ? tolower(i_move[0]) : toupper(i_move[0]), src, dst)) {
			mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
			mBoard[src.x][src.y] = ' ';

			mIsWhite = !mIsWhite;
		}
		else {
			cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
		}


	}
	else if(i_move.length() == 5)
	{
		
		
		Location dst, src;

		dst.x = toGrid(i_move[3]);
		dst.y = i_move[4] - '1';

		src.x = toGrid(i_move[0]);
		src.y = i_move[1] - '1';

		char piecetoMove = mBoard[src.x][src.y];

		if ((mIsWhite == true && islower(piecetoMove)) || (mIsWhite == false && isupper(piecetoMove)))
		{

			if (isLegal(piecetoMove, src, dst))
			{

				mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
				mBoard[src.x][src.y] = ' ';


				mIsWhite = !mIsWhite;
			}
			else {
				cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
			}
		}
				



		
	}
	else {
		return false;
	}
	
	

	
	return true;


}




void 
Board::print()
{
	int i, j;
	cout << "---------------------------------\n";
	for (i = 7; i >= 0; i--)
	{
		for (j = 0; j < 8; j++)
		{
			
			cout << "| " << mBoard[j][i] << " ";
		}
		cout << "|\n";
		cout << "---------------------------------\n";
	}

}



