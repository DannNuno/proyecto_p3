#include <SFML/Graphics.hpp>
#include <iostream>
#include "objeto.hpp"
#include <cmath>
using namespace sf;
using namespace std;

Objeto::Objeto(){
    if(!this->textura_objeto.loadFromFile("assets/manzana.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->textura_objeto.setRepeated(true);

    this->sprite_objeto.setTexture(textura_objeto);
    this->sprite_objeto.setScale(6,6);
}

void Objeto::update(RenderWindow &window){
    if(this->en_mapa){
        window.draw(this->sprite_objeto);
    }
}

float Objeto::calcular_dist(Vector2f s1, Vector2f s2){
    float dist_x = s1.x - s2.x;
    float dist_y = s1.y - s2.y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

Texture Objeto::getTextura(){
    return textura_objeto;
}