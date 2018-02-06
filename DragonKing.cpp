#include "DragonKing.h"

void DragonKing::SetPieceMovement()
{
	stepMoves = " K ";
	lionMoves = "";
	rangeMoves = " F R L B ";
	jumpMoves = "";
	name = "Dragon King";
	abrName2 = "D";
	abrName = "K";
	isPromotable = true;

	TextureSetup();
}