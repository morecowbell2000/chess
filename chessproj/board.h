#pragma once
#include <string>



typedef struct {  
	int x, y;
} Location;


class Board
{
public:
	Board();
	~Board();


	bool move(const std::string &i_move);
	bool   isWhiteMove() { return mIsWhite; }
	void	print();



private:

	
	int toGrid(char x);
	bool isLegal(char i_piece, Location &o_src, Location &i_dst);

	
	bool   isWhite(char i_piece) { return islower(i_piece) != 0; }
	bool   isBlack(char i_piece) { return !isWhite(i_piece); }


	bool   isPawn(char i_piece) { return tolower(i_piece) == 'p'; }





private:
	bool mIsWhite;
	bool search(char i_piece, Location &i_dst, Location &o_src);
	char  mBoard[8][8];





};