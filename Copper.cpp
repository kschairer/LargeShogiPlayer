#include "Copper.h"

void Copper::SetPieceMovement()
{
	stepMoves = " FR F FL B ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "";
	name = "Copper General";
	abrName = "C";
	abrName2 = "";
	isPromotable = true;

	TextureSetup();
}