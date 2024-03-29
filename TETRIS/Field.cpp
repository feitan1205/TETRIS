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

/// <summary>
/// フィールドにブロックを生成する。
/// </summary>
/// <param name="flag">isMoveBlock</param>
/// <param name="color">color</param>
void Field::SetBlock(bool flag,int color)
{
	isExistBlock = true;
	isMoveBlock = flag;
	blockColor = color;
}

/// <summary>
/// フィールドのブロックを削除する。
/// </summary>
void Field::DeleteExist()
{
	isExistBlock = false;
	isMoveBlock = false;
	isMovedBlock = false;
}

void Field::Update() {

}

/// <summary>
/// フィールドの描画
/// </summary>
/// <param name="i">描画するx座標</param>
/// <param name="j">描画するy座標</param> 
void Field::Draw(int i,int j,int color) {

	if (isExistBlock) {
		DrawBox(j * 16 + 250, i * 16 + 100, j * 16 + 16 + 250, i * 16 + 16 + 100, blockColor, isExistBlock);
		DrawBox(j * 16 + 250, i * 16 + 100, j * 16 + 16 + 250, i * 16 + 16 + 100, 0x000000, false);
	}
	else {
		DrawBox(j * 16 + 250, i * 16 + 100, j * 16 + 16 + 250, i * 16 + 16 + 100, 0xffffff, isExistBlock);
	}
}
