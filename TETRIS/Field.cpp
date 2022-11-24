#include <DxLib.h>
#include "Field.h"

namespace {

	constexpr int kFieldMinX = 0;
	constexpr int kFieldMinY = 0;
	constexpr int kFieldMaxX = 16*10;
	constexpr int kFieldMaxY = 16*22;

}

Field::Field() :
	m_minfield(),
	m_maxfield()
{}

Field::~Field()
{}

void Field::Init() {

	m_minfield.x = kFieldMinX;
	m_minfield.y = kFieldMinY;
	m_maxfield.x = kFieldMaxX;
	m_maxfield.y = kFieldMaxY;

}
void Field::End() {



}

void Field::Update() {



}

void Field::Draw() {

	DrawBox(m_minfield.x, m_minfield.y, m_maxfield.x, m_maxfield.y, GetColor(0, 0, 0), true);

}
