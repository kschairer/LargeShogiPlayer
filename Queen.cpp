#include "Queen.h"

void Queen::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "";
	rangeMoves = " Q ";
	jumpMoves = "";
	name = "Queen";
	abrName = "Q";
	abrName2 = "";
	isPromotable = false;

	TextureSetup();

}