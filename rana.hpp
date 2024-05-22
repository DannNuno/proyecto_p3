#ifndef rana_h
#define rana_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Rana{
    private:
    Texture ranaTexture;
    Texture ranaTexture_2;
    Texture dialogo;

    vector<Texture> idleFrames;
    size_t currentFrame = 0;
    float frameTime = 0.5f;
    float currentTime = 0.f;

    public:
    Sprite sprite_rana;
    Sprite sprite_dialogo;
    Rana();
    void update(float deltaTime,Sprite sprite, RenderWindow &window);
    float calcular_dist(Vector2f s1, Vector2f s2);
    void hablar(RenderWindow &window);

};

#endif