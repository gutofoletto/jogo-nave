#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"
#include "Nave.h"

Nave *nave = NULL;

//variaveis globais
int   opcao  = 50;
float global = 0;


//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
    nave->desenharNave();
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
    printf("\nTecla: %d" , key);
    if( key < 200 )
    {
        opcao = key;
    }

    switch(key)
    {
        case 27:
            exit(0);
            break;
        case 200:
            nave->transformaNave(-0.1f, NULL);
            break;
        case 201:
            nave->transformaNave(NULL,Vetor(0.0f, 1.0f));
            break;
        case 202:
            nave->transformaNave(0.1f, NULL);
            break;
        case 203:
            nave->transformaNave(NULL,Vetor(0.0f, -1.0f));
            break;
    }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
    //printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int x, int y)
{
    //printf("\nmouse %d %d %d %d", button, state, x, y);
}

int main(void)
{
    initCanvas(600,600);

    nave = new Nave();

    runCanvas();
}
