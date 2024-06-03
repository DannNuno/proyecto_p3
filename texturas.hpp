#ifndef texturas_h
#define texturas_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class texturitas{
    public:
    Texture textura_hongo;
    Texture textura_dialogo;
    vector<Texture> texturas_hongo;
    vector<Texture> texturas_dialogo_hongo;

    texturitas();
};

#endif