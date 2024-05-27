#include <SFML/Graphics.hpp>
#include <iostream>
#include "pollo.hpp"
#include "rana.hpp"
#include "npc.hpp"
#include "mapa.hpp"
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
    rana.sprite_rana.setPosition(800,600);
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

            
        }

        float deltaTime = reloj.restart().asSeconds();
        pollo.update(deltaTime, &rana);
        rana.update(deltaTime, pollo.sprite_pollo, window);
        
        window.clear(Color(51,51,51));

        window.draw(mapa.mapa);
        window.draw(rana.sprite_rana);
        window.draw(ajolote.sprite_npc);
        window.draw(pollo.sprite_pollo);

        rana.drawDialog(window);

        window.display();
    }

    return 0;
}