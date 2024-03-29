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
	if (type == InputType::left) {
		return lastKeystate[KEY_INPUT_LEFT];
	}
	if (type == InputType::right) {
		return lastKeystate[KEY_INPUT_RIGHT];
	}
	if (type == InputType::fast) {
		return lastKeystate[KEY_INPUT_DOWN];
	}
	if (type == InputType::jump) {
		return lastKeystate[KEY_INPUT_SPACE];
	}
	return false;
}

bool InputState::IsTriggered(InputType type)const {
	if (type == InputType::next) {
		return !lastKeystate[KEY_INPUT_RETURN] &&
			keystate[KEY_INPUT_RETURN];
	}
	if (type == InputType::left) {
		return !lastKeystate[KEY_INPUT_LEFT] &&
			keystate[KEY_INPUT_LEFT];
	}
	if (type == InputType::right) {
		return !lastKeystate[KEY_INPUT_RIGHT] &&
			keystate[KEY_INPUT_RIGHT];
	}
	if (type == InputType::fast) {
		return !lastKeystate[KEY_INPUT_DOWN] &&
			keystate[KEY_INPUT_DOWN];
	}
	if (type == InputType::jump) {
		return !lastKeystate[KEY_INPUT_SPACE] &&
			keystate[KEY_INPUT_SPACE];
	}
	if (type == InputType::spin) {
		return !lastKeystate[KEY_INPUT_UP] &&
			keystate[KEY_INPUT_UP];
	}
	if (type == InputType::hold) {
		return !lastKeystate[KEY_INPUT_C] &&
			keystate[KEY_INPUT_C];
	}
	return false;
}