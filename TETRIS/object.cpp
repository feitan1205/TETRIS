#include <DxLib.h>
#include "object.h"

object::object():
	objectnum(),
	isMoveObject(false)
{
}

object::~object() {

}

void object::Init() {

	objectnum = GetRand(SHAPE_MAX);

}

void object::End() {

}

void object::Update() {

}

void object::Draw() {
	
}