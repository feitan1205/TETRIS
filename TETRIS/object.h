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
	int height, width;
	int pattern[SHAPE_WIDTH_MAX][SHAPE_WIDTH_MAX];

}SHAPE;

class object
{
private:

	SHAPE shapes[SHAPE_MAX];

public:

	object() {}
	~object() {}

	void setShapeData();

};

