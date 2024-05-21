#ifndef pollo_h
#define pollo_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Pollito{
    private:
    Texture polloTexture;
    Texture polloTexture_2;

    public:
    Sprite sprite_pollo;
    float speed_x=1;
    float speed_y=1;

    Pollito();
    void mover();
    void correr();
    void update();

};

#endif