#ifndef objeto_h
#define objeto_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Objeto{
    private:
    Texture textura_objeto;

    public:
    Sprite sprite_objeto;
    bool en_mapa = true;
    void update(RenderWindow &window);

    Objeto();
    float calcular_dist(Vector2f s1, Vector2f s2);
    Texture getTextura();

};

#endif