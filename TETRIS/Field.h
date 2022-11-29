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

	void Update();

	void Draw();

private:

	Vec2 m_minfield;
	Vec2 m_maxfield;

	object* m_pObject;

};

