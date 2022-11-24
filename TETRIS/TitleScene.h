#pragma once
#include "Scene.h"

/// <summary>
/// タイトルシーン
/// </summary>
class TitleScene :
    public Scene
{
public:
    TitleScene(SceneManager& manager) : Scene(manager){};
    ~TitleScene() {};

    void Init() {};

    void End() {};

    void Update(const InputState& input);
    void Draw();
};

