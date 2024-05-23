#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "rana.hpp"
using namespace sf;
using namespace std;

Rana::Rana(){
   if(!ranaTexture.loadFromFile("assets/rana.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    ranaTexture.setRepeated(true);

    if(!ranaTexture_2.loadFromFile("assets/rana2.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    ranaTexture_2.setRepeated(true);

    this->sprite_rana.setTexture(ranaTexture);
    this->sprite_rana.setScale(6,6);

    idleFrames.push_back(ranaTexture);
    idleFrames.push_back(ranaTexture_2);
}

void Rana::update(float deltaTime, Sprite sprite, RenderWindow &window){
    currentTime += deltaTime;
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        sprite_rana.setTexture(idleFrames[currentFrame]); 
    }
    if(calcular_dist(sprite.getPosition(), this->sprite_rana.getPosition()) <= 150){
        cout << "dialogo" << endl;
        hablar(window);
    }
}

float Rana::calcular_dist(Vector2f s1, Vector2f s2){
    float dist_x = s1.x - s2.x;
    float dist_y = s1.y - s2.y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

void Rana::hablar(RenderWindow &window){
    if(!dialogo.loadFromFile("assets/hola.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    dialogo.setRepeated(true);

    this->sprite_dialogo.setTexture(dialogo);
    this->sprite_dialogo.setScale(10,10);

    window.draw(sprite_dialogo);
}