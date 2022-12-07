#include "object.h"



void object::setShapeData()
{
	shapes[SHAPE_T] = {
		//SHAPE_T,
			//color
			0xff0000,
			//height,width
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,0,0},
				{1,1,1},
				{0,1,0}
			}
	};

	shapes[SHAPE_L] = {
		//SHAPE_L
			//color
			0xff0000,
			//height,width
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,1,0},
				{0,1,0},
				{0,1,1}
			}
	};

	shapes[SHAPE_J] = {
		//SHAPE_J,

			//color
			0xff0000,
			//height,width
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,1,0},
				{0,1,0},
				{1,1,0}
			}
	};

	shapes[SHAPE_I] = {
		//SHAPE_I,
			//color
			0xff0000,
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

	shapes[SHAPE_O] = {
		//SHAPE_O,
		//color
			0xff0000,
			//height,width
			2,2,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{1,1},
				{1,1}
			}
	};

	shapes[SHAPE_S] = {
		//SHAPE_S,
		//color
			0xff0000,
			//height,width
			3,3,
			//int pattern[SHAPE_HEIGHT_MAX][SHAPE_WIDTH_MAX];
			{
				{0,1,1},
				{1,1,0},
				{0,0,0}
			}
	};

	shapes[SHAPE_Z] = {
		//SHAPE_Z,
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
}
