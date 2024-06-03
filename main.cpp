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
    RenderWindow window(VideoMode(1920, 1080), "La aventura mas kawaii");
    window.setFramerateLimit(60);

    Mapa mapa;
    Pollito pollo;
    Rana rana;
    NPC ajolote;
    NPC hongo(2);
    NPC oso(1);
    Objeto manzana;
    Objeto placeholder(1);

    vector<Objeto> objetos;

    objetos.push_back(manzana);
    objetos.push_back(placeholder);

    rana.sprite_rana.setPosition(800,600);
    manzana.sprite_objeto.setPosition(300,400);
    placeholder.sprite_objeto.setPosition(400,200);
    ajolote.sprite_npc.setPosition(600,800);
    hongo.sprite_npc.setPosition(500,300);
    oso.sprite_npc.setPosition(800,600);
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
                    if(mapa.nivel == 1){
                        rana.habla(pollo.sprite_pollo);
                        ajolote.habla(pollo.sprite_pollo);
                        hongo.habla(pollo.sprite_pollo);
                    }

                    if(mapa.nivel == 2){
                        oso.habla(pollo.sprite_pollo);
                    }
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
        pollo.update(deltaTime, &rana, &manzana, &placeholder);
        rana.update(deltaTime, pollo, &manzana);
        ajolote.update(deltaTime, pollo, &manzana);
        oso.update(deltaTime, pollo, &placeholder);
        hongo.update(deltaTime, pollo, &manzana);
        mapa.cambiarmapa(&pollo.sprite_pollo);
        
        window.clear();

        window.draw(mapa.sprite_mapa);
        if(mapa.nivel == 1){
            window.draw(rana.sprite_rana);
            window.draw(ajolote.sprite_npc);
            window.draw(hongo.sprite_npc);
            manzana.update(window);
        }
        if(mapa.nivel == 2){
            window.draw(oso.sprite_npc);
            placeholder.update(window);
        }
        window.draw(pollo.sprite_pollo);

        rana.drawDialog(window);
        ajolote.drawDialog(window);
        hongo.drawDialog(window);
        oso.drawDialog(window);
        pollo.ver_inventario(window);

        window.display();
    }

    return 0;
}