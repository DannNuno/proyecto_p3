#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "npc.hpp"
using namespace sf;
using namespace std;

NPC::NPC(){
   if(!npcTexture.loadFromFile("assets/ajolote_pilon.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    npcTexture.setRepeated(true);

    if(!npcTexture2.loadFromFile("assets/ajolote_pilon2.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    npcTexture2.setRepeated(true);

    if(!dialogo.loadFromFile("assets/hola.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    dialogo.setRepeated(true);

    this->sprite_dialogo.setTexture(dialogo);
    this->sprite_dialogo.setScale(10,10);

    this->sprite_npc.setTexture(npcTexture);
    this->sprite_npc.setScale(6,6);

    this->idleFrames.push_back(npcTexture);
    this->idleFrames.push_back(npcTexture2);
}

void NPC::update(float deltaTime, Sprite sprite, RenderWindow &window){
    currentTime += deltaTime;
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        sprite_npc.setTexture(idleFrames[currentFrame]); 
    }
    if(calcular_dist(sprite.getPosition(), this->sprite_npc.getPosition()) <= 150){
        if(Keyboard::isKeyPressed(Keyboard::E)){
        cout << "dialogo ajolote" << endl;
        hablar();
        }
    } else {
        hablando = false;
    }
}

float NPC::calcular_dist(Vector2f s1, Vector2f s2){
    float dist_x = s1.x - s2.x;
    float dist_y = s1.y - s2.y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

void NPC::hablar(){
    hablando = true;
}

void NPC::drawDialog(RenderWindow &window) {
    if (hablando){
        window.draw(sprite_dialogo);
    }
}