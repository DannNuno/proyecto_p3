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

    vector<Texture> idleFrames;
    size_t currentFrame = 0;
    float frameTime = 0.5f;
    float currentTime = 0.f;

    public:
    Sprite sprite_rana;
    Rana();
    void update(float deltaTime);

};

#endif