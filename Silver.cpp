#include "Silver.h"

void Silver::SetPieceMovement()
{
	stepMoves = " FR FL BR BL F ";
	lionMoves = "";
	rangeMoves = "";
	jumpMoves = "";
	name = "Silver General";
	abrName2 = "";
	abrName = "S";
	isPromotable = true;

	TextureSetup();
}