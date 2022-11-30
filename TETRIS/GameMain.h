#include <DxLib.h>
#include "Field.h"

class GameMain {

public:

	GameMain();
	~GameMain();

	void Init();
	void End();

	void Update();

	void Draw();

private:

	Field m_field[10][22];
	float movespeed;
};