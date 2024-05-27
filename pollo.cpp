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

    if(!this->polloTexture_3.loadFromFile("assets/pollito2.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture_3.setRepeated(true);

    if(!this->polloTexture_4.loadFromFile("assets/pollito2_otrolado.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture_4.setRepeated(true);

    if(!this->polloTexture_5.loadFromFile("assets/pollito3.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture_5.setRepeated(true);

    if(!this->polloTexture_6.loadFromFile("assets/pollito3_otrolado.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture_6.setRepeated(true);

    if(!this->polloTexture_7.loadFromFile("assets/pollito4.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture_7.setRepeated(true);

    if(!this->polloTexture_8.loadFromFile("assets/pollito4_otrolado.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    this->polloTexture_8.setRepeated(true);

    this->sprite_pollo.setTexture(this->polloTexture);
    this->sprite_pollo.setScale(6,6);

    idleFrames_der.push_back(polloTexture);
    idleFrames_der.push_back(polloTexture_3);

    idleFrames_izq.push_back(polloTexture_2);
    idleFrames_izq.push_back(polloTexture_4);

    
    moviendose_der.push_back(polloTexture_5);
    moviendose_der.push_back(polloTexture_7);

    moviendose_izq.push_back(polloTexture_6);
    moviendose_izq.push_back(polloTexture_8);
}

void Pollito::mover(){

this->sprite_pollo.move(this->speed_x,this->speed_y);

}

void Pollito::correr(){
    this->speed_x = speed_x*3;
    this->speed_y = speed_y*3;
}

void Pollito::update(float deltaTime, Rana *rana){
    currentTime += deltaTime;
    //acumular tiempo desde el ultimo cuadro
    this->moviendose = false;

    if(Keyboard::isKeyPressed(Keyboard::D)){
        
        this->speed_x = 1;
        this->speed_y = 0;
        //this->mover();
        this->moviendose = true;
        this->mirando_der = true;
    }

    if(Keyboard::isKeyPressed(Keyboard::A)){
        this->speed_x = -1;
        this->speed_y = 0;
        //this->mover();
        this->moviendose = true;
        this->mirando_der = false;
    }

    if(Keyboard::isKeyPressed(Keyboard::W)){
        this->speed_x = 0;
        this->speed_y = -1;
        //this->mover();
        this->moviendose = true;
    }

    if(Keyboard::isKeyPressed(Keyboard::S)){
        this->speed_x = 0;
        this->speed_y = 1;
        //this->mover();
        this->moviendose = true;
    }

    if(Keyboard::isKeyPressed(Keyboard::Space)){
        this->correr();
    }

    this->pausar(rana);

    if (this->moviendose){
        this->mover();
        if(this->mirando_der){
            this->mover_der();
            cout << "derecha" << endl;
        }
        else{
            this->mover_izq();
            cout << "izquierda" << endl;
        }
    }
    else{
        if(this->mirando_der){
        this->idle_der();
        }
        else{
            this->idle_izq();
        }
    }
    //realiza la animacion idle si no se esta moviendo

}

void Pollito::idle_der(){
    if (currentTime >= frameTime) { //si current time supera el tiempo asignado a cada cuadro de la animacion
        currentTime = 0.f; //reinicio
        currentFrame = (currentFrame + 1) % idleFrames_der.size(); //cambiar de frame
        sprite_pollo.setTexture(idleFrames_der[currentFrame]); 
    }
}

void Pollito::idle_izq(){
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % idleFrames_izq.size();
        sprite_pollo.setTexture(idleFrames_izq[currentFrame]); 
    }
}

void Pollito::mover_der(){
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % moviendose_der.size();
        sprite_pollo.setTexture(moviendose_der[currentFrame]); 
    }
}

void Pollito::mover_izq(){
    if (currentTime >= frameTime) {
        currentTime = 0.f;
        currentFrame = (currentFrame + 1) % moviendose_izq.size();
        sprite_pollo.setTexture(moviendose_izq[currentFrame]);
    }
}

void Pollito::pausar(Rana *rana){
    if(rana->hablando){
        this->speed_x = 0;
        this->speed_y = 0;
        this->moviendose = false;
    }
    //se queda quieto si esta hablando con un npc
}