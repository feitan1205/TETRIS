#pragma once

#include "Vec2.h"

namespace {
	constexpr int SHAPE_HEIGHT_MAX = 4;
	constexpr int SHAPE_WIDTH_MAX = 4;
}

class object
{
public:

	object();
	~object();

	void Init();

	void End();

	void Update();
	void Draw();

	bool GetIsMoveObject() { return isMoveObject; }

private:

	bool isMoveObject;

	int objectnum;

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
		int Red, Green, Blue;
		int width, height;
		int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
	}SHAPE;

	SHAPE shapes[SHAPE_MAX] = {
		//SHAPE_T,
		{
			//color
			255,0,0,
			//int width, height;
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0},
				{1,1,1},
				{0,1,0}
			}
		},
		//SHAPE_L,
		{
			//color
			0,255,0,
			//int width, height;
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,1,0},
				{0,1,0},
				{0,1,1}
			}
		},
		//SHAPE_J,
		{
			//color
			0,0,255,
			//int width, height;
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,1,0},
				{0,1,0},
				{1,1,0}
			}
		},
		//SHAPE_I,
		{
			//color
			255,255,0,
			//int width, height;
			4,4,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0}
			}
		},
		//SHAPE_O,
		{
			//color
			255,0,255,
			//int width, height;
			2,2,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{1,1},
				{1,1}
			}
		},
		//SHAPE_S,
		{
			//color
			0,255,255,
			//int width, height;
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0},
				{0,1,1},
				{1,1,0}
			}
		},
		//SHAPE_Z,
		{
			//color
			0,0,0,
			//int width, height;
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0},
				{1,1,0},
				{0,1,1}
			}
		},
	};
		
};

