#include "TitleScene.h"
#include "InputState.h"
#include "SceneManager.h"
#include "GameplayingScene.h"
#include <DxLib.h>

void TitleScene::Update(const InputState& input) {
	if (input.IsTriggered(InputType::next)) {
		manager_.ChangeScene(new GameplayingScene(manager_));
		manager_.Init();
		return;
	}
}

void TitleScene::Draw() {
	DrawString(300, 200, "TitleScene", 0xffffff);
}