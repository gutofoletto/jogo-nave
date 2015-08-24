/*********************************************************************
// Canvas para desenho - Versao CPP.
//  Autor: Cesar Tadeu Pozzer
//         10/2007
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Instru��es:
//    Para compilar em C, basta comentar o comando #define _CPP_
//	  Para alterar a animacao, digite numeros entre 1 e 7
/*********************************************************************/

/*
Autor: Cesar Tadeu Pozzer
04/2013

Instru��es:
Para alterar a animacao, digite numeros entre 1 e 7
*/

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
    nave->desenhaNave();
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
            nave->rodaNave(-5);
            break;
        case 201:
            nave->aceleraNave();
            break;
        case 202:
            nave->rodaNave(5);
            break;
        case 203:
            nave->aceleraNave();
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
