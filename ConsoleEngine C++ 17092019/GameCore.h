#pragma once
#include "Engine.h"

Scene map;

Scene mapWallArea;
Scene mapMoveArea;

// Blank
Object spriteBlank;

// Thickwall
Object spriteThickWall01;
Object spriteThickWall02;
Object spriteThickWall03;
Object spriteThickWall04;
Object spriteThickWall05;
Object spriteThickWall06;
Object spriteThickWall07;
Object spriteThickWall08;
Object spriteThickWall09;
Object spriteThickWall10;
Object spriteThickWall11;
Object spriteThickWall12;
Object spriteThickWall13;
Object spriteThickWall14;
Object spriteThickWall15;

// Thinwall
Object spriteWall01;
Object spriteWall02;
Object spriteWall03;
Object spriteWall04;
Object spriteWall05;
Object spriteWall06;

// Chees
Object spriteCheese;
Object spriteBigCheese;

// Ghosts
Object spritePacBlinky;
Object spritePacPinky;
Object spritePacInky;
Object spritePacClyde;

// PacMan
Object spritePacMan;

void importSprites()
{
	spriteBlank.ImportSprite("spr_pacBlank");

	spriteThickWall01.ImportSprite("spr_pacThickWall01");
	spriteThickWall02.ImportSprite("spr_pacThickWall02");
	spriteThickWall03.ImportSprite("spr_pacThickWall03");
	spriteThickWall04.ImportSprite("spr_pacThickWall04");
	spriteThickWall05.ImportSprite("spr_pacThickWall05");
	spriteThickWall06.ImportSprite("spr_pacThickWall06");
	spriteThickWall07.ImportSprite("spr_pacThickWall07");
	spriteThickWall08.ImportSprite("spr_pacThickWall08");
	spriteThickWall09.ImportSprite("spr_pacThickWall09");
	spriteThickWall10.ImportSprite("spr_pacThickWall10");
	spriteThickWall11.ImportSprite("spr_pacThickWall11");
	spriteThickWall12.ImportSprite("spr_pacThickWall12");
	spriteThickWall13.ImportSprite("spr_pacThickWall13");
	spriteThickWall14.ImportSprite("spr_pacThickWall14");
	spriteThickWall15.ImportSprite("spr_pacThickWall15");

	spriteWall01.ImportSprite("spr_pacWall01");
	spriteWall02.ImportSprite("spr_pacWall02");
	spriteWall03.ImportSprite("spr_pacWall03");
	spriteWall04.ImportSprite("spr_pacWall04");
	spriteWall05.ImportSprite("spr_pacWall05");
	spriteWall06.ImportSprite("spr_pacWall06");

	spriteCheese.ImportSprite("spr_pacChees");
	spriteBigCheese.ImportSprite("spr_pacBigChees");

	spritePacBlinky.ImportSprite("spr_pacGhost1_01");

	spritePacMan.ImportSprite("spr_pacMan01");
}

void createMap()
{
	// Map
	mapWallArea.ImportMap("spr_pacMapWallArea");
	mapWallArea.ObjectDimensions(3, 3);

	mapWallArea.ObjectId(int('1'), spriteThickWall01);
	mapWallArea.ObjectId(int('2'), spriteThickWall02);
	mapWallArea.ObjectId(int('3'), spriteThickWall03);
	mapWallArea.ObjectId(int('4'), spriteThickWall04);
	mapWallArea.ObjectId(int('5'), spriteThickWall05);
	mapWallArea.ObjectId(int('6'), spriteThickWall06);
	mapWallArea.ObjectId(int('7'), spriteThickWall07);
	mapWallArea.ObjectId(int('8'), spriteThickWall08);
	mapWallArea.ObjectId(int('a'), spriteThickWall09);
	mapWallArea.ObjectId(int('b'), spriteThickWall10);
	mapWallArea.ObjectId(int('c'), spriteThickWall11);
	mapWallArea.ObjectId(int('d'), spriteThickWall12);
	mapWallArea.ObjectId(int('e'), spriteThickWall13);
	mapWallArea.ObjectId(int('f'), spriteThickWall14);
	mapWallArea.ObjectId(int('g'), spriteThickWall15);

	mapWallArea.ObjectId(int('E'), spriteWall01);
	mapWallArea.ObjectId(int('F'), spriteWall02);
	mapWallArea.ObjectId(int('G'), spriteWall03);
	mapWallArea.ObjectId(int('H'), spriteWall04);
	mapWallArea.ObjectId(int('I'), spriteWall05);
	mapWallArea.ObjectId(int('J'), spriteWall06);

	// Map
	mapMoveArea.ImportMap("spr_pacMapMoveArea");
	mapMoveArea.ObjectDimensions(3, 3);

	mapMoveArea.ObjectId(int('-'), spriteBlank);
	mapMoveArea.ObjectId(int('.'), spriteCheese);
	mapMoveArea.ObjectId(int('/'), spriteBigCheese);
}