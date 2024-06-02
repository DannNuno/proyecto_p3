#ifndef pollo_h
#define pollo_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include "rana.hpp"
#include "objeto.hpp"
using namespace sf;
using namespace std;

class Rana;
class Objeto;

class Pollito{
    private:
    Texture polloTexture;
    Texture polloTexture_2;
    Texture polloTexture_3;
    Texture polloTexture_4;
    Texture polloTexture_5;
    Texture polloTexture_6;
    Texture polloTexture_7;
    Texture polloTexture_8;
    Texture inventarioTexture;

    vector<Texture> idleFrames_der; //vector de texturas idle
    vector<Texture> idleFrames_izq;
    vector<Texture> moviendose_der;
    vector<Texture> moviendose_izq;

    size_t currentFrame = 0; // Frame en el que se encuentra
    float frameTime = 0.5f; // Tiempo por cuadro en segundos
    float currentTime = 0.f; // saber cuando cambiar de cuadro
    
    bool moviendose = false; // saber si el pollito esta idle o moviendose
    bool mirando_der = true; // saber si el pollito esta mirando a la izq o der
    bool inv_abierto = false;

    int objeto_actual = 0;

    public:
    Sprite sprite_pollo;
    Sprite sprite_inventario;
    float speed_x;
    float speed_y;
    vector<Objeto*> inventario;

    Pollito();
    void mover();
    void correr();
    void update(float deltaTime, Rana *rana, Objeto *objeto);
    // deltaTime se utiliza para que la animacion ocurra independientemente de los FPS, es el tiempo transcurrido desde el ultimo cuadro
    void idle_der();
    void idle_izq();
    void mover_der();
    void mover_izq();
    void pausar(Rana *rana);
    void tomar_objeto(Objeto *objeto);
    void abrir_inv();
    void ver_inventario(RenderWindow &window);
    void cambiar_objactual();

};

#endif