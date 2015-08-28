#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "Nave.h"

Nave *nave = NULL;
float angulo = 0;
int k = 0;
int controleDisparo = 10;

int main(void) {
    initCanvas(800,600);

    nave = new Nave();

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
        if(controleDisparo >= 5){
            nave->dispararBala();
            controleDisparo = 0;
        }
        controleDisparo++;
    }


    // if (nave->getPosicao() > this.game.width) this.ship.x = 0;
    // if (this.ship.x < 0) this.ship.x = this.game.width;
    // if (this.ship.y > this.game.height) this.ship.y = 0;
    // if (this.ship.y < 0) this.ship.y = this.game.height;

    nave->transformarNave(angulo);
    nave->desenharNave();
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
