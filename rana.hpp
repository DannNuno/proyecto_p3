#ifndef rana_h
#define rana_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include "pollo.hpp"
#include "objeto.hpp"
using namespace sf;
using namespace std;

class Pollito;
class Objeto;

class Rana{
    private:
    Texture ranaTexture;
    Texture ranaTexture_2;
    Texture dialogo;
    Texture dialogo_2;
    int dialogos_index;

    vector<Texture> idleFrames;
    vector<Texture> dialogos;
    size_t currentFrame = 0;
    float frameTime = 0.5f;
    float currentTime = 0.f;


    public:
    Sprite sprite_rana;
    Sprite sprite_dialogo;
    Rana();
    void update(float deltaTime, Pollito &pollito, Objeto *objetoMision);
    float calcular_dist(Vector2f s1, Vector2f s2);
    void habla(Sprite sprite);
    void hablar(int dialogo_actual);
    void drawDialog(RenderWindow &window);
    void mision(Pollito &pollo, Objeto *objetoMision);
    bool hablando = false;

};

#endif