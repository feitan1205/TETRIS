#pragma once
#include "Vec2.h"

class object;

class Field
{
public:

	Field();
	~Field();

	void Init();
	void End();

	void SetBlock(bool flag,int color);
	void DeleteExist();

	void Update();

	void Draw(int i,int j);

	bool GetIsExist() { return isExistBlock; }
	bool GetIsMove() { return isMoveBlock; }
	void SetIsMoved(bool flag) { isMovedBlock = flag; }
	bool GetIsMoved() { return isMovedBlock; }
	void SetStop() { isMoveBlock = false; }
private:

	bool isExistBlock;
	bool isMoveBlock;
	bool isMovedBlock;
	int blockColor;

};

