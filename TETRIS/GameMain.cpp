#include "GameMain.h"
#include "InputState.h"
#include "Shape.h"

namespace {

	constexpr int kfieldheight = 22;
	constexpr int kfieldwidth = 10;
	constexpr float kspeed = 0.05f;
}

GameMain::GameMain()	:
	m_field(),
	m_movespeed(),
	m_shape(nullptr),
	m_stopflag(false),
	m_randShape(),
	m_isGameOverFlag(false)
{
	//èàóùÇ»Çµ
}

GameMain::~GameMain() 
{}

void GameMain::Init() {
	
	CreatBlock();

	m_movespeed = 1;

	m_shape = new Shape();



}

void GameMain::End() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].End();
		}
	}

}

void GameMain::Update(const InputState& input) {

	m_movespeed -= kspeed;
	
	CheckRanding();

	if (m_stopflag) {

		if (m_field[4][0].GetIsExist()) {
			m_isGameOverFlag = true;
		}

		for (int i = kfieldheight - 1 ; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (!(m_field[j][i].GetIsExist()))break;
				
				if (j == 9) {
					ClearBlock(i);
				}
				continue;
			}
		}
		m_stopflag = false;
	}

	CreatBlock();	

	if (input.IsTriggered(InputType::left)) {
		LeftMoveBlock(-1, 0, 0xff0000);
	}
	if (input.IsTriggered(InputType::right)) {
		RightMoveBlock(1, 0, 0xff0000);
	}

	if (input.IsTriggered(InputType::jump)) {
		JumpBlock(0xff0000);
	}

	if (input.IsPressed(InputType::fast)) {
		DownMoveBlock(0, 1, 0xff0000);
	}
	else if (!input.IsPressed(InputType::fast)) {
		if (m_movespeed < 0) {
			DownMoveBlock(0, 1, 0xff0000);
			m_movespeed = 1;
		}
	}
	
}

void GameMain::Draw() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].Draw(i,j);
		}
	}
}

void GameMain::DownMoveBlock(int x, int y, int color)
{
	for (int i = kfieldheight - 1; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {

			if (m_field[j][i].GetIsMove()) {
				m_field[j][i].SetStop();
				m_field[j + x][i + y].SetBlock(true, color);
				m_field[j + x][i + y].SetIsMoved(true);
				m_field[j][i].DeleteExist();
			}			
		}
	}
}

void GameMain::LeftMoveBlock(int x,int y,int color)
{	

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].SetIsMoved(false);
		}
	}

	bool isMoveShape = false;
	int count = 0;

	for (int j = 0; j < kfieldwidth; j++) {
		for (int i = kfieldheight - 1; i >= 0; i--) {

			if (!(m_field[j][i].GetIsMove()))continue;

			if (j - 1 != -1 && m_field[j - 1][i].GetIsExist() && !(m_field[j - 1][i].GetIsMove()))continue;

			if (j - 1 == -1)continue;

			count++;

			if (count == 4) {
				isMoveShape = true;
			}
		}
	}

	if (count < 4) {
		return;
	}

	if (count == 4) {
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
					m_field[j][i].SetStop();
					m_field[j + x][i + y].SetBlock(true,color);
					m_field[j + x][i + y].SetIsMoved(true);
					m_field[j][i].DeleteExist();
				}
			}
		}
	}
}

void GameMain::RightMoveBlock(int x, int y, int color)
{

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].SetIsMoved(false);
		}
	}

	bool isMoveShape = false;
	int count = 0;

	for (int j = kfieldwidth - 1; j >= 0; j--) {
		for (int i = kfieldheight - 1; i >= 0; i--) {

			if (!(m_field[j][i].GetIsMove()))continue;

			if (j + 1 != 10 && m_field[j + 1][i].GetIsExist() && !(m_field[j + 1][i].GetIsMove()))continue;

			if (j + 1 == 10)continue;

			count++;

			if (count == 4) {
				isMoveShape = true;
			}
		}
	}

	if (count < 4) {
		return;
	}

	if (count == 4) {
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = kfieldwidth - 1; j >= 0; j--) {
				if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
					m_field[j][i].SetStop();
					m_field[j + x][i + y].SetBlock(true,color);
					m_field[j + x][i + y].SetIsMoved(true);
					m_field[j][i].DeleteExist();
				}
			}
		}
	}
}

void GameMain::JumpBlock(int color)
{
	bool isMoveShape = true;	

	while (isMoveShape) {
		isMoveShape = false;
		for (int i = 0; i < kfieldheight; i++) {
			for (int j = 0; j < kfieldwidth; j++) {
				m_field[j][i].SetIsMoved(false);
			}
		}
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (i != 21 && m_field[j][i].GetIsMove()) {
					m_field[j][i].SetStop();
					m_field[j][i + 1].SetBlock(true, color);
					m_field[j][i + 1].SetIsMoved(true);
					m_field[j][i].DeleteExist();
					isMoveShape = true;
				}
			}
		}
		CheckRanding();
	}
}

void GameMain::CreatBlock()
{

}

void GameMain::ClearBlock(int y)
{

	for (int i = 0; i < 10; i++) {
		m_field[i][y].DeleteExist();
	}

	for (int i = y; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {

			if (i != 21 && m_field[j][i].GetIsExist()) {
				m_field[j][i + 1].SetBlock(false,0xff0000);
				m_field[j][i].DeleteExist();
			}
		}
	}
}

void GameMain::CheckRanding()
{

	for (int i = kfieldheight - 1; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {
			if (m_field[j][i].GetIsMove() && i == 21) {
				m_stopflag = true;
			}
			if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i + 1].GetIsExist() && !(m_field[j][i + 1].GetIsMove())) {
				m_stopflag = true;
			}
		}
	}

	if (m_stopflag) {
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				m_field[j][i].SetStop();
			}
		}
	}

}
