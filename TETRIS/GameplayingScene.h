#pragma once
#include "Scene.h"


class GameplayingScene :
    public Scene
{
public:
    GameplayingScene(SceneManager& manager) : Scene(manager) {};
    ~GameplayingScene() {}
    void Update(const InputState& input);
    void Draw();
};

