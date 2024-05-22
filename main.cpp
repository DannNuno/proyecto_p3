#include <SFML/Graphics.hpp>
#include <iostream>
#include "pollo.hpp"
#include "rana.hpp"
using namespace sf;
using namespace std;
int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(60);
    Texture mapaTexture;

    Pollito pollo;
    Rana rana;
    rana.sprite_rana.setPosition(800,600);
    Clock reloj;

    if(!mapaTexture.loadFromFile("assets/mapa.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    mapaTexture.setRepeated(true);

    Sprite mapa;

    mapa.setTexture(mapaTexture);
    mapa.setScale(10,10);
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            
        }

        float deltaTime = reloj.restart().asSeconds();
        pollo.update(deltaTime);
        rana.update(deltaTime);
        
        window.clear(Color(51,51,51));

        window.draw(mapa);
        window.draw(rana.sprite_rana);
        window.draw(pollo.sprite_pollo);
        window.display();
    }

    return 0;
}