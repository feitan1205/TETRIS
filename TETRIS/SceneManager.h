#pragma once

class Scene;
class InputState;

class SceneManager
{
private:
	Scene* scene_ = nullptr;
public:
	void ChangeScene(Scene* scene);
	void Update(const InputState& input);
	void Draw();
};

