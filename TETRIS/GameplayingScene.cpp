#include "GameplayingScene.h"
#include "SceneManager.h"
#include "InputState.h"
#include "GameoverScene.h"
#include "GameMain.h"
#include "game.h"
#include <DxLib.h>

void GameplayingScene::Init() {

	m_pgamemain = new GameMain();

	m_pgamemain->Init();

}

void GameplayingScene::End() {

	m_pgamemain->End();

}

void GameplayingScene::Update(const InputState& input) {

	m_pgamemain->Update();

	if (input.IsTriggered(InputType::next)) {
		manager_.ChangeScene(new GameoverScene(manager_));
		manager_.Init();
		return;
	}
}

void GameplayingScene::Draw() {

	//DrawBox(0, 0,Game::kScreenWidth,Game::kScreenHeight, GetColor(150, 150, 150), true);

	m_pgamemain->Draw();

}