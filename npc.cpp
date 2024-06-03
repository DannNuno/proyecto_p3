#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "npc.hpp"
#include "pollo.hpp"
using namespace sf;
using namespace std;

NPC::NPC(){
   if(!this->npcTexture.loadFromFile("assets/ajolote_pilon.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    if(!this->npcTexture2.loadFromFile("assets/ajolote_pilon2.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    if(!this->dialogo.loadFromFile("assets/hola.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    if(!this->dialogo_2.loadFromFile("assets/soy_rana.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }

    dialogos_index = 0;
    this->sprite_dialogo.setTexture(dialogo);
    this->sprite_dialogo.setScale(10,10);

    this->sprite_npc.setTexture(npcTexture);
    this->sprite_npc.setScale(6,6);

    this->idleFrames.push_back(npcTexture);
    this->idleFrames.push_back(npcTexture2);

    this->dialogos.push_back(dialogo);
    this->dialogos.push_back(dialogo_2);
}

NPC::NPC(int typenpc){

    if(typenpc == 1){
        if(!this->npcTexture.loadFromFile("assets/oso.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->npcTexture2.loadFromFile("assets/oso2.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->npcTexture3.loadFromFile("assets/oso3.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->npcTexture4.loadFromFile("assets/oso4.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->dialogo.loadFromFile("assets/hola.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->dialogo_2.loadFromFile("assets/soy_rana.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        dialogos_index = 0;
        this->sprite_dialogo.setTexture(dialogo);
        this->sprite_dialogo.setScale(10,10);

        this->sprite_npc.setTexture(npcTexture);
        this->sprite_npc.setScale(6,6);

        this->idleFrames.push_back(npcTexture);
        this->idleFrames.push_back(npcTexture2);
        this->idleFrames2.push_back(npcTexture3);
        this->idleFrames2.push_back(npcTexture4);

        this->dialogos.push_back(dialogo);
        this->dialogos.push_back(dialogo_2);
    }

    if(typenpc == 2){
        if(!this->npcTexture.loadFromFile("assets/hongo_mario.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->npcTexture2.loadFromFile("assets/hongo_mario.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->dialogo.loadFromFile("assets/hola.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        if(!this->dialogo_2.loadFromFile("assets/soy_rana.png"))
        {
            cout << "Error al cargar imagen" << endl;
        }

        dialogos_index = 0;
        this->sprite_dialogo.setTexture(dialogo);
        this->sprite_dialogo.setScale(10,10);

        this->sprite_npc.setTexture(npcTexture);
        this->sprite_npc.setScale(6,6);

        this->idleFrames.push_back(npcTexture);
        this->idleFrames.push_back(npcTexture2);

        this->dialogos.push_back(dialogo);
        this->dialogos.push_back(dialogo_2);
    }

}

void NPC::update(float deltaTime, Pollito &pollito, Objeto *objetoMision){
    currentTime += deltaTime;
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % idleFrames.size();
        sprite_npc.setTexture(idleFrames[currentFrame]); 
    }
    this->mision(pollito, objetoMision);
}

float NPC::calcular_dist(Vector2f s1, Vector2f s2){
    float dist_x = s1.x - s2.x;
    float dist_y = s1.y - s2.y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

void NPC::habla(Sprite sprite){
if(calcular_dist(sprite.getPosition(), this->sprite_npc.getPosition()) <= 150){
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

void NPC::hablar(int dialogo_actual){
    this->sprite_dialogo.setTexture(dialogos[dialogo_actual]);
    this->hablando = true;
}

void NPC::drawDialog(RenderWindow &window) {
    if (this->hablando){
        window.draw(this->sprite_dialogo);
    }
}

void NPC::mision(Pollito &pollito, Objeto *objetoMision){

    if(this->hablando){
    if(pollito.inventario.empty() == false){
        
        // Encontrar el objeto en el inventario
        auto it = find(pollito.inventario.begin(), pollito.inventario.end(), objetoMision);

        // Verificar si se encontró el objeto
        if (it != pollito.inventario.end()) {
            // Eliminar el objeto del inventario
            pollito.inventario.erase(it);

            cout << "Objeto mision tomado" << endl;
        } else {
            cout << "Objeto mision no encontrado" << endl;
        }
        
    }
    }


    /*
    si el pollito tiene la manzana, la rana
    la toma y la mision se cumple
    */
}