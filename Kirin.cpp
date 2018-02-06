#include "Kirin.h"

void Kirin::SetPieceMovement()
{
	stepMoves = " FR FL BR BL ";
	lionMoves = "";
	rangeMoves = "";
	jumpMoves = " F L R B ";
	name = "Kirin";
	abrName2 = "";
	abrName = "Kr";
	isPromotable = true;

	TextureSetup();
}