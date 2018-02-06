#include "Iron.h"

void Iron::SetPieceMovement()
{
	stepMoves = " FL F FR ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "  ";
	name = "Iron General";
	abrName2 = "";
	abrName = "I";
	isPromotable = true;


	TextureSetup();
}
