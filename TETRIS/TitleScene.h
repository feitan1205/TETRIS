#pragma once
#include "Scene.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class TitleScene :
    public Scene
{
public:
    TitleScene(SceneManager& manager) : Scene(manager){};
    ~TitleScene() {};

    void Update(const InputState& input);
    void Draw();
};

