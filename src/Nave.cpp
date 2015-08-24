#include "Nave.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Nave::Nave()
{
   x = 0, y = 0;
   escala = 1;
   aceleracao = 0;
   vel_max = 0;
   Nave::setVertices();
}

void Nave::setVertices(){
    vertX[0] = -25; vertY[0] = -25;
    vertX[1] = 0; vertY[1] = 25;
    vertX[2] = 25; vertY[2] = -25;
    vertX[3] = 0; vertY[3] = 0;
}

void Nave::desenhaNave(){

    color(0, 0, 0);
    polygonFill(vertX, vertY, 4);
}

void Nave::aceleraNave(){
    aceleracao += 1;
    Nave::moveNave(0, x+aceleracao);
}

void Nave::moveNave(float mx, float my){
    x += mx;
    y += my;

    for (int i=0;i<4;i++){
        vertX[i] += x;
        vertY[i] += y;
    }
}

void Nave::rodaNave(float ang){
    for (int i=0;i<4;i++){
        vertX[i] += vertX[i]*(cos(ang)) - vertY[i]*(sin(ang));
        vertY[i] += vertX[i]*(sin(ang)) + vertY[i]*(cos(ang));
    }
}
