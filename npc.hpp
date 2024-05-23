#ifndef npc_h
#define npc_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class NPC{
    private:
    Texture npcTexture;
    Texture dialogo;

    vector<Texture> idleFrames;
    size_t currentFrame = 0;
    float frameTime = 0.5f;
    float currentTime = 0.f;
    bool hablando = false;

    public:
    Sprite sprite_npc;
    Sprite sprite_dialogo;
    NPC();
    void update(float deltaTime,Sprite sprite, RenderWindow &window);
    float calcular_dist(Vector2f s1, Vector2f s2);
    void hablar();
    void drawDialog(RenderWindow &window);

};

#endif