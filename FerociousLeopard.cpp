#include "FerociousLeopard.h"

void FerociousLeopard::SetPieceMovement()
{
	stepMoves = " FR F FL BL B BR ";
	lionMoves = "";
	rangeMoves = " ";
	jumpMoves = "";
	name = "Ferocious Leopard";
	abrName2 = "F";
	abrName = "L";
	isPromotable = true;

	TextureSetup();
}