#pragma once
#include "Scene.h"

class GameMain;

class GameplayingScene :
    public Scene
{
public:
    GameplayingScene(SceneManager& manager) : Scene(manager){};
    ~GameplayingScene() {}
    void Init();
    void End();
    void Update(const InputState& input);
    void Draw();

private:

    GameMain* m_pgamemain = nullptr;

};

