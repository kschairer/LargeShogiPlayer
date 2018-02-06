#include "Lance.h"

void Lance::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "";
	rangeMoves = " F ";
	jumpMoves = "  ";
	name = "Lance";
	abrName2 = "";
	abrName = "L";
	isPromotable = true;

	TextureSetup();
}