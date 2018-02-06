#include "DrunkElephant.h"

void DrunkElephant::SetPieceMovement()
{
	stepMoves = " BL BR L R FL F FR ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "";
	name = "Drunk Elephant";
	abrName = "E";
	abrName2 = "D";
	isPromotable = true;

	TextureSetup();
}
