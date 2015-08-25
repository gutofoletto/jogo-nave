#ifndef __NAVE_H__
#define __NAVE_H__

#include "gl_canvas2d.h"
#include "vetor.h"
#include <iostream>

class Nave {
    Vetor geometria[5] = {
        Vetor(-25.0f, -25.0f),
        Vetor(0.0f, 25.0f),
        Vetor(25.0f, -25.0f),
        Vetor(0.0f, 0.0f),
        Vetor(-25.0f, -25.0f)
    };
    Vetor posicao;
    Vetor direcao;
    float angulo;
    float escala;
    float aceleracao;
    int vel_max;

public:
    Vetor base[5] = {
            geometria[0],
            geometria[1],
            geometria[2],
            geometria[3],
            geometria[4]
    };

    Nave(){
        posicao = Vetor(0.0f, 0.0f);
        direcao = Vetor(0.0f, 1.0f);
        angulo = 0.0f;
        escala = 1.0f;
        aceleracao = 0.0f;
        vel_max = 10;
    }

    void desenharNave(){
        for(int i=0; i<4; i++){
            color(0,0,0);
            line(
                base[i].getX(), base[i].getY(),
                base[i+1].getX(), base[i+1].getY()
            );
        }
    }


    void moverNave(Vetor p){
        posicao.setX(posicao.getX()+p.getX());
        posicao.setY(posicao.getY()+p.getY());

        for(int i=0; i<5; i++){
            float newX = geometria[i].getX() + posicao.getX();
            float newY = geometria[i].getY() + posicao.getY();
            base[i].setX(newX);
            base[i].setY(newY);
        }
    }

    void girarNave(float ang){
        angulo += ang;
        float seno = sin(angulo);
        float coss = cos(angulo);

        for(int i=0; i<5; i++){
            float newX = (geometria[i].getX() * coss) - (geometria[i].getY() * seno)+ posicao.getX();
            float newY = (geometria[i].getX() * seno) + (geometria[i].getY() * coss)+ posicao.getY();
            base[i].setX(newX);
            base[i].setY(newY);
        }
    }

    void transformaNave(float ang = 0, Vetor p = Vetor(0,0)){
        angulo = angulo + ang;
        float seno = sin(angulo);
        float coss = cos(angulo);
        posicao.setX(posicao.getX()+p.getX());
        posicao.setY(posicao.getY()+p.getY());

        for(int i=0; i<5; i++){
            float newX = (geometria[i].getX() * coss) - (geometria[i].getY() * seno)+ posicao.getX();
            float newY = (geometria[i].getX() * seno) + (geometria[i].getY() * coss)+ posicao.getY();
            base[i].setX(newX);
            base[i].setY(newY);
        }
    }
};

#endif
