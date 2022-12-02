#pragma once

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
	int width, height;
	int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
}SHAPE;

SHAPE shapes[SHAPE_MAX] = {
	//SHAPE_T,
	{
		//color
		0xff0000,
		//int width, height;
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,1,1},
			{0,0,1,0},
			{0,0,0,0}
		}
	},
	//SHAPE_L,
	{
		//color
		0xff0000,
		//int width, height;
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,1,0}
			
		}
	},
	//SHAPE_J,
	{
		//color
		0xff0000,
		//int width, height;
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,1,1,0}
		}
	},
	//SHAPE_I,
	{
		//color
		0xff0000,
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
		0xff0000,
		//int width, height;
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	},
	//SHAPE_S,
	{
		//color
		0xff0000,
		//int width, height;
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,0,0,0}
		}
	},
	//SHAPE_Z,
	{
		//color
		0xff0000,
		//int width, height;
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1},
			{0,0,0,0}
		}
	},
};

