#include "Gold.h"

void Gold::SetPieceMovement()
{
	stepMoves = " L FL F FR R B ";
	lionMoves = "";
	rangeMoves = "";
	jumpMoves = "";
	name = "Gold General";
	abrName2 = "";
	abrName = "G";
	isPromotable = true;

	TextureSetup();
}