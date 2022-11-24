#include "InputState.h"
#include <DxLib.h>

void InputState::Update() {
	for (int i = 0; i < _countof(lastKeystate); ++i) {
		lastKeystate[i] = keystate[i];
	}
	GetHitKeyStateAll(keystate);
}

bool InputState::IsPressed(InputType type)const {
	if (type == InputType::next) {
		return lastKeystate[KEY_INPUT_RETURN];
	}
	return false;
}

bool InputState::IsTriggered(InputType type)const {
	if (type == InputType::next) {
		return !lastKeystate[KEY_INPUT_RETURN] &&
			keystate[KEY_INPUT_RETURN];
	}
	return false;
}