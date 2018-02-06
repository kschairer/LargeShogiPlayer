#include "PieceDecorator.hpp"

PieceDecorator::PieceDecorator(Piece * piece, bool white1black0, TextureModule * t)
{
	Initialize(white1black0, t);
	SetPieceMovement();
	temp = piece;
}