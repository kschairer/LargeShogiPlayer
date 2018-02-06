#include "Knight.h"

void Knight::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = " N ";
	name = "Knight";
	abrName2 = "";
	abrName = "N";
	isPromotable = true;


	TextureSetup();
}
