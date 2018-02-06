#include "Lion.h"

void Lion::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = " K ";
	rangeMoves = "";
	jumpMoves = "  ";
	name = "Lion";
	abrName2 = "";
	abrName = "Ln";
	isPromotable = false;

	TextureSetup();
}