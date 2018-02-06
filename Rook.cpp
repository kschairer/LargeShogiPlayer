#include "Rook.h"

void Rook::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "";
	rangeMoves = " F R L B ";
	jumpMoves = "  ";
	name = "Rook";
	abrName2 = "";
	abrName = "R";
	isPromotable = true;

	TextureSetup();
}