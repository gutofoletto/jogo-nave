#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "Nave.h"

Nave *nave = NULL;

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{

    if(nave->estaMovendo() == true){
        nave->transformarNave();
    }

    if(nave->estaMovendo() == false && nave->getAceleracao() > 0){
        nave->acelerarNave(-0.075f);
        nave->transformarNave();
    }

    nave->desenharNave();
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
    switch(key) {
        case 27:
            exit(0);
            break;
        case 200:
            nave->transformarNave(0.1f);
            break;
        case 201:
            nave->setMovendo(true);
            nave->acelerarNave(0.3f);
            break;
        case 202:
            nave->transformarNave(-0.1f);
            break;
        case 203:
            nave->setMovendo(false);
            break;
    }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key) {
    switch(key) {
        case 200:
            //left
            break;
        case 201:
            //up
            break;
        case 202:
            //right
            break;
        case 203:
            //down
            break;
    }
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y) {
    //printf("\nmouse %d %d %d %d", button, state, x, y);
}

int main(void) {
    initCanvas(800,600);

    nave = new Nave();
    nave->transformarNave();

    runCanvas();
}
