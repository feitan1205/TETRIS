#include <DxLib.h>
#include "Field.h"
#include "game.h"


Field::Field() :
	isExistBlock(false),
	isMoveBlock(false),
	isMovedBlock(false),
	blockColor(0)
{}

Field::~Field()
{}

void Field::Init() {

}
void Field::End() {

}

void Field::SetBlock(int color)
{
	isExistBlock = true;
	isMoveBlock = true;
	blockColor = color;
}

void Field::DeleteExist()
{
	isExistBlock = false;
}

void Field::Update() {

}

void Field::Draw(int i,int j) {

	if (isExistBlock) {
		DrawBox(j * 16, i * 16, j * 16 + 16, i * 16 + 16, blockColor, isExistBlock);
		DrawBox(j * 16, i * 16, j * 16 + 16, i * 16 + 16, GetColor(0, 0, 0), false);
	}
	else {
		DrawBox(j * 16, i * 16, j * 16 + 16, i * 16 + 16, GetColor(255, 255, 255), isExistBlock);
	}
}
