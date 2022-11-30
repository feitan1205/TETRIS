#include <DxLib.h>
#include "Field.h"

class InputState;

class GameMain {

public:

	GameMain();
	~GameMain();

	void Init();
	void End();

	void Update();

	void Draw();

	void MoveBlock(int x,int y,int color);

private:

	Field m_field[10][22];
	float movespeed;
	InputState input;
};