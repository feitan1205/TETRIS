#pragma once
#include "Scene.h"

class GameoverScene :
    public Scene
{
public:
    GameoverScene(SceneManager& manager) : Scene(manager) {};
    ~GameoverScene() {}
    void Update(const InputState& input);
    void Draw();
};

