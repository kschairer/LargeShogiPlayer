#include "King.h"

void King::SetPieceMovement()
{
	stepMoves = " K ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "";
	name = "King";
	abrName = "K";
	abrName2 = "";
	isPromotable = false;

	TextureSetup();
}