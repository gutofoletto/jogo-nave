#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "nave.h"
#include "inimigo.h"

const int w = 800;
const int h = 600;

Nave *nave = NULL;
std::vector<Inimigo> inimigos;

float angulo = 0;
int k = 0;
int controleDisparo = 10;

int main(void) {
    initCanvas(w, h);

    nave = new Nave();

    Inimigo e = Inimigo(Vetor(100.0f, 100.0f));
    inimigos.push_back(e);

    Inimigo f = Inimigo(Vetor(700.0f, 500.0f));
    inimigos.push_back(f);

    Inimigo g = Inimigo(Vetor(100.0f, 500.0f));
    inimigos.push_back(g);

    Inimigo h = Inimigo(Vetor(700.0f, 100.0f));
    inimigos.push_back(h);

    runCanvas();
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{

    if(nave->estaMovendo() == true)
        nave->acelerarNave();

    if(nave->estaGirando() == true && k == 200)
        angulo = 0.1f;
    else if(nave->estaGirando() == true && k == 202)
        angulo = -0.1f;
    else angulo = 0;

    if(nave->estaMovendo() == false && nave->getAceleracao() > 0)
        nave->desacelerarNave();

    if(nave->getAceleracao() < 0)
        nave->pararNave();

    if(nave->estaDisparando() == true){
        if(controleDisparo >= 10){
            nave->dispararBala();
            controleDisparo = 0;
        }
        controleDisparo++;
    }


    if (nave->getPosicao().getX() > w)
        nave->setPosicao(Vetor(0, nave->getPosicao().getY()));

    if (nave->getPosicao().getX() < 0)
        nave->setPosicao(Vetor(w, nave->getPosicao().getY()));

    if (nave->getPosicao().getY() > h)
        nave->setPosicao(Vetor(nave->getPosicao().getX(), 0));

    if (nave->getPosicao().getY() < 0)
        nave->setPosicao(Vetor(nave->getPosicao().getX(), h));

    nave->transformarNave(angulo);
    nave->desenharNave();

    for(int i=0; i<inimigos.size(); i++){
        inimigos[i].desenharInimigo();
        if(inimigos[i].existeBala() == false){
            inimigos[i].localizarNave(nave->getPosicao());
            inimigos[i].dispararBala();
        } else {
            inimigos[i].animarBalas();
        }
    }
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
    switch(key) {
        case 27:
            //esc
            exit(0);
            break;
        case 32:
            //spacebar
            nave->setDisparando(true);
            break;
        case 200:
            //left
            nave->setGirando(true);
            k = 200;
            break;
        case 201:
            //up
            nave->setMovendo(true);
            k = 201;
            break;
        case 202:
            //right
            nave->setGirando(true);
            k = 202;
            break;
        case 203:
            //down
            nave->setMovendo(false);
            k = 203;
            break;
    }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key) {
    switch(key) {
        case 32:
            //spacebar
            nave->setDisparando(false);
            controleDisparo = 5;
            break;
        case 200:
            //left
            nave->setGirando(false);
            k = 0;
            break;
        case 201:
            //up
            nave->setMovendo(false);
            k = 0;
            break;
        case 202:
            //right
            nave->setGirando(false);
            k = 0;
            break;
        case 203:
            //down
            k = 0;
            break;
    }
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y) {
    //printf("\nmouse %d %d %d %d", button, state, x, y);
}
