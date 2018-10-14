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
	bool isLegalBishop(char i_piece, Location &i_src, Location &i_dst);
	bool isLegalKnight(char i_piece, Location &i_src, Location &i_dst);
	bool isLegalRook(char i_piece, Location &i_src, Location &i_dst);
	bool isLegalQueen(char i_piece, Location &i_src, Location &i_dst);
	bool isLegalKing(char i_piece, Location &i_src, Location &i_dst);

	bool   isWhite(char i_piece) { return islower(i_piece) != 0; }
	bool   isBlack(char i_piece) { return !isWhite(i_piece); }


	bool   isPawn(char i_piece) { return tolower(i_piece) == 'p'; }
	bool   isBishop(char i_piece) { return tolower(i_piece) == 'b'; }
	bool   isKnight(char i_piece) { return tolower(i_piece) == 'n'; }
	bool   isRook(char i_piece) { return tolower(i_piece) == 'r'; }
	bool   isQueen(char i_piece) { return tolower(i_piece) == 'q'; }
	bool   isKing(char i_piece) { return tolower(i_piece) == 'k'; }






private:
	bool mIsWhite;
	bool search(char i_piece, Location &i_dst, Location &o_src);
	char  mBoard[8][8];





};