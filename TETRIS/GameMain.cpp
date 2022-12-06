#include "GameMain.h"
#include "InputState.h"

namespace {

	constexpr int kfieldheight = 22;
	constexpr int kfieldwidth = 10;
	constexpr float kspeed = 0.05f;
}

GameMain::GameMain()	:
	m_field(),
	movespeed(),
	stopflag(false),
	shapes()
{
	//èàóùÇ»Çµ
}

GameMain::~GameMain() 
{}

void GameMain::Init() {
	
	SetObjectDate();

	CreatBlock(0xff0000);

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
			if (m_field[j][i].GetIsExist() && !(m_field[j][i].GetIsMove()))stopflag = true;
			if (m_field[j][i].GetIsExist() && m_field[j][i].GetIsMove()) {
				stopflag = false;
				break;
			}
		}
		if (!stopflag)break;
	}
	 
	if (stopflag) {
		for (int i = kfieldheight - 1 ; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (!(m_field[j][i].GetIsExist()))break;
				
				if (j == 9) {
					ClearBlock(i);
				}
				continue;
			}
		}
		stopflag = false;
	}

	CreatBlock(0xff0000);

	if (input.IsTriggered(InputType::left)) {
		LeftMoveBlock(-1, 0, 0xff0000);
	}
	if (input.IsTriggered(InputType::right)) {
		RightMoveBlock(1, 0, 0xff0000);
	}

	if (input.IsTriggered(InputType::jump)) {
		JumpBlock(0xff0000);
	}

	if (!(input.IsPressed(InputType::fast))) {
		if (movespeed > 0)return;
	}

	DownMoveBlock(0,1,0xff0000);

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
		//color
		0xff0000,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,1,1},
			{0,0,1,0},
			{0,0,0,0}
		}
	};

	shapes[SHAPE_L] = {
	//SHAPE_L
		//color
		0xff0000,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,1,0}
		}	
	};

	shapes[SHAPE_J] = {
	//SHAPE_J,
	
		//color
		0xff0000,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,1,1,0}
		}
	};

	shapes[SHAPE_I] = {
	//SHAPE_I,
		//color
		0xff0000,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		}
	};

	shapes[SHAPE_O] = {
	//SHAPE_O,
	//color
		0xff0000,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	};

	shapes[SHAPE_S] = {
	//SHAPE_S,
	//color
		0xff0000,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,0,0,0}
		}
	};

	shapes[SHAPE_Z] = {
	//SHAPE_Z,
	//color
		0xff0000,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1},
			{0,0,0,0}
		}
	};
}

void GameMain::DownMoveBlock(int x, int y, int color)
{

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].SetIsMoved(false);
		}
	}

	bool isMoveShape = false;
	int count = 0;

	for (int i = kfieldheight - 1; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {

			if (!(m_field[j][i].GetIsMove()))continue;

			if (i + 1 != 22 && m_field[j][i + 1].GetIsExist() && !(m_field[j][i + 1].GetIsMove()))continue;

			if (i + 1 == 22)continue;

			count++;

			if (count == 4) {
				isMoveShape = true;
			}
		}
	}

	if (count < 4) {
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
					m_field[j][i].SetStop();
			}
		}
	}

	if (count == 4) {
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
					m_field[j][i].SetStop();
					m_field[j + x][i + y].SetBlock(color);
					m_field[j + x][i + y].SetIsMoved(true);
					m_field[j][i].DeleteExist();
				}
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

	if (count == 4) {
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
					m_field[j][i].SetStop();
					m_field[j + x][i + y].SetBlock(color);
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

	if (count == 4) {
		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = kfieldwidth - 1; j >= 0; j--) {
				if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
					m_field[j][i].SetStop();
					m_field[j + x][i + y].SetBlock(color);
					m_field[j + x][i + y].SetIsMoved(true);
					m_field[j][i].DeleteExist();
				}
			}
		}
	}
}

void GameMain::JumpBlock(int color)
{
	bool isMoveShape = false;
	int count = 4;

	while (count == 4) {

		isMoveShape = false;
		count = 0;

		for (int i = 0; i < kfieldheight; i++) {
			for (int j = 0; j < kfieldwidth; j++) {
				m_field[j][i].SetIsMoved(false);
			}
		}

		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {

				if (!(m_field[j][i].GetIsMove()))continue;

				if (i + 1 != 22 && m_field[j][i + 1].GetIsExist() && !(m_field[j][i + 1].GetIsMove()))continue;

				if (i + 1 == 22)continue;

				count++;

				if (count == 4) {
					isMoveShape = true;
				}
			}
		}

		if (count < 4) {
			for (int i = kfieldheight - 1; i >= 0; i--) {
				for (int j = 0; j < kfieldwidth; j++) {
					m_field[j][i].SetStop();
				}
			}
		}

		if (count == 4) {
			for (int i = kfieldheight - 1; i >= 0; i--) {
				for (int j = 0; j < kfieldwidth; j++) {
					if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
						m_field[j][i].SetStop();
						m_field[j][i + 1].SetBlock(color);
						m_field[j][i + 1].SetIsMoved(true);
						m_field[j][i].DeleteExist();
					}
				}
			}
		}
	}
}

void GameMain::CreatBlock(int color)
{
	
	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			if (m_field[j][i].GetIsMove())return;
		}
	}

	int randShape = GetRand(SHAPE_MAX);

	for (int i = 0; i < SHAPE_HEIGHT_MAX; i++) {
		for (int j = 0; j < SHAPE_WIDTH_MAX; j++) {
			if (shapes[randShape].pattern[j][i] == 1) {
				m_field[j + 3][i].SetBlock(color);
			}
		}
	}

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
