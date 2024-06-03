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

    Texture textura_oso1;
    Texture textura_oso2;
    Texture textura_oso3;
    Texture textura_oso4;
    vector<Texture> texturas_oso1;
    vector<Texture> texturas_oso2;
    vector<Texture> texturas_dialogo_oso;

    texturitas();
};

#endif