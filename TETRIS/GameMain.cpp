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
	m_waitStop(),
	m_randShape(),
	m_isGameOverFlag(false)
{
	//処理なし
}

GameMain::~GameMain() 
{}


/// <summary>
/// 初期化
/// </summary>
void GameMain::Init() {
	
	m_waitStop = 1;

	m_movespeed = 1;

	m_shape = new Shape();

	m_shape->SetShapeData();

	CreatBlock();
}

/// <summary>
/// 終了処理
/// </summary>
void GameMain::End() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].End();
		}
	}

}

/// <summary>
/// ゲームの主な処理と管理
/// </summary>
/// <param name="input">キー</param>
void GameMain::Update(const InputState& input) {

	m_movespeed -= kspeed;
	
	if (!m_stopflag) {
		m_waitStop = 1;
	}

	if (m_stopflag) {
		m_waitStop -= kspeed;
	}

	CheckRanding();

	if (input.IsTriggered(InputType::left)) {
		LeftMoveBlock(0xff0000);
	}
	if (input.IsTriggered(InputType::right)) {
		RightMoveBlock(0xff0000);
	}

	if (m_waitStop > 0 && m_stopflag) {
		return;
	}

	if (m_waitStop < 0 && m_stopflag) {

		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				m_field[j][i].SetStop();
			}
		}

		for (int i = 4; i < 7; i++) {
			if (m_field[i][0].GetIsExist()) {
				m_isGameOverFlag = true;
			}
			if (m_isGameOverFlag) {
				break;
			}
		}

		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (!(m_field[j][i].GetIsExist()))break;

				if (j == 9) {
					ClearBlock(i);
				}
				continue;
			}
		}

		CheckRanding();

		CreatBlock();

		m_stopflag = false;

		m_waitStop = 1;

	}

	if (input.IsTriggered(InputType::jump)) {
		JumpBlock(0xff0000);
	}

	if (input.IsPressed(InputType::fast)) {
		DownMoveBlock(0xff0000);
	}
	else if (!input.IsPressed(InputType::fast)) {
		if (m_movespeed < 0) {
			DownMoveBlock(0xff0000);
			m_movespeed = 1;
		}
	}

	/*if (m_waitStop < 0 && m_stopflag) {

		
	}*/
		
}

/// <summary>
/// ゲームの描画処理
/// </summary>
void GameMain::Draw() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].Draw(i,j);
		}
	}
}

/// <summary>
/// ブロックを下に落とす処理
/// </summary>
/// <param name="color">ブロックの色</param>
void GameMain::DownMoveBlock(int color)
{
	for (int i = kfieldheight - 1; i >= 0; i--) {
		for (int j = 0; j < kfieldwidth; j++) {

			if (i != 21 && m_field[j][i].GetIsMove()) {
				m_field[j][i].SetStop();
				m_field[j][i + 1].SetBlock(true, color);
				m_field[j][i + 1].SetIsMoved(true);
				m_field[j][i].DeleteExist();
			}			
		}
	}
}

/// <summary>
/// ブロックを左に動かす処理
/// </summary>
/// <param name="color">ブロックの色</param>
void GameMain::LeftMoveBlock(int color)
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
				if (m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
					m_field[j][i].SetStop();
					m_field[j - 1][i].SetBlock(true,color);
					m_field[j - 1][i].SetIsMoved(true);
					m_field[j][i].DeleteExist();
				}
			}
		}
	}
}

/// <summary>
/// ブロックを右に動かす処理
/// </summary>
/// <param name="color">ブロックの色</param>
void GameMain::RightMoveBlock(int color)
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
				if (m_field[j][i].GetIsMove() && m_field[j][i].GetIsExist()) {
					m_field[j][i].SetStop();
					m_field[j + 1][i].SetBlock(true,color);
					m_field[j + 1][i].SetIsMoved(true);
					m_field[j][i].DeleteExist();
				}
			}
		}
	}
}

/// <summary>
/// ブロックを一番下まで飛ばす処理
/// </summary>
/// <param name="color">ブロックの色</param>
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

		if (m_stopflag) {
			for (int i = kfieldheight - 1; i >= 0; i--) {
				for (int j = 0; j < kfieldwidth; j++) {
					m_field[j][i].SetStop();
				}
			}
		}
	}
}

/// <summary>
/// ブロックの生成処理
/// </summary>
void GameMain::CreatBlock()
{
	m_randShape = GetRand(SHAPE_MAX - 1);

	for (int i = 0; i < m_shape->shapes[m_randShape][0].height; i++) {
		for (int j = 0; j < m_shape->shapes[m_randShape][0].width; j++) {
			if (m_shape->shapes[m_randShape][0].pattern[i][j] == 1) {
				m_field[j + 3][i].SetBlock(true, m_shape->shapes[m_randShape][0].color);
			}
		}
	}

}

/// <summary>
/// ブロックを消す処理
/// </summary>
/// <param name="y">消す列の座標</param>
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

/// <summary>
/// 着地しているか判定
/// </summary>
void GameMain::CheckRanding()
{

	m_stopflag = false;

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
	
}
