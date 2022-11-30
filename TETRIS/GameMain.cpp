#include "GameMain.h"

namespace {

	constexpr int kfieldheight = 22;
	constexpr int kfieldwidth = 10;
	constexpr float kspeed = 0.1;
}

GameMain::GameMain()	:
	m_field(),
	movespeed()
{
	//ˆ—‚È‚µ
}

GameMain::~GameMain() 
{}

void GameMain::Init() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].Init();
		}
	}

	m_field[5][0].SetBlock(0xff0000);

	movespeed = 1;

}
void GameMain::End() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].End();
		}
	}

}

void GameMain::Update() {

	movespeed -= kspeed;

	if (movespeed > 0)return;

	MoveBlock(0,1,0xff0000);


	movespeed = 1;
}

void GameMain::Draw() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].Draw(i,j);
		}
	}
}

void GameMain::MoveBlock(int x,int y,int color)
{
	for (int i = kfieldheight - 1; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {

			if (i == 21 || m_field[j][i + 1].GetIsExist()) m_field[j][i].SetStop();

			if (i != 21 && m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
				m_field[j + x][i + y].SetBlock(color);
				m_field[j][i].DeleteExist();
			}
		}
	}
}
