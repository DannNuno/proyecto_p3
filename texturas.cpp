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

    texturas_hongo.push_back(textura_hongo);

    if(!this->textura_dialogo.loadFromFile("assets/hola.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->textura_dialogo.setRepeated(true);

    this->texturas_dialogo_hongo.push_back(textura_dialogo);
}