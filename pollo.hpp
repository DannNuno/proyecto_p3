#ifndef pollo_h
#define pollo_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Pollito{
    private:
    Texture polloTexture;
    Texture polloTexture_2;
    Texture polloTexture_3;
    Texture polloTexture_4;
    vector<Texture> idleFrames_der; //vector de texturas idle
    vector<Texture> idleFrames_izq;
    size_t currentFrame = 0; // Frame en el que se encuentra
    float frameTime = 0.5f; // Tiempo por cuadro en segundos
    float currentTime = 0.f; // saber cuando cambiar de cuadro
    bool moviendose = false; // saber si el pollito esta idle o moviendose
    bool mirando_der = true; // saber si el pollito esta mirando a la izq o der

    public:
    Sprite sprite_pollo;
    float speed_x;
    float speed_y;
    

    Pollito();
    void mover();
    void correr();
    void update(float deltaTime);
    void idle_der(float deltaTime);
    void idle_izq(float deltaTime);
    // deltaTime se utiliza para que la animacion ocurra independientemente de los FPS, es el tiempo transcurrido desde el ultimo cuadro

};

#endif