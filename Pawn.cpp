#include "Pawn.h"

void Pawn::SetPieceMovement()
{
	stepMoves = " F ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "";
	name = "Pawn";
	abrName = "P";
	abrName2 = "";
	isPromotable = true;


	TextureSetup();
}
