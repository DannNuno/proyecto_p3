#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(60);
    Texture polloTexture;

    if(!polloTexture.loadFromFile("assets/pollito.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    polloTexture.setRepeated(true);

    Sprite pollo;
    pollo.setTexture(polloTexture);
    pollo.setScale(10,10);
    int opacidad = 0;
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(51,51,51));
        window.draw(pollo);
        pollo.setColor(Color(255,255,255, opacidad % 256));
        window.display();
        opacidad++;
    }

    return 0;
}