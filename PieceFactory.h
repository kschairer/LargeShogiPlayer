#pragma once

#include "Piece.h"
#include "Bishop.h" 
#include "Rook.h"
#include "Pawn.h"
#include "AngryBoar.h"
#include "BlindTiger.h"
#include "CatSword.h"
#include "Copper.h"
#include "DragonHorse.h"
#include "DragonKing.h"
#include "DrunkElephant.h"
#include "EvilWolf.h"
#include "FerociousLeopard.h"
#include "FlyingDragon.h"
#include "FlyingOx.h"
#include "FlyingStag.h"
#include "FreeBoar.h"
#include "Gold.h"
#include "GoBetween.h"
#include "HornedFalcon.h"
#include "Iron.h"
#include "King.h"
#include "Kirin.h"
#include "Knight.h"
#include "Lance.h"
#include "Lion.h"
#include "Pheonix.h"
#include "Prince.h"
#include "Queen.h"
#include"ReverseChariot.h"
#include "Silver.h"
#include "SideMover.h"
#include "SoaringEagle.h"
#include "Stone.h"
#include "VerticalMover.h"
#include "ViolentOx.h"
#include"Whale.h"
#include"WhiteHorse.h"

class PieceFactory
{
public:
	enum PieceType
	{
		ANGRYBOAR,
		BISHOP,
		BLINDTIGER,
		CATSWORD,
		COPPER,
		DRUNKELEPHANT,
		DRAGONHORSE,
		DRAGONKING,
		EVILWOLF,
		FEROCIOUSLEOPARD,
		FLYINGSTAG,
		FLYINGOX,
		FLYINGDRAGON,
		FREEBOAR,
		GOLD,
		GOBETWEEN,
		HORNEDFALCON,
		IRON,
		KING,
		KIRIN,
		KNIGHT,
		LANCE,
		LION,
		PAWN,
		PHEONIX,
		PRINCE,
		QUEEN,
		ROOK,
		REVERSECHARIOT,
		SILVER,
		SIDEMOVER,
		SOARINGEAGLE,
		STONE,
		VERTICALMOVER,
		VIOLENTOX,
		WHITEHORSE,
		WHALE,
		
	};

	static Piece* createPiece(PieceType pieceType, Piece* basePiece);
	
};

