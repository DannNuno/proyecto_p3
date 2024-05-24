#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "rana.hpp"
using namespace sf;
using namespace std;

Rana::Rana(){
   if(!this->ranaTexture.loadFromFile("assets/rana.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->ranaTexture.setRepeated(true);

    if(!this->ranaTexture_2.loadFromFile("assets/rana2.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->ranaTexture_2.setRepeated(true);

    if(!this->dialogo.loadFromFile("assets/hola.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->dialogo.setRepeated(true);

    if(!this->dialogo_2.loadFromFile("assets/soy_rana.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->dialogo_2.setRepeated(true);

    dialogos_index = 0;
    this->sprite_dialogo.setTexture(dialogo);
    this->sprite_dialogo.setScale(10,10);

    this->sprite_rana.setTexture(ranaTexture);
    this->sprite_rana.setScale(6,6);

    this->idleFrames.push_back(ranaTexture);
    this->idleFrames.push_back(ranaTexture_2);

    this->dialogos.push_back(dialogo);
    this->dialogos.push_back(dialogo_2);
}

void Rana::update(float deltaTime, Sprite sprite, RenderWindow &window){
    currentTime += deltaTime;
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        sprite_rana.setTexture(idleFrames[currentFrame]); 
    }
    if(calcular_dist(sprite.getPosition(), this->sprite_rana.getPosition()) <= 150){
        //hay errores al hablar
        if(Keyboard::isKeyPressed(Keyboard::Enter)){
            if(dialogos_index < dialogos.size()){
                cout << "dialogo num." << dialogos_index << endl;
                hablar(dialogos_index);
                dialogos_index = (dialogos_index + 1) % dialogos.size();
            } else {
                dialogos_index = 0;
                hablando = false;
                cout << "no hablando" << endl;
            }
        }
    } else {
        hablando = false;
        cout << "no hablando" << endl;
    }
}

float Rana::calcular_dist(Vector2f s1, Vector2f s2){
    float dist_x = s1.x - s2.x;
    float dist_y = s1.y - s2.y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

void Rana::hablar(int dialogo_actual){
    sprite_dialogo.setTexture(dialogos[dialogo_actual]);
    hablando = true;
}

void Rana::drawDialog(RenderWindow &window) {
    if (hablando){
        window.draw(sprite_dialogo);
    }
}