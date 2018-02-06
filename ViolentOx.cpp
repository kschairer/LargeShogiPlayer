#include "ViolentOx.h"

void ViolentOx::SetPieceMovement()
{
	stepMoves = " 2 F R B L ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "  ";
	name = "Violent Ox";
	abrName2 = "V";
	abrName = "O";
	isPromotable = false;


	TextureSetup();
}
