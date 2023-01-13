#include "GameMain.h"
#include "InputState.h"
#include "Shape.h"

namespace {

	constexpr int kfieldheight = 22;
	constexpr int kfieldwidth = 10;
	constexpr float kspeed = 0.05f;
}

GameMain::GameMain() :
	m_field(),
	m_shape(nullptr),
	m_color(),
	m_blockvec(),
	m_blockX(),
	m_blockY(),
	m_movespeed(),
	m_waitStop(),
	m_stopflag(false),
	m_randShape(),
	m_isGameOverFlag(false),
	m_holdShape(),
	m_ishold(false),
	m_isholded(false),
	m_score(),
	m_clearnum()
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

	for (int i = 0; i < 6; i++) {
		m_randShape[i] = GetRand(SHAPE_MAX - 1);
	}

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

	if (input.IsTriggered(InputType::hold) && !m_isholded) {
		HoldBlock();
		m_isholded = true;
	}

	if (input.IsTriggered(InputType::left)) {
		LeftMoveBlock(m_color);
		m_blockX--;
	}
	else if (input.IsTriggered(InputType::right)) {
		RightMoveBlock(m_color);
		m_blockX++;
	}
	else if (input.IsTriggered(InputType::jump)) {
		JumpBlock(m_color);
	}
	else if (input.IsTriggered(InputType::spin)) {
		SpinBlock();
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
					m_clearnum++;
					i++;
				}
				continue;
			}
		}

		CheckRanding();

		if (m_clearnum == 1) {
			m_score += 300;
		}
		if (m_clearnum == 2) {
			m_score += 800;
		}
		if (m_clearnum == 3) {
			m_score += 1200;
		}
		if (m_clearnum == 4) {
			m_score += 2000;
		}

		CreatBlock();

		m_clearnum = 0;

		m_stopflag = false;

		m_isholded = false;

		m_waitStop = 1;

		return;
	}

	if (input.IsPressed(InputType::fast)) {
		DownMoveBlock(m_color);
		m_blockY++;
	}
	else if (!input.IsPressed(InputType::fast)) {
		if (m_movespeed < 0) {
			DownMoveBlock(m_color);
			m_blockY++;
			m_movespeed = 1;
		}
	}

}

/// <summary>
/// ゲームの描画処理
/// </summary>
void GameMain::Draw() {

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			m_field[j][i].Draw(i,j,m_color);
		}
	}

	DrawBox(500, 110, 600, 450, 0xffffff, false);

	for (int k = 1; k <= 5; k++) {

		for (int i = 0; i < m_shape->shapes[m_randShape[k]][0].height; i++) {
			for (int j = 0; j < m_shape->shapes[m_randShape[k]][0].width; j++) {
				if (m_shape->shapes[m_randShape[k]][0].pattern[i][j] == 0) {
					continue;
				}
				else if (m_shape->shapes[m_randShape[k]][0].pattern[i][j] == 1) {
					DrawBox(j * 12 + 520, i * 12 + 80 + k * 60, j * 12 + 12 + 520, i * 12 + 12 + 80 + k * 60, m_shape->shapes[m_randShape[k]][m_blockvec].color, true);
					DrawBox(j * 12 + 520, i * 12 + 80 + k * 60, j * 12 + 12 + 520, i * 12 + 12 + 80 + k * 60, 0x000000, false);
				}
			}
		}

	}

	DrawBox(100, 100, 200, 200, 0xffffff, false);

	if (m_ishold) {
		for (int i = 0; i < m_shape->shapes[m_holdShape][0].height; i++) {
			for (int j = 0; j < m_shape->shapes[m_holdShape][0].width; j++) {
				if (m_shape->shapes[m_holdShape][0].pattern[i][j] == 0) {
					continue;
				}
				else if (m_shape->shapes[m_holdShape][0].pattern[i][j] == 1) {
					DrawBox(j * 12 + 120, i * 12 + 120, j * 12 + 12 + 120, i * 12 + 12 + 120, m_shape->shapes[m_holdShape][m_blockvec].color, true);
					DrawBox(j * 12 + 120, i * 12 + 120, j * 12 + 12 + 120, i * 12 + 12 + 120, 0x000000, false);
				}
			}
		}
	}

	DrawFormatString(500, 550, 0xffffff, "score：%d", m_score, false);

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

	CheckRanding();

	if (m_stopflag) {
		return;
	}

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

	m_stopflag = true;

	m_waitStop = -1;
	
}

