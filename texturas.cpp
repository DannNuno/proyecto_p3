#include <SFML/Graphics.hpp>
#include <iostream>
#include "texturas.hpp"
using namespace sf;
using namespace std;

texturitas::texturitas(){

    //HONGO
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

    //OSO
    if(!this->textura_oso1.loadFromFile("assets/oso.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->textura_oso1.setRepeated(true);

    if(!this->textura_oso2.loadFromFile("assets/oso2.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->textura_oso2.setRepeated(true);

    if(!this->textura_oso3.loadFromFile("assets/oso3.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->textura_oso3.setRepeated(true);

    if(!this->textura_oso4.loadFromFile("assets/oso4.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->textura_oso4.setRepeated(true);

    texturas_oso1.push_back(textura_oso1);
    texturas_oso1.push_back(textura_oso2);

    texturas_oso2.push_back(textura_oso3);
    texturas_oso2.push_back(textura_oso4);

    this->texturas_dialogo_oso.push_back(textura_dialogo);
}