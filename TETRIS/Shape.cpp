#include "Shape.h"
#include "DxLib.h"

Shape::Shape():
	shapes(),
	randShape()
{
}

Shape::~Shape()
{
}

void Shape::SetShapeData()
{
	/// <summary>
	/// SHAPE_T
	/// </summary>
	shapes[SHAPE_T][0] = {
		//color
		0xa260bf,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0},
			{1,1,1},
			{0,0,0}
		}
	};
	shapes[SHAPE_T][1] = {
		//color
		0xa260bf,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0},
			{0,1,1},
			{0,1,0}
		}
	};
	shapes[SHAPE_T][2] = {
		//color
		0xa260bf,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0},
			{1,1,1},
			{0,1,0}
		}
	};
	shapes[SHAPE_T][3] = {
		//color
		0xa260bf,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0},
			{1,1,0},
			{0,1,0}
		}
	};

	/// <summary>
	/// SHAPE_L
	/// </summary>
	shapes[SHAPE_L][0] = {
		//color
		0xfd7e00,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0},
			{0,1,0},
			{0,1,1}
		}
	};
	shapes[SHAPE_L][1] = {
		//color
		0xfd7e00,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0},
			{1,1,1},
			{1,0,0}
		}
	};
	shapes[SHAPE_L][2] = {
		//color
		0xfd7e00,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{1,1,0},
			{0,1,0},
			{0,1,0}
		}
	};
	shapes[SHAPE_L][3] = {
		//color
		0xfd7e00,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,1},
			{1,1,1},
			{0,0,0}
		}
	};

	/// <summary>
	/// SHAPE_J
	/// </summary>
	shapes[SHAPE_J][0] = {
		//color
		0x0000ff,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0},
			{0,1,0},
			{1,1,0}
		}
	};
	shapes[SHAPE_J][1] = {
		//color
		0x0000ff,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{1,0,0},
			{1,1,1},
			{0,0,0}
		}
	};
	shapes[SHAPE_J][2] = {
		//color
		0x0000ff,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,1},
			{0,1,0},
			{0,1,0}
		}
	};
	shapes[SHAPE_J][3] = {
		//color
		0x0000ff,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0},
			{1,1,1},
			{0,0,1}
		}
	};

	/// <summary>
	/// SHAPE_I
	/// </summary>
	shapes[SHAPE_I][0] = {
		//color
		0xa9ceec,
		//height,width
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		}
	};
	shapes[SHAPE_I][1] = {
		//color
		0xa9ceec,
		//height,width
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		}
	};
	shapes[SHAPE_I][2] = {
		//color
		0xa9ceec,
		//height,width
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}
		}
	};
	shapes[SHAPE_I][3] = {
		//color
		0xa9ceec,
		//height,width
		4,4,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		}
	};

	/// <summary>
	/// SHAPE_O
	/// </summary>
	for (int i = 0; i < 4; i++) {
		shapes[SHAPE_O][i] = {
			//SHAPE_O,
			//color
				0xffff00,
				//height,width
				2,2,
				//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
				{
					{1,1},
					{1,1}
				}
		};
	}

	/// <summary>
	/// SHAPE_S
	/// </summary>
	shapes[SHAPE_S][0] = {
		//color
		0xb9c42f,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,1},
			{1,1,0},
			{0,0,0}
		}
	};
	shapes[SHAPE_S][1] = {
		//color
		0xb9c42f,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0},
			{0,1,1},
			{0,0,1}
		}
	};
	shapes[SHAPE_S][2] = {
		//color
		0xb9c42f,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0},
			{0,1,1},
			{1,1,0}
		}
	};
	shapes[SHAPE_S][3] = {
		//color
		0xb9c42f,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{1,0,0},
			{1,1,0},
			{0,1,0}
		}
	};

	/// <summary>
	/// SHAPE_Z
	/// </summary>
	shapes[SHAPE_Z][0] = {
		//color
		0xff0000,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{1,1,0},
			{0,1,1},
			{0,0,0},
		}
	};
	shapes[SHAPE_Z][1] = {
		//color
		0xff0000,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,1},
			{0,1,1},
			{0,1,0},
		}
	};
	shapes[SHAPE_Z][2] = {
		//color
		0xff0000,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,0,0},
			{1,1,0},
			{0,1,1},
		}
	};
	shapes[SHAPE_Z][3] = {
		//color
		0xff0000,
		//height,width
		3,3,
		//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
		{
			{0,1,0},
			{1,1,0},
			{1,0,0},
		}
	};

}

void Shape::CreatShape()
{

	randShape = GetRand(SHAPE_MAX);

}

