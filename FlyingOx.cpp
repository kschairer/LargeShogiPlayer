#include "FlyingOx.h"

void FlyingOx::SetPieceMovement()
{
	stepMoves = "  ";
	lionMoves = "  ";
	rangeMoves = "  BR F FR FL B BL ";
	jumpMoves = " ";
	name = "Flying Ox";
	abrName2 = "F";
	abrName = "O";
	isPromotable = false;


	TextureSetup();
}