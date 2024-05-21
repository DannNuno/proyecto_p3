#include <SFML/Graphics.hpp>
#include <iostream>
#include "pollo.hpp"
using namespace sf;
using namespace std;

Pollito::Pollito(){
    if(!this->polloTexture.loadFromFile("assets/pollito.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture.setRepeated(true);

    if(!this->polloTexture_2.loadFromFile("assets/pollito_otrolado.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture_2.setRepeated(true);

    this->sprite_pollo.setTexture(this->polloTexture);
    this->sprite_pollo.setScale(6,6);
}

void Pollito::mover(){

this->sprite_pollo.move(this->speed_x,this->speed_y);

}

void Pollito::correr(){
    this->speed_x = speed_x*2;
    this->speed_y = speed_y*2;
}

void Pollito::update(){

                if(Keyboard::isKeyPressed(Keyboard::D)){
                    this->sprite_pollo.setTexture(this->polloTexture);
                    this->speed_x = 1;
                    this->speed_y = 0;
                    if(Keyboard::isKeyPressed(Keyboard::Space)){
                        this->correr();
                    }
                    this->mover();
                }

                if(Keyboard::isKeyPressed(Keyboard::A)){
                    this->sprite_pollo.setTexture(this->polloTexture_2);
                    this->speed_x = -1;
                    this->speed_y = 0;
                     if(Keyboard::isKeyPressed(Keyboard::Space)){
                        this->correr();
                    }
                    this->mover();
                }

                if(Keyboard::isKeyPressed(Keyboard::W)){
                    this->speed_x = 0;
                    this->speed_y = -1;
                     if(Keyboard::isKeyPressed(Keyboard::Space)){
                        this->correr();
                    }
                    this->mover();
                }

                if(Keyboard::isKeyPressed(Keyboard::S)){
                    this->speed_x = 0;
                    this->speed_y = 1;
                     if(Keyboard::isKeyPressed(Keyboard::Space)){
                        this->correr();
                    }
                    this->mover();
                }
}