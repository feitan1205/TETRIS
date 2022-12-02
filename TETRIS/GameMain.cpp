#include "GameMain.h"
#include "InputState.h"

namespace {

	constexpr int kfieldheight = 22;
	constexpr int kfieldwidth = 10;
	constexpr float kspeed = 0.1;
}

GameMain::GameMain()	:
	m_field(),
	movespeed(),
	stopflag(false)
{
	//�����Ȃ�
}

GameMain::~GameMain() 
{}

void GameMain::Init() {
	
	SetObjectDate();

	/*for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].Init();
		}
	}

	m_field[5][0].SetBlock(0xff0000);*/

	CreatBlock(0,5,0xff0000);

	movespeed = 1;

}

void GameMain::End() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].End();
		}
	}

}

void GameMain::Update(const InputState& input) {

	movespeed -= kspeed;
	
	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			if (i == 21 && m_field[j][i].GetIsExist() && m_field[j][i].GetIsMove()) {
				m_field[j][i].SetStop();
				stopflag = true;
			}
		}
	}
	 
	if (stopflag) {
		for (int i = 0; i < kfieldheight; i++) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (!(m_field[j][i].GetIsExist()))break;
				
				if (j == 9) {
					ClearBlock(i);
				}
			}
		}
		stopflag = false;
	}

	if (input.IsTriggered(InputType::left)) {
		MoveBlock(-1, 0, 0xff0000);
	}
	if (input.IsTriggered(InputType::right)) {
		MoveBlock(1, 0, 0xff0000);
	}

	if (input.IsTriggered(InputType::jump)) {
		JumpBlock(0xff0000);
	}

	if (!(input.IsPressed(InputType::fast))) {
		if (movespeed > 0)return;
	}

	MoveBlock(0,1,0xff0000);

	//CreatBlock(5, 0, 0xff0000);



	movespeed = 1;
}

void GameMain::Draw() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].Draw(i,j);
		}
	}
}

void GameMain::SetObjectDate()
{


	shapes[SHAPE_T] = {
		//SHAPE_T,
		{
			//color
			0xff0000,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{0,1,1,1},
				{0,0,1,0},
				{0,0,0,0}
			}
		},
	};

	shapes[SHAPE_L] = {
		//SHAPE_L,
		{
			//color
			0xff0000,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,1,0}
			}
		},
	};
		//SHAPE_J,
		{
			//color
			0xff0000,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{0,0,1,0},
				{0,0,1,0},
				{0,1,1,0}
			}
		},
		//SHAPE_I,
		{
			//color
			0xff0000,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0}
			}
		},
		//SHAPE_O,
		{
			//color
			0xff0000,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			}
		},
		//SHAPE_S,
		{
			//color
			0xff0000,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{0,0,1,1},
				{0,1,1,0},
				{0,0,0,0}
			}
		},
		//SHAPE_Z,
		{
			//color
			0xff0000,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,0,1,1},
				{0,0,0,0}
			}
		},
	};
}

void GameMain::MoveBlock(int x,int y,int color)
{	

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].SetIsMoved(false);
		}
	}

	for (int i = kfieldheight - 1; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {

			if (m_field[j][i].GetIsMoved())continue;

			if (m_field[j][i].GetIsMove() && j + x < 0 || j + x == 10) continue;

			if (i == 21 || !(m_field[j][i].GetIsMove()))continue;


			if (m_field[j][i + 1].GetIsExist()) {
				m_field[j][i].SetStop();
				continue;
			}

			if (m_field[j + x][i + y].GetIsExist()) {
				continue;
			}

			if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
				m_field[j][i].SetStop();
				m_field[j + x][i + y].SetBlock(color);
				m_field[j + x][i + y].SetIsMoved(true);
				m_field[j][i].DeleteExist();
			}
		}
	}
}

void GameMain::JumpBlock(int color)
{
	for (int i = kfieldheight - 1; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {
			if (m_field[j][i].GetIsMove()) {
				for (int k = i + 1; k < kfieldheight; k++) {

					if (m_field[j][k].GetIsExist()) {
						m_field[j][k - 1].SetBlock(color);
						m_field[j][i].DeleteExist();
						m_field[j][i].SetStop();
					}
					else if (k == kfieldheight - 1) {
						m_field[j][k].SetBlock(color);
						m_field[j][i].DeleteExist();
						m_field[j][i].SetStop();
					}

				}
			}
		}
	}
}

void GameMain::CreatBlock(int x, int y, int color)
{
	
	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			if (m_field[j][i].GetIsMove())return;
		}
	}



	m_field[x][y].SetBlock(color);

}

void GameMain::ClearBlock(int y)
{

	for (int i = 0; i < 10; i++) {
		m_field[i][y].DeleteExist();
	}

	for (int i = y; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {

			if (i != 21 && m_field[j][i].GetIsExist()) {
				m_field[j][i].SetStop();
				m_field[j][i + 1].SetBlock(0xff0000);
				m_field[j][i].DeleteExist();
			}
		}
	}
}
