#pragma once
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

	enum struct tetrimino{
		T,
		L,
		R,
		I,
		O,
		S,
		Z,
	};

};

