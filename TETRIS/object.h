#pragma once

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

private:

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
		int width, height;
		int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
	}SHAPE;

	SHAPE shapes[SHAPE_MAX] = {
		//SHAPE_T,
		{
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
