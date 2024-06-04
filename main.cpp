#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

    SoundBuffer musica;
    if (!musica.loadFromFile("assets/music.wav")) {
        cout << "error al cargar musica" << endl;
    }

    Sound sound;
    sound.setBuffer(musica);
    sound.play();
    sound.setLoop(true);

    bool menu_abierto = true;

    Texture menuTexture;
    if(!menuTexture.loadFromFile("assets/inicio.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    Sprite menu;
    menu.setTexture(menuTexture);
    menu.setScale(10,10);

    Texture finTexture;
    if(!finTexture.loadFromFile("assets/fin.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    Sprite findeljuego;
    findeljuego.setTexture(finTexture);
    findeljuego.setScale(10,10);

    Mapa mapa;
    Pollito pollo;
    Rana rana;
    NPC ajolote;
    NPC hongo(2);
    NPC oso(1);
    Objeto manzana;
    Objeto objeto_oso(1);
    Objeto manzana_azul(2);
    Objeto manzana_amarilla(3);

    rana.sprite_rana.setPosition(800,600);
    manzana.sprite_objeto.setPosition(300,400);
    objeto_oso.sprite_objeto.setPosition(400,200);
    manzana_azul.sprite_objeto.setPosition(500,900);
    manzana_amarilla.sprite_objeto.setPosition(900,20);
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
                        rana.habla(pollo.sprite_pollo, pollo, &manzana);
                        ajolote.habla(pollo.sprite_pollo, pollo, &manzana_amarilla);
                        hongo.habla(pollo.sprite_pollo, pollo, &manzana_azul);
                    }

                    if(mapa.nivel == 2){
                        oso.habla(pollo.sprite_pollo, pollo, &objeto_oso);
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

            if(event.type == Event::KeyPressed){
                if(Keyboard::isKeyPressed(Keyboard::Enter)){
                    if(menu_abierto){
                        menu_abierto = false;
                    }
                }
            }

            
        }

        float deltaTime = reloj.restart().asSeconds();
        pollo.update(deltaTime, &rana, &manzana, &objeto_oso, &manzana_azul, &manzana_amarilla, menu_abierto, &ajolote, &oso, &hongo);
        rana.update(deltaTime);
        ajolote.update(deltaTime);
        oso.update(deltaTime);
        hongo.update(deltaTime);
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
            objeto_oso.update(window);
        }

        if(mapa.nivel == 3){
            manzana_azul.update(window);
        }

        if(mapa.nivel == 4){
            manzana_amarilla.update(window);
        }

        window.draw(pollo.sprite_pollo);

        rana.drawDialog(window);
        ajolote.drawDialog(window);
        hongo.drawDialog(window);
        oso.drawDialog(window);
        pollo.ver_inventario(window);

        if(menu_abierto){
            window.draw(menu);
        }

        if(pollo.misiones_completas == 4 && rana.dialogo_2_listo && ajolote.dialogo_2_listo && oso.dialogo_2_listo && hongo.dialogo_2_listo){
            window.draw(findeljuego);
        }
        
        window.display();
    }

    return 0;
}