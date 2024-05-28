#ifndef mapa_h
#define mapa_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Mapa{
       private:
    Texture mapa1_Texture;
    Texture mapa2_Texture;
    Texture mapa3_Texture;
    Texture mapa4_Texture;
 public:
    Sprite sprite_mapa;
    int nivel;

    Mapa();
    void cambiarmapa(Sprite *sprite);

};

#endif