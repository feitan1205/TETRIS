#include <DxLib.h>
#include "Field.h"

class InputState;

namespace {
	constexpr int SHAPE_HEIGHT_MAX = 4;
	constexpr int SHAPE_WIDTH_MAX = 4;
}

enum {
	SHAPE_T,
	SHAPE_L,
	SHAPE_J,
	SHAPE_I,
	SHAPE_O,
	SHAPE_S,
	SHAPE_Z,
	SHAPE_MAX
};

typedef struct {

	int color;
	int height, width;
	int pattern[SHAPE_WIDTH_MAX][SHAPE_WIDTH_MAX];

}SHAPE;

class GameMain {

public:

	GameMain();
	~GameMain();

	void Init();
	void End();

	void Update(const InputState& input);

	void Draw();

	void SetObjectDate();

	void DownMoveBlock(int x,int y,int color);
	void LeftMoveBlock(int x, int y, int color);
	void RightMoveBlock(int x, int y, int color);

	void JumpBlock(int color);

	void CreatBlock();

	void ClearBlock(int y);

	void CheckRanding();

	bool GetGameOver() { return isGameOverFlag; }

private:

	Field m_field[10][22];
	SHAPE shapes[SHAPE_MAX];
	float movespeed;
	bool stopflag;
	int randShape;
	bool isGameOverFlag;
};