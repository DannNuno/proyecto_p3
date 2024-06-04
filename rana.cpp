#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "rana.hpp"
#include "pollo.hpp"
using namespace sf;
using namespace std;

Rana::Rana(){
   if(!this->ranaTexture.loadFromFile("assets/rana.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    if(!this->ranaTexture_2.loadFromFile("assets/rana2.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    if(!this->dialogo.loadFromFile("assets/ranahola.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    if(!this->dialogo_2.loadFromFile("assets/ranamision.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

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

void Rana::update(float deltaTime, Pollito &pollito, Objeto *objetoMision){
    currentTime += deltaTime;
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        sprite_rana.setTexture(idleFrames[currentFrame]); 
    }
    this->mision(pollito, objetoMision);
}

float Rana::calcular_dist(Vector2f s1, Vector2f s2){
    float dist_x = s1.x - s2.x;
    float dist_y = s1.y - s2.y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

void Rana::habla(Sprite sprite){
if(calcular_dist(sprite.getPosition(), this->sprite_rana.getPosition()) <= 150){
    this->hablando = true;
            if(this->dialogos_index < this->dialogos.size()){
                cout << "dialogo num." << this->dialogos_index << endl;
                hablar(this->dialogos_index);
                this->dialogos_index = (this->dialogos_index + 1);
            } else {
                this->hablando = false;
                this->dialogos_index = 0;
            }
        
    } else {
        this->hablando = false;
    }
}

void Rana::hablar(int dialogo_actual){
    this->sprite_dialogo.setTexture(dialogos[dialogo_actual]);
    this->hablando = true;
}

void Rana::drawDialog(RenderWindow &window) {
    if (this->hablando){
        window.draw(this->sprite_dialogo);
    }
}

void Rana::mision(Pollito &pollito, Objeto *objetoMision){

    if(this->hablando){
    if(pollito.inventario.empty() == false){
        
        // Encontrar el objeto en el inventario
        auto it = find(pollito.inventario.begin(), pollito.inventario.end(), objetoMision);

        // Verificar si se encontró el objeto
        if (it != pollito.inventario.end()) {
            // Eliminar el objeto del inventario
            pollito.inventario.erase(it);
            pollito.misiones_completas++;

            cout << "Objeto mision rana tomado" << endl;
        } else {
            cout << "Objeto mision rana no encontrado" << endl;
        }
        
    }
    }


    /*
    si el pollito tiene la manzana, la rana
    la toma y la mision se cumple
    */
}