#pragma once
class SceneManager;
class InputState;
class Scene
{
protected:
	SceneManager& manager_;
public:
	Scene(SceneManager& manager):manager_(manager) {}
	virtual ~Scene() {};

	virtual void Init() = 0;

	virtual void End() = 0;

	//シーンを更新する
	virtual void Update(const InputState& input) = 0;
	//シーンを描画する
	virtual void Draw() = 0;
};

