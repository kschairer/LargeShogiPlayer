#include "CatSword.h"

void CatSword::SetPieceMovement()
{
	stepMoves = " FL FR BR BL ";
	lionMoves = "";
	rangeMoves = "  ";
	jumpMoves = "  ";
	name = "Cat Sword";
	abrName2 = "C";
	abrName = "S";
	isPromotable = true;


	TextureSetup();
}
