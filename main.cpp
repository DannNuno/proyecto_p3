#include <SFML/Graphics.hpp>
#include <iostream>
#include "pollo.hpp"
#include "rana.hpp"
#include "npc.hpp"
#include "mapa.hpp"
#include "objeto.hpp"
using namespace sf;
using namespace std;
int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(60);
    Texture mapaTexture;

    Mapa mapa;
    Pollito pollo;
    Rana rana;
    NPC ajolote;
    Objeto manzana;
    rana.sprite_rana.setPosition(800,600);
    manzana.sprite_objeto.setPosition(300,400);
    ajolote.sprite_npc.setPosition(600,800);
    Clock reloj;
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if(event.type == Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Enter)){
                    rana.habla(pollo.sprite_pollo);
                }
            }
            
            if(event.type == Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Q))
                pollo.abrir_inv();
            }

            if(event.type == Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::K))
                pollo.cambiar_objactual();
            }

            
        }

        float deltaTime = reloj.restart().asSeconds();
        pollo.update(deltaTime, &rana, &manzana);
        rana.update(deltaTime, pollo.sprite_pollo, window);
        mapa.cambiarmapa(&pollo.sprite_pollo);
        
        window.clear(Color(51,51,51));

        window.draw(mapa.sprite_mapa);
        window.draw(rana.sprite_rana);
        window.draw(ajolote.sprite_npc);
        window.draw(pollo.sprite_pollo);

        rana.drawDialog(window);
        manzana.update(window);
        pollo.ver_inventario(window);

        window.display();
    }

    return 0;
}