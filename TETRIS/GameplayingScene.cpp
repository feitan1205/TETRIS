#include "GameplayingScene.h"
#include "SceneManager.h"
#include "InputState.h"
#include "GameoverScene.h"
#include <DxLib.h>

void GameplayingScene::Update(const InputState& input) {
	if (input.IsTriggered(InputType::next)) {
		manager_.ChangeScene(new GameoverScene(manager_));
		return;
	}
}

void GameplayingScene::Draw() {
	DrawString(300, 200, "GameplayingScene", 0xffffff);
}