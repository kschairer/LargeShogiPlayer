#include "Bishop.h"

void Bishop::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "";
	rangeMoves = " FL FR BL BR ";
	jumpMoves = "";
	name = "Bishop";
	abrName = "B";
	abrName2 = "";
	isPromotable = true;

	TextureSetup();
}