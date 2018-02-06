#include "FreeBoar.h"

void FreeBoar::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "  ";
	rangeMoves = "  BR R FR FL L BL ";
	jumpMoves = " ";
	name = "Free Boar";
	abrName2 = "F";
	abrName = "B";
	isPromotable = false;


	TextureSetup();
}
