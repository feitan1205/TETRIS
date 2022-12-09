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
/// �t�B�[���h�Ƀu���b�N�𐶐�����B
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
/// �t�B�[���h�̃u���b�N���폜����B
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
/// �t�B�[���h�̕`��
/// </summary>
/// <param name="i">�`�悷��x���W</param>
/// <param name="j">�`�悷��y���W</param> 
void Field::Draw(int i,int j) {

	if (isExistBlock) {
		DrawBox(j * 16, i * 16, j * 16 + 16, i * 16 + 16, blockColor, isExistBlock);
		DrawBox(j * 16, i * 16, j * 16 + 16, i * 16 + 16, GetColor(0, 0, 0), false);
	}
	else {
		DrawBox(j * 16, i * 16, j * 16 + 16, i * 16 + 16, GetColor(255, 255, 255), isExistBlock);
	}
}
