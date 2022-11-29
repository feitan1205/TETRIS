#include <DxLib.h>
#include "Field.h"
#include "game.h"
#include "object.h"

namespace {

	constexpr int kFieldMaxX = 16*10;
	constexpr int kFieldMaxY = 16*22;

}

Field::Field() :
	m_minfield(),
	m_maxfield(),
	m_pObject()
{}

Field::~Field()
{}

void Field::Init() {

	m_pObject = new object();

}
void Field::End() {

	m_pObject->End();

}

void Field::Update() {

	m_pObject->Update();

}

void Field::Draw() {

	m_minfield.x = (Game::kScreenWidth / 2) - (kFieldMaxX / 2);
	m_minfield.y = (Game::kScreenHeight / 2) - (kFieldMaxY / 2);
	m_maxfield.x = m_minfield.x + kFieldMaxX;
	m_maxfield.y = m_minfield.y + kFieldMaxY;

	DrawBox(m_minfield.x,m_minfield.y,m_maxfield.x, m_maxfield.y, GetColor(0, 0, 0), true);

}
