#include "board.h"
#include <iostream>
#include <ctype.h>

//to fix any build errors between versions simply retarget the solution. Right click it, and click re-target

using namespace std;
char gInitBoard[][8] = {
							{ 'r', 'n', 'b', ' ', 'k', ' ', 'n', 'r' },
							{ 'p', 'p', 'p', 'p', ' ', 'p', 'p', 'p' },
							{ ' ', ' ', ' ', ' ', 'p', 'q', ' ', ' ' },
							{ ' ', ' ', 'b', ' ', ' ', ' ', ' ', ' ' },
							{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
							{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
							{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
							{ 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
};





//Flip X and Y because of definition above
Board::Board()
{
	playstate = true;
	//initialize variables
	mIsWhite = true;
	blackCheck = false;
	whiteCheck = false;
	
	wKmoved = false;
	bKmoved = false;
	wrRmoved = false;
	wlRmoved = false;
	brRmoved = false;
	blRmoved = false;
	generic.turn = -1;
	generic.movedTwo = false;
	generic.dst.x = 9;
	generic.dst.y = 9;
	generic.doit = false;
	turnNumber = 0;



	//initialize board
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
Board::whiteInCheck(int x) {
	//make x zero to check for white, make it 1 for black. This redundifies the blackInCheck function but I'm still keeping it
	/*
	char king = 'k';
	if (x == 1) {
		king == 'K';
	}

	Location src;
	src.x = -1;
	src.y = -1;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (mBoard[x][y] == king)
			{
				src.x = x;
				src.y = y;
			}
		}
	}

	if (src.x || src.y == -1) {
		cout << "\n\nThere is a king missing on your board?\n\n";
	}

	

	for (int i = 0; i < 7; i++) {
		char piece = mBoard[src.x][i];
		if (king == 'K' && isWhite(piece) && (isRook(piece) || isQueen(piece))) 
		{
			return true;
		}
		else if (king == 'k' && isBlack(piece) && (isRook(piece) || isQueen(piece)))
		{
			return true;
		}
	}
	
	for (int i = 0; i < 7; i++) {
		char piece = mBoard[i][src.y];
		if (king == 'K' && isWhite(piece) && (isRook(piece) || isQueen(piece)))
		{
			return true;
		}
		else if (king == 'k' && isBlack(piece) && (isRook(piece) || isQueen(piece)))
		{
			return true;
		}
	}

	for (int i = 0; i < 7; i++) {
		if ((src.x + i > 7 || src.y + i > 7)) {
			break;
		}
		char piece = mBoard[src.x + i][src.y + i];
		if (king == 'K' && isWhite(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
		if (king == 'k' && isBlack(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
	}
	for (int i = 0; i < 7; i++) {
		if ((src.x - i < 0 || src.y - i < 0)) {
			break;
		}
		char piece = mBoard[src.x - i][src.y - i];
		if (king == 'K' && isWhite(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
		if (king == 'k' && isBlack(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
	}
	for (int i = 0; i < 7; i++) {
		if ((src.x + i > 7 || src.y - i < 0)) {
			break;
		}
		char piece = mBoard[src.x + i][src.y - i];
		if (king == 'K' && isWhite(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
		if (king == 'k' && isBlack(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
	}
	for (int i = 0; i < 7; i++) {
		if ((src.x - i < 0 || src.y + i > 7)) {
			break;
		}
		char piece = mBoard[src.x - i][src.y + i];
		if (king == 'K' && isWhite(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
		if (king == 'k' && isBlack(piece) && (isBishop(piece) || isQueen(piece))) {
			return true;
		}
	}*/
Location src, kingloc;

kingloc.x = -1;
kingloc.y = -1;
if (x == 0) {
	for (int g = 0; g < 8; g++) {
		for (int z = 0; z < 8; z++) {
			if (mBoard[z][g] == 'k') {
				kingloc.x = z;
				kingloc.y = g;
				break;
			}
		}
		if (kingloc.x != -1 && kingloc.y != -1) {
			break;
		}
	}


	
		for (int i = 0; i < 8; i++) {
			for (int q = 0; q < 8; q++) {
				char piece = mBoard[q][i];
				if (piece != ' ' && isBlack(piece) && piece != 'K') {
					src.x = q;
					src.y = i;
					if (isLegal(piece, src, kingloc))
					{
						return true;
					}

				}
			}
		}
	
}
else {
	for (int g = 0; g < 8; g++) {
		for (int z = 0; z < 8; z++) {
			if (mBoard[z][g] == 'K') {
				kingloc.x = z;
				kingloc.y = g;
				break;
			}
		}
		if (kingloc.x != -1 && kingloc.y != -1) {
			break;
		}
	}
	for (int i = 0; i < 8; i++) 
	{
		for (int q = 0; q < 8; q++) 
		{
			char piece = mBoard[q][i];
			if (piece != ' ' && isWhite(piece) && piece != 'k')
			{
				src.x = q;
				src.y = i;
				if(isLegal(piece, src, kingloc))
				{
					return true;
				}

			}
		}
	}
}


	
	return false;
}
bool
Board::blackInCheck() {
	
	return whiteInCheck(1);
}

bool
Board::isLegalKing(char i_piece, Location &i_src, Location &i_dst) {
	//doesn't allow landing on own pieces.
	if ((mIsWhite && islower(mBoard[i_dst.x][i_dst.y])) || (!mIsWhite && isupper(mBoard[i_dst.x][i_dst.y]))) {
		return false;
	}
	else 
	{
		if (isLegalRook(i_piece, i_src, i_dst) == true || isLegalBishop(i_piece, i_src, i_dst) == true) {
			if (!((0 <= abs(i_src.x - i_dst.x) && abs(i_src.x - i_dst.x) < 2)) || !((0 <= abs(i_src.y - i_dst.y) && abs(i_src.y - i_dst.y) < 2))) {
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
}


bool 
Board::isLegalQueen(char i_piece, Location &i_src, Location &i_dst) {
	//doesn't allow landing on own pieces.
	if ((mIsWhite && islower(mBoard[i_dst.x][i_dst.y])) || (!mIsWhite && isupper(mBoard[i_dst.x][i_dst.y]))) {
		return false;
	}
	else
	{
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
}

bool
Board::isLegalRook(char i_piece, Location &i_src, Location &i_dst) {
	//doesn't allow landing on own pieces.
	if ((mIsWhite && islower(mBoard[i_dst.x][i_dst.y])) || (!mIsWhite && isupper(mBoard[i_dst.x][i_dst.y]))) {
		return false;
	}
	else
	{
		
		if (abs(i_src.x - i_dst.x) > 0 && i_src.y - i_dst.y == 0) {
			for (int z = 1; z < abs(i_src.x - i_dst.x); z++) 
			{
				
				if (i_src.x - i_dst.x < 0) {
					if (mBoard[i_src.x + (z)][i_src.y] != ' ') {
						return false;
					}
				}
				else {
					if (mBoard[i_src.x - (z)][i_src.y] != ' ') {
						return false;
					}
				}
			}
			return true;
		}
		else if (abs(i_src.y - i_dst.y) > 0 && i_src.x - i_dst.x == 0) {
			for (int z = 1; z < abs(i_src.y - i_dst.y); z++) {
				if (i_src.y - i_dst.y > 0) {
					if (mBoard[i_src.x][i_src.y - (z)] != ' ') {
						return false;
					}
				}
				else {
					if (mBoard[i_src.x][i_src.y + (z)] != ' ') {
						return false;
					}
				}
			}
			
			return true;
		}
		else {
			return false;
		}
	}
	
}


bool
Board::isLegalKnight(char i_piece, Location &i_src, Location &i_dst) 
{
	//if (isKnight(i_piece)) 
	//{
	//doesn't allow landing on own pieces.
	if ((mIsWhite && islower(mBoard[i_dst.x][i_dst.y])) || (!mIsWhite && isupper(mBoard[i_dst.x][i_dst.y]))) {
		return false;
	}
	else
	{
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
	}
	//}
	//else {
		//return false;
	//}
}


bool
Board::isLegalBishop(char i_piece, Location &i_src, Location &i_dst) {
	Location test;
	int k;
	//int diff;
	//doesn't allow landing on own pieces.
	if ((mIsWhite && islower(mBoard[i_dst.x][i_dst.y])) || (!mIsWhite && isupper(mBoard[i_dst.x][i_dst.y]))) {
		return false;
	}
	else
	{
        if(i_dst.y - i_src.y == 0)
        {
            if(i_dst.x - i_src.x != 0)
            {
                return false;
            }
        }
        else
        {
		if (abs((i_dst.x - i_src.x) / (i_dst.y - i_src.y)) != 1) 
		{
			return false;
		}
		else
		{
				for (k = 1; k < abs(i_dst.x - i_src.x); k++)
				{
					if (i_src.x - i_dst.x > 0) {
						//are we going left
						if (i_src.y - i_dst.y < 0) {
							//up
							
							test.x = i_src.x - (k+1);
							test.y = i_src.y + (1 + k);

							if (mBoard[test.x][test.y] != ' ') {
								if (test.x == i_dst.x && test.y == i_dst.y) {

								}
								else {
									return false;
								}
							}
						}
						else {
							//or down
							test.x = (i_src.x - (k))+1;
							test.y = (i_src.y - (k))+1;

							if (mBoard[test.x][test.y] != ' ') {
								if (test.x == i_dst.x && test.y == i_dst.y) {

								}
								else {
									return false;
								}
							}
						}
					}
					else {
						//or going right
						if (i_src.y - i_dst.y < 0) {
							//up
							test.x = i_src.x + k;
							test.y = i_src.y + k;
							if (mBoard[test.x][test.y] != ' ') {
								if (test.x == i_dst.x && test.y == i_dst.y) {

								}
								else {
									return false;
								}
							}
						}
						else {
							//or down
							test.x = i_src.x + (k - 1);
							test.y = i_src.y - (1 + k);


							if (mBoard[test.x][test.y] != ' ') {
								if (test.x == i_dst.x && test.y == i_dst.y) {

								}
								else {
									return false;
								}
							}
						}
					}
				
				}
			return true;
		}
	}
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
					generic.movedTwo = true;
					generic.turn = turnNumber;
					generic.dst.x = i_dst.x;
					generic.dst.y = i_dst.y;
					return true;
				}
				if (diff == 1)
					return true;
			}
			else if(isBlack(mBoard[i_dst.x][i_dst.y]) && mBoard[i_dst.x][i_dst.y] != ' ') 
			{
				if (abs(i_dst.x - i_src.x) == 1 && i_dst.y - i_src.y == 1) {
					return true;
				}
				else 
				{
					return false;
				}
			}
			else if (isBlack(mBoard[i_dst.x][i_dst.y - 1]) && mBoard[i_dst.x][i_dst.y - 1] != ' ' && turnNumber - generic.turn == 1 && generic.dst.x == i_dst.x && generic.dst.y == i_dst.y - 1 && mBoard[i_dst.x][i_dst.y] == ' ') {
				//mBoard[i_dst.x][i_dst.y - 1] = ' ';
				generic.doit = true;
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
					generic.movedTwo = true;
					generic.turn = turnNumber;
					generic.dst.x = i_dst.x;
					generic.dst.y = i_dst.y;
					return true;
				}

				if (diff == 1)
					return true;

			}
			else if (isWhite(mBoard[i_dst.x][i_dst.y]) && mBoard[i_dst.x][i_dst.y] != ' ') {
				if (abs(i_dst.x - i_src.x) == 1 && i_dst.y - i_src.y == -1) {
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (isWhite(mBoard[i_dst.x][i_dst.y + 1]) && mBoard[i_dst.x][i_dst.y + 1] != ' ' && turnNumber - generic.turn == 1 && generic.dst.x == i_dst.x && generic.dst.y == i_dst.y + 1 && mBoard[i_dst.x][i_dst.y] == ' ') {
				//mBoard[i_dst.x][i_dst.y + 1] = ' ';
				generic.doit = true;
				return true;
			}
			else
			{
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

void 
Board::mBoardToSaveBoard(int g) { //1 = inverse, ie SaveBoard to Mboard
	
	if (g == 0) {
		for (int w = 0; w < 8; w++)
		{
			for (int z = 0; z < 8; z++)
			{
				SaveBoard[w][z] = mBoard[w][z];
			}
		}
	}
	if (g == 1) 
	{
		for (int w = 0; w < 8; w++)
		{
			for (int z = 0; z < 8; z++)
			{
				mBoard[w][z] = SaveBoard[w][z];
			}
		}
	}
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
		if (isWhiteCheck() || isBlackCheck()) 
		{
			if (search(mIsWhite ? 'p' : 'P', src, dst))
			{
				mBoardToSaveBoard(0);
				if (search(mIsWhite ? tolower(i_move[0]) : toupper(i_move[0]), src, dst))
				{
					if (generic.doit == true)
					{
						int passantMod;
						if (mIsWhite) {
							passantMod = -1;
						}
						else {
							passantMod = 1;
						}
						mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
						mBoard[src.x][src.y] = ' ';
						mBoard[dst.x][dst.y + passantMod] = ' ';
					}
					else {
						mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
						mBoard[src.x][src.y] = ' ';
					}
					if (mIsWhite) {
						if (whiteInCheck(0)) {
							cout << "\n\nWe already told you... Your king is in check\n\n Try AGAIN\n\n";
							mBoardToSaveBoard(1);
							return false;
						}
					}
					else {
						if (blackInCheck()) {
							cout << "\n\nWe already told you... Your king is in check\n\n Try AGAIN\n\n";
							mBoardToSaveBoard(1);
							return false;
						}
					}
					mBoardToSaveBoard(1);
				}
				if (!whiteInCheck(0) && !blackInCheck()) {
					mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
					mBoard[src.x][src.y] = ' ';

				}
			}
			else {
				cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
				return false;
			}
		
		}
		else
		{
			if (search(mIsWhite ? 'p' : 'P', src, dst))
			{
				if (generic.doit == true)
				{
					int passantMod;
					if (mIsWhite) {
						passantMod = -1;
					}
					else {
						passantMod = 1;
					}
					mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
					mBoard[src.x][src.y] = ' ';
					mBoard[dst.x][dst.y + passantMod] = ' ';
				}
				else {
					mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
					mBoard[src.x][src.y] = ' ';
				}
			}
			else {
				cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
				return false;
			}
		}
	}
	else if (i_move == "O-O" || i_move == "0-0")
	{
		if (mIsWhite)
		{
			if (wKmoved == true || wrRmoved == true)
			{
				cout << "\n\nyou've alread moved your king or rook.\n\n";
				return false;
			}
			else
			{
				if (mBoard[5][0] == ' ' && mBoard[6][0] == ' ' && whiteInCheck(0) == false)
				{
					mBoardToSaveBoard(0);
					mBoard[5][0] = 'k';
					mBoard[4][0] = ' ';
					if (whiteInCheck(0) == false)
					{
						mBoard[6][0] = 'k';
						mBoard[5][0] = ' ';
						mBoard[5][0] = 'r';
						mBoard[7][0] = ' ';
					}
					else
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;
					}
					if (whiteInCheck(0) == true)
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;

					}
				}
			}
		}
		else
		{
			if (bKmoved == true || brRmoved == true)
			{
				cout << "\n\nyou've alread moved your king or rook.\n\n";
				return false;
			}
			else
			{
				if (mBoard[5][7] == ' ' && mBoard[6][7] == ' ' && blackInCheck() == false)
				{
					mBoardToSaveBoard(0);
					mBoard[5][7] = 'K';
					mBoard[4][7] = ' ';
					if (blackInCheck() == false)
					{
						mBoard[6][7] = 'K';
						mBoard[5][7] = ' ';
						mBoard[5][7] = 'R';
						mBoard[7][7] = ' ';
					}
					else
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;
					}
					if (blackInCheck() == true)
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;

					}
				}
			}
		}
	}
	else if (i_move == "O-O-O" || i_move == "0-0-0")
	{
		if (mIsWhite)
		{
			if (wKmoved == true || wlRmoved == true)
			{
				cout << "\n\nyou've alread moved your king or rook.\n\n";
				return false;
			}
			else
			{
				if (mBoard[3][0] == ' ' && mBoard[2][0] == ' ' && mBoard[1][0] == ' ' && whiteInCheck(0) == false)
				{
					mBoardToSaveBoard(0);
					mBoard[3][0] = 'k';
					mBoard[4][0] = ' ';
					if (whiteInCheck(0) == false)
					{
						mBoard[2][0] = 'k';
						mBoard[3][0] = ' ';
						mBoard[3][0] = 'r';
						mBoard[0][0] = ' ';
					}
					else
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;
					}
					if (whiteInCheck(0) == true)
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;

					}
				}
			}
		}
		else
		{
			if (bKmoved == true || blRmoved == true)
			{
				cout << "\n\nyou've alread moved your king or rook.\n\n";
				return false;
			}
			else
			{
				if (mBoard[3][7] == ' ' && mBoard[2][7] == ' ' && mBoard[1][7] == ' ' && blackInCheck() == false)
				{
					mBoardToSaveBoard(0);
					mBoard[3][7] = 'k';
					mBoard[4][7] = ' ';
					if (blackInCheck() == false)
					{
						mBoard[2][7] = 'k';
						mBoard[3][7] = ' ';
						mBoard[3][7] = 'r';
						mBoard[0][7] = ' ';
					}
					else
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;
					}
					if (blackInCheck() == true)
					{
						mBoardToSaveBoard(1);
						cout << "\n\nYou just tried to castle in, out, or through check. Try again.\n\n";
						return false;

					}
				}
			}
		}
	}
	else if (i_move == "quit")
	{
	abort();
		return false;
	}
	else if (i_move.length() == 3) 
	{
		Location dst, src;
		dst.x = toGrid(i_move[1]);
		dst.y = i_move[2] - '1';
		mBoardToSaveBoard(0);
		
		if (((whiteCheck == true && mIsWhite) || (blackCheck == true && !mIsWhite))) 
		{
			if (search(mIsWhite ? tolower(i_move[0]) : toupper(i_move[0]), src, dst)) 
			{
				if(generic.doit == true)
				{
					int passantMod;
					if (mIsWhite) {
						passantMod = -1;
					}
					else {
						passantMod = 1;
					}
					mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
					mBoard[src.x][src.y] = ' ';
					mBoard[dst.x][dst.y + passantMod] = ' ';
				}
				else 
				{

					mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
					mBoard[src.x][src.y] = ' ';
				}
				if (mIsWhite) {
					if (whiteInCheck(0)) {
						cout << "\n\nWe already told you... Your king is in check\n\n Try AGAIN\n\n";
						mBoardToSaveBoard(1);
						return false;
					}
				}
				else {
					if (blackInCheck()) {
						cout << "\n\nWe already told you... Your king is in check\n\n Try AGAIN\n\n";
						mBoardToSaveBoard(1);
						return false;
					}
				}




			}
			else 
			{
				cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
				return false;
			}
		} 
		else if (search(mIsWhite ? tolower(i_move[0]) : toupper(i_move[0]), src, dst)) 
		{
			if (generic.doit == true)
			{
				int passantMod;
				if (mIsWhite) {
					passantMod = -1;
				}
				else {
					passantMod = 1;
				}
				mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
				mBoard[src.x][src.y] = ' ';
				mBoard[dst.x][dst.y + passantMod] = ' ';
			}
			else {
				mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
				mBoard[src.x][src.y] = ' ';
			}


			

		}
		else {
			cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
			return false;
		}
		if (i_move[0] == 'k') {
			wKmoved = true;
		}
		if (i_move[0] == 'r') {
			if (src.x == 0 && src.y == 0) {
				wlRmoved = true;
			}
			if (src.x == 7 && src.y == 0) {
				wrRmoved = true;
			}
		}
		if (i_move[0] == 'K') {
			bKmoved = true;
		}
		if (i_move[0] == 'R') {
			if (src.x == 0 && src.y == 0) {
				blRmoved = true;
			}
			if (src.x == 7 && src.y == 0) {
				brRmoved = true;
			}
		}


	}
	else if(i_move.length() == 5)
	{
		
		
		Location dst, src;

		dst.x = toGrid(i_move[3]);
		dst.y = i_move[4] - '1';

		src.x = toGrid(i_move[0]);
		src.y = i_move[1] - '1';
		mBoardToSaveBoard(0);
		char piecetoMove = mBoard[src.x][src.y];

		if (((whiteCheck == true && mIsWhite) || (blackCheck == true && !mIsWhite))) {
			if (generic.doit == true)
			{
				int passantMod;
				if (mIsWhite) {
					passantMod = -1;
				}
				else {
					passantMod = 1;
				}
				mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
				mBoard[src.x][src.y] = ' ';
				mBoard[dst.x][dst.y + passantMod] = ' ';
			}
			else 
			{
				mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
				mBoard[src.x][src.y] = ' ';
			}
			if (mIsWhite) {
				if (whiteInCheck(0)) {
					cout << "\n\nWe already told you... Your king is in check\n\n Try AGAIN\n\n";
					mBoardToSaveBoard(1);
					return false;
				}
			}
			else {
				if (blackInCheck()) {
					cout << "\n\nWe already told you... Your king is in check\n\n Try AGAIN\n\n";
					mBoardToSaveBoard(1);
					return false;
				}
			}
		}
		else if ((mIsWhite == true && islower(piecetoMove)) || (mIsWhite == false && isupper(piecetoMove)))
		{

			if (isLegal(piecetoMove, src, dst))
			{
				if (generic.doit == true)
				{
					int passantMod;
					if (mIsWhite) {
						passantMod = -1;
					}
					else {
						passantMod = 1;
					}
					mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
					mBoard[src.x][src.y] = ' ';
					mBoard[dst.x][dst.y + passantMod] = ' ';
				}
				else 
				{
					mBoard[dst.x][dst.y] = mBoard[src.x][src.y];
					mBoard[src.x][src.y] = ' ';
				}

			}
			else {
				cout << "\n\nYou made an illegal move, or this program sucks.\n\n";
				return false;
			}
		}
				
		if (piecetoMove == 'k') {
			wKmoved = true;
		}
		if (piecetoMove == 'r') {
			if (src.x == 0 && src.y == 0) {
				wlRmoved = true;
			}
			if (src.x == 7 && src.y == 0) {
				wrRmoved = true;
			}
		}
		if (piecetoMove == 'K') {
			bKmoved = true;
		}
		if (piecetoMove == 'R') {
			if (src.x == 0 && src.y == 0) {
				blRmoved = true;
			}
			if (src.x == 7 && src.y == 0) {
				brRmoved = true;
			}
		}
		
	}
	
	else 
	{
		return false;
	}
	//its written like this since the next turn will be this piece.
	if (mIsWhite) {
		blackCheck = blackInCheck();
	}
	else {
		whiteCheck = whiteInCheck(0);
	}
	mIsWhite = !mIsWhite;

	{
		if (turnNumber - generic.turn == 1 && turnNumber != 0) {
			generic.turn = -1;
			generic.movedTwo = false;
			generic.dst.x = 9;
			generic.dst.y = 9;
			generic.doit = false;
		}


	}



	turnNumber++;
	return true;


}


void
Board::reload() {
    for (int w = 0; w < 8; w++)
    {
        for (int z = 0; z < 8; z++)
        {
            mBoard[w][z] = checkMateSaveBoard[w][z];
        }
    }
}


bool
Board::isCheckMate() {
	


	
		for (int w = 0; w < 8; w++)
		{
			for (int z = 0; z < 8; z++)
			{
				checkMateSaveBoard[w][z] = mBoard[w][z];
			}
		}

	Location kingloc;
	kingloc.x = -1;
	kingloc.y = -1;
	if (mIsWhite) {
		for (int g = 0; g < 8; g++) {
			for (int z = 0; z < 8; z++) {
				if (mBoard[z][g] == 'k') {
					kingloc.x = z;
					kingloc.y = g;
					break;
				}
			}
			if (kingloc.x != -1 && kingloc.y != -1) {
				break;
			}
		}
	}
	else {
		for (int g = 0; g < 8; g++) {
			for (int z = 0; z < 8; z++) {
				if (mBoard[z][g] == 'K') {
					kingloc.x = z;
					kingloc.y = g;
					break;
				}
			}
			if (kingloc.x != -1 && kingloc.y != -1) {
				break;
			}
		}
	}
    {
	if (kingloc.x == 0 && kingloc.y == 0)
	{
		int xmod, ymod;
		xmod = 0;
		ymod = 1;
		for (int i = 0; i < 3; i++) 
		{
			if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
			{
				char erasedPiece;
					if (mIsWhite)
					{
						erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
							mBoard[kingloc.x][kingloc.y] = ' ';
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
							if (!whiteInCheck(0))
							{
                                reload();
                                return false;
							}
							else
							{
								mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
								mBoard[kingloc.x][kingloc.y] = 'k';
							}
					}
					else
					{
						erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
						if (!whiteInCheck(1))
						{
                            reload();
							return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'K';
						}
					}


			}
			if (i == 0) {
				xmod = 1;
			}
			if (i == 1) {
				ymod = 0;
			}
		}
	}
	else if (kingloc.x == 0 && kingloc.y == 7)
	{
		int xmod, ymod;
		xmod = 0;
		ymod = -1;
		for (int i = 0; i < 3; i++)
		{
			if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
			{
				char erasedPiece;
					if (mIsWhite)
					{
						erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
							mBoard[kingloc.x][kingloc.y] = ' ';
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
							if (!whiteInCheck(0))
							{
                                reload();
                                return false;
							}
							else
							{
								mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
								mBoard[kingloc.x][kingloc.y] = 'k';
							}
					}
					else
					{
						erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
						if (!whiteInCheck(1))
						{
                            reload();
                            return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'K';
						}
					}


			}
			if (i == 0) {
				xmod = 1;
			}
			if (i == 1) {
				ymod = 0;
			}
		}
	}
	else if (kingloc.x == 7 && kingloc.y == 0)
	{
	int xmod, ymod;
	xmod = 0;
	ymod = 1;
	for (int i = 0; i < 3; i++)
	{
		if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
		{
			char erasedPiece;
				if (mIsWhite)
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
						if (!whiteInCheck(0))
						{
                            reload();
                            return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'k';
						}
				}
				else
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
					mBoard[kingloc.x][kingloc.y] = ' ';
					mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
					if (!whiteInCheck(1))
					{
                        reload();
                        return false;
					}
					else
					{
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
						mBoard[kingloc.x][kingloc.y] = 'K';
					}
				}


		}
		if (i == 0) {
			xmod = -1;
		}
		if (i == 1) {
			ymod = 0;
		}
	}
	}
	else if (kingloc.x == 7 && kingloc.y == 7)
	{
	int xmod, ymod;
	xmod = 7;
	ymod = -1;
	for (int i = 0; i < 3; i++)
	{
		if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
		{
			char erasedPiece;
				if (mIsWhite)
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
						if (!whiteInCheck(0))
						{
                            reload();
                            return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'k';
						}
				}
				else
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
					mBoard[kingloc.x][kingloc.y] = ' ';
					mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
					if (!whiteInCheck(1))
					{
						mIsWhite = !mIsWhite;
                        reload();
                        return false;
					}
					else
					{
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
						mBoard[kingloc.x][kingloc.y] = 'K';
					}
				}


		}
		if (i == 0) {
			xmod = -1;
		}
		if (i == 1) {
			ymod = 0;
		}
	}
	}
	else if (kingloc.x == 0)
	{
	int xmod, ymod;
	xmod = 0;
	ymod = -1;
	for (int i = 0; i < 5; i++)
	{
		if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
		{
			char erasedPiece;
				if (mIsWhite)
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
						if (!whiteInCheck(0))
						{
                            reload();
                            return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'k';
						}
				}
				else
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
					mBoard[kingloc.x][kingloc.y] = ' ';
					mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
					if (!whiteInCheck(1))
					{
                        reload();
						return false;
					}
					else
					{
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
						mBoard[kingloc.x][kingloc.y] = 'K';
					}
				}


		}
		if (i == 0) {
			xmod = 1;
		}
		if (i == 1) {
			ymod = 0;
		}
		if (i == 2) {
			ymod = 1;
		}
		if (i == 3) {
			xmod = 0;
		}
	}
	}
	else if (kingloc.x == 7)
	{
	int xmod, ymod;
	xmod = 0;
	ymod = -1;
	for (int i = 0; i < 5; i++)
	{
		if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
		{
			char erasedPiece;
				if (mIsWhite)
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
						if (!whiteInCheck(0))
						{
                            reload();
								return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'k';
						}
				}
				else
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
					mBoard[kingloc.x][kingloc.y] = ' ';
					mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
					if (!whiteInCheck(1))
					{
                        reload();
						return false;
					}
					else
					{
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
						mBoard[kingloc.x][kingloc.y] = 'K';
					}
				}


		}
		if (i == 0) {
			xmod = -1;
		}
		if (i == 1) {
			ymod = 0;
		}
		if (i == 2) {
			ymod = 1;
		}
		if (i == 3) {
			xmod = 0;
		}
	}
	}
	else if (kingloc.y == 0)
	{
	int xmod, ymod;
	xmod = -1;
	ymod = 0;
	for (int i = 0; i < 5; i++)
	{
		if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
		{
			char erasedPiece;
				if (mIsWhite)
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
						if (!whiteInCheck(0))
						{
                            reload();
                            return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'k';
						}
				}
				else
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
					mBoard[kingloc.x][kingloc.y] = ' ';
					mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
					if (!whiteInCheck(1))
					{
                        reload();
						return false;
					}
					else
					{
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
						mBoard[kingloc.x][kingloc.y] = 'K';
					}
				}


		}
		if (i == 0) {
			ymod = 1;
		}
		if (i == 1) {
			xmod = 0;
		}
		if (i == 2) {
			xmod = 1;
		}
		if (i == 3) {
			ymod = 0;
		}
	}
	}
	else if (kingloc.y == 7)
	{
	int xmod, ymod;
	xmod = -1;
	ymod = 0;
	for (int i = 0; i < 5; i++)
	{
		if (mBoard[kingloc.x + xmod][kingloc.y + ymod] == ' ' || isWhite(mBoard[kingloc.x][kingloc.y]) != isWhite(mBoard[kingloc.x + xmod][kingloc.y + ymod]))
		{
			char erasedPiece;
				if (mIsWhite)
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
						mBoard[kingloc.x][kingloc.y] = ' ';
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'k';
						if (!whiteInCheck(0))
						{
                            reload();
                            return false;
						}
						else
						{
							mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
							mBoard[kingloc.x][kingloc.y] = 'k';
						}
				}
				else
				{
					erasedPiece = mBoard[kingloc.x + xmod][kingloc.y + ymod];
					mBoard[kingloc.x][kingloc.y] = ' ';
					mBoard[kingloc.x + xmod][kingloc.y + ymod] = 'K';
					if (!whiteInCheck(1))
					{
                        reload();
						return false;
					}
					else
					{
						mBoard[kingloc.x + xmod][kingloc.y + ymod] = erasedPiece;
						mBoard[kingloc.x][kingloc.y] = 'K';
					}
				}


		}
		if (i == 0) {
			ymod = -1;
		}
		if (i == 1) {
			xmod = 0;
		}
		if (i == 2) {
			xmod = 1;
		}
		if (i == 3) {
			ymod = 0;
		}
	}
	}
    }
    
    if((mIsWhite && whiteInCheck(0)) || (!mIsWhite && blackInCheck()))
    {
        
    
	//dont remove this. Last line before quitting;
	playstate = false;
	return true;
    }
    else
    {
        reload();
        return false;
    }
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
