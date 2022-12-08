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

struct ShapeData{

	int color;
	int height, width;
	int pattern[SHAPE_WIDTH_MAX][SHAPE_WIDTH_MAX];

};

class Shape
{
private:

	int randShape;

public:

	ShapeData shapes[SHAPE_MAX][4];

	Shape();
	~Shape();

	void SetShapeData();

	void CreatShape();

};