/// <summary>
/// ブロックの生成処理
/// </summary>
void GameMain::CreatBlock()
{
	//GetRand(SHAPE_MAX - 1)

	for (int i = 0; i < 5; i++) {
		m_randShape[i] = m_randShape[i + 1];
	}
	
	m_blockvec = 0;

	for (int i = 0; i < m_shape->shapes[m_randShape[0]][m_blockvec].height; i++) {
		for (int j = 0; j < m_shape->shapes[m_randShape[0]][m_blockvec].width; j++) {
			if (m_shape->shapes[m_randShape[0]][m_blockvec].pattern[i][j] == 1) {
				m_field[j + 3][i].SetBlock(true, m_shape->shapes[m_randShape[0]][m_blockvec].color);
			}
		}
	}

	m_color = m_shape->shapes[m_randShape[0]][0].color;
	m_blockX = 3;
	m_blockY = 0;

	m_randShape[5] = GetRand(SHAPE_MAX - 1);

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
				m_field[j][i + 1].SetBlock(false, m_field[j][i].GetColor());
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

/// <summary>
/// ブロックを回転させる処理
/// </summary>
void GameMain::SpinBlock()
{

	for (int i = 0; i < kfieldheight; i++) {
		for (int j = 0; j < kfieldwidth; j++) {
			if (m_field[j][i].GetIsMove()) {
				m_field[j][i].DeleteExist();
			}
		}
	}

	int tmpblockvec = m_blockvec;
	int tmpblockX = m_blockX;
	int tmpblockY = m_blockY;

	m_blockvec++;

	if (m_blockvec == 4) {
		m_blockvec = 0;
	}

	while (m_blockX + m_shape->shapes[m_randShape[0]][m_blockvec].width > 10) {
		m_blockX--;
	}

	while (m_blockX + m_shape->shapes[m_randShape[0]][m_blockvec].height > 21) {
		m_blockY--;
	}

	for (int i = 0; i < m_shape->shapes[m_randShape[0]][m_blockvec].height; i++) {
		for (int j = m_shape->shapes[m_randShape[0]][m_blockvec].width/ 2 ; j < m_shape->shapes[m_randShape[0]][m_blockvec].width; j++) {
			if (m_shape->shapes[m_randShape[0]][m_blockvec].pattern[i][j] == 1) {
				if (m_field[j + m_blockX][i + m_blockY].GetIsExist()) {
					m_blockX--;
				}
			}
		}
	}


	for (int i = 0; i < m_shape->shapes[m_randShape[0]][m_blockvec].height; i++) {
		for (int j = m_shape->shapes[m_randShape[0]][m_blockvec].width / 2 - 1 ; j >= 0; j--) {
			if (m_shape->shapes[m_randShape[0]][m_blockvec].pattern[i][j] == 1) {
				if (m_field[j + m_blockX][i + m_blockY].GetIsExist()) {
					m_blockX++;
				}
			}
		}
	}

	for (int j = m_shape->shapes[m_randShape[0]][m_blockvec].width / 2 - 1; j >= 0; j--) {
		for (int i = 0; i < m_shape->shapes[m_randShape[0]][m_blockvec].height; i++) {

		}
	}

	bool cantput = false;

	for (int i = 0; i < m_shape->shapes[m_randShape[0]][m_blockvec].height; i++) {
		for (int j = 0; j < m_shape->shapes[m_randShape[0]][m_blockvec].width; j++) {
			if (m_field[j + m_blockX][i + m_blockY].GetIsExist()) {
				cantput = true;
			}
		}
	}

	if (cantput) {
		m_blockvec = tmpblockvec;
		m_blockX = tmpblockX;
		m_blockY = tmpblockY;
	}

	if (m_blockX < 0) {
		m_blockX = 0;
	}

	for (int i = 0; i < m_shape->shapes[m_randShape[0]][m_blockvec].height; i++) {
		for (int j = 0; j < m_shape->shapes[m_randShape[0]][m_blockvec].width; j++) {
			if (m_shape->shapes[m_randShape[0]][m_blockvec].pattern[i][j] == 1) {
				m_field[j + m_blockX][i + m_blockY].SetBlock(true, m_shape->shapes[m_randShape[0]][m_blockvec].color);
			}
		}
	}

}

/// <summary>
/// ブロックをホールドする処理
/// </summary>
void GameMain::HoldBlock()
{
	if (!m_ishold) {

		m_holdShape = m_randShape[0];

		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (m_field[j][i].GetIsMove()) {
					m_field[j][i].DeleteExist();
				}
			}
		}

		CreatBlock();

		m_ishold = true;

		return;
	}

	int tmpShape = 99;

	if (m_ishold) {
		tmpShape = m_holdShape;
		m_holdShape = m_randShape[0];
		m_randShape[0] = tmpShape;

		for (int i = kfieldheight - 1; i >= 0; i--) {
			for (int j = 0; j < kfieldwidth; j++) {
				if (m_field[j][i].GetIsMove()) {
					m_field[j][i].DeleteExist();
				}
			}
		}

		for (int i = 0; i < m_shape->shapes[m_randShape[0]][m_blockvec].height; i++) {
			for (int j = 0; j < m_shape->shapes[m_randShape[0]][m_blockvec].width; j++) {
				if (m_shape->shapes[m_randShape[0]][m_blockvec].pattern[i][j] == 1) {
					m_field[j + 3][i].SetBlock(true, m_shape->shapes[m_randShape[0]][m_blockvec].color);
				}
			}
		}

		m_color = m_shape->shapes[m_randShape[0]][0].color;
		m_blockX = 3;
		m_blockY = 0;
	}

}

