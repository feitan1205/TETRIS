#pragma once

enum class InputType {
	next,//次へ行くボタン
	left,
	right,
	fast,
	jump,
	spin,
	hold
};

class InputState
{
private:
	int keypadState;
	int lastKeypadState;
	char keystate[256];
	char lastKeystate[256];
public:
	bool IsTriggered(InputType type)const;
	bool IsPressed(InputType type)const;
	void Update();
};

