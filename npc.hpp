#ifndef npc_h
#define npc_h

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Pollito;
class Objeto;
class NPC{
    private:
    Texture npcTexture;
    Texture npcTexture2;
    Texture npcTexture3;
    Texture npcTexture4;
    Texture dialogo;
    Texture dialogo_2;
    Texture dialogo_3;
    int dialogos_index;

    vector<Texture> idleFrames;
    vector<Texture> idleFrames2;
    vector<Texture> dialogos;
    vector<Texture> dialogos2;
    size_t currentFrame = 0;
    float frameTime = 0.5f;
    float currentTime = 0.f;

    bool primer_dialogo = false;
    bool dialogo_terminado = false;


    public:
    Sprite sprite_npc;
    Sprite sprite_dialogo;
    NPC();
    NPC(int typenpc);
    void update(float deltaTime);
    float calcular_dist(Vector2f s1, Vector2f s2);
    void habla(Sprite sprite, Pollito &pollito, Objeto *objetoMision);
    void hablar(int dialogo_actual);
    void hablar2(int dialogo_actual);
    void drawDialog(RenderWindow &window);
    void mision(Pollito &pollo, Objeto *objetoMision);
    bool hablando = false;
    bool mision_completada = false;
    bool dialogo_2_listo = false;

};

#endif