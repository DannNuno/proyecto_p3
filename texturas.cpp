#include <SFML/Graphics.hpp>
#include <iostream>
#include "texturas.hpp"
using namespace sf;
using namespace std;

texturitas::texturitas(){
    if(!this->textura_hongo.loadFromFile("assets/hongo_mario.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->textura_hongo.setRepeated(true);
}