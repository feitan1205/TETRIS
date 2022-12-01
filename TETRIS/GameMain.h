#include <DxLib.h>
#include "Field.h"

class InputState;

class GameMain {

public:

	GameMain();
	~GameMain();

	void Init();
	void End();

	void Update(const InputState& input);

	void Draw();

	void MoveBlock(int x,int y,int color);

	void CreatBlock(int x, int y, int color);

	void ClearBlock(int y);

private:

	Field m_field[10][22];
	float movespeed;
	bool stopflag;
};