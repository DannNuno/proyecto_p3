#include <SFML/Graphics.hpp>
#include <iostream>
#include "mapa.hpp"
using namespace sf;
using namespace std;

/*
nivel 1=fondo 3
nivel 2= fondo 4
nivel 3= fondo 1
nivel 4=fondo 2;

*/

Mapa::Mapa()
{
    if (!this->mapa1_Texture.loadFromFile("assets/fondo.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->mapa1_Texture.setRepeated(true);

    if (!this->mapa2_Texture.loadFromFile("assets/fondo_2.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->mapa2_Texture.setRepeated(true);

    if (!this->mapa3_Texture.loadFromFile("assets/fondo_3.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->mapa3_Texture.setRepeated(true);

    if (!this->mapa4_Texture.loadFromFile("assets/fondo_4.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->mapa4_Texture.setRepeated(true);

    this->sprite_mapa.setTexture(mapa3_Texture);
    this->nivel = 1;
    this->sprite_mapa.setScale(10, 10);
}

void Mapa::cambiarmapa(Sprite *sprite)
{
    if (nivel == 1)
    {
        if (sprite->getPosition().y < 0)
        {
            sprite->setPosition(sprite->getPosition().x, 0);
        }
        if (sprite->getPosition().x < -95)
        {
            this->sprite_mapa.setTexture(mapa4_Texture);
            sprite->setPosition(1800, sprite->getPosition().y);
            nivel = 2;
        }
    }

    if (nivel == 2)
    {
        if (sprite->getPosition().y > 920)
        {
            sprite->setPosition(sprite->getPosition().x, 920);
        }

        if (sprite->getPosition().x > 1920)
        {
            this->sprite_mapa.setTexture(mapa3_Texture);
            sprite->setPosition(0, sprite->getPosition().y);
            nivel = 1;
        }
        if(sprite->getPosition().y<0)
        {
            this->sprite_mapa.setTexture(mapa1_Texture);
            sprite->setPosition(sprite->getPosition().x,2080);
            nivel = 3;
        }
    }

    /*
       if (this->sprite_mapa.getTexture() == sprite_mapa.getTexture(mapa3_Texture)) {

        if(sprite->getPosition().y<0)
        {
            sprite->setPosition(sprite->getPosition().x,0);
        }
       }

        if(sprite->getPosition().x < -95){
            this->sprite_mapa.setTexture(mapa4_Texture);
            sprite->setPosition(1915,sprite->getPosition().y);
        }

        if(sprite->getPosition().x > 1920){
            this->sprite_mapa.setTexture(mapa3_Texture);
            sprite->setPosition(-95,sprite->getPosition().y);
        }

        if(sprite->getPosition().y > 1010){
            this->sprite_mapa.setTexture(mapa2_Texture);
            sprite->setPosition(sprite->getPosition().x,-90);
        }

        if(sprite->getPosition().y < -100){
            this->sprite_mapa.setTexture(mapa1_Texture);
            sprite->setPosition(sprite->getPosition().x,1005);
        }
        */
}

/*
if nivel =1;
sprite->setTexture(mapa3);
if <-   nivel = 2

*/