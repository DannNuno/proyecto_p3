#include <SFML/Graphics.hpp>
#include <iostream>
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

void Rana::update(float deltaTime){
    currentTime += deltaTime;
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        sprite_rana.setTexture(idleFrames[currentFrame]); 
    }
}