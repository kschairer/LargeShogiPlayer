#include "Prince.h"

void Prince::SetPieceMovement()
{
	stepMoves = " K ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = " ";
	name = "Prince";
	abrName2 = "";
	abrName = "Pr";
	isPromotable = false;


	TextureSetup();
}
