#include <DxLib.h>
#include "Field.h"

class InputState;
class Shape;
struct ShapeData;

class GameMain {

public:

	GameMain();
	~GameMain();

	void Init();
	void End();

	void Update(const InputState& input);

	void Draw();

	void DownMoveBlock(int color);
	void LeftMoveBlock(int color);
	void RightMoveBlock(int color);

	void JumpBlock(int color);

	void CreatBlock();

	void ClearBlock(int y);

	void CheckRanding();

	bool GetGameOver() { return m_isGameOverFlag; }

private:

	Field m_field[10][22];
	Shape* m_shape;
	float m_movespeed;
	float m_waitStop;
	bool m_stopflag;
	int m_randShape;
	bool m_isGameOverFlag;
};