#include "GameMain.h"


GameMain::GameMain()	:
	m_field(nullptr)
{
	//ˆ—‚È‚µ
}

GameMain::~GameMain() 
{}

void GameMain::Init() {

	m_field = new Field();

	m_field->Init();

}
void GameMain::End() {

	m_field->End();

}

void GameMain::Update() {

	m_field->Update();

}

void GameMain::Draw() {

	m_field->Draw();

}