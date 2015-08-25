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
    float vel_max;

public:
    Vetor base[5] = {
            geometria[0],
            geometria[1],
            geometria[2],
            geometria[3],
            geometria[4]
    };

    Nave(){
        posicao = Vetor(100.0f, 100.0f);
        direcao = Vetor(0.0f, 1.0f);
        angulo = 0.0f;
        escala = 1.0f;
        aceleracao = 0.0f;
        vel_max = 10.0;
    }

    void desenharNave(){
        for(int i=0; i<4; i++){
            color(0,0,0);
            line(
                base[i].getX(), base[i].getY(),
                base[i+1].getX(), base[i+1].getY()
            );
        }
        color(1,0,0);
        line(posicao.getX(),posicao.getY(), posicao.getX()+direcao.getX()*100, posicao.getY()+direcao.getY()*100);
    }

    void acelerarNave(float v){
        aceleracao += v;
    }

    // void moverNave(Vetor p){
    //     posicao.setX(posicao.getX()+p.getX());
    //     posicao.setY(posicao.getY()+p.getY());
    //
    //     for(int i=0; i<5; i++){
    //         float newX = geometria[i].getX() + posicao.getX();
    //         float newY = geometria[i].getY() + posicao.getY();
    //         base[i].setX(newX);
    //         base[i].setY(newY);
    //     }
    // }
    //
    // void girarNave(float ang){
    //     angulo += ang;
    //     float s = sin(angulo);
    //     float c = cos(angulo);
    //
    //     for(int i=0; i<5; i++){
    //         float newX = (geometria[i].getX() * c) - (geometria[i].getY() * s)+ posicao.getX();
    //         float newY = (geometria[i].getX() * s) + (geometria[i].getY() * c)+ posicao.getY();
    //         base[i].setX(newX);
    //         base[i].setY(newY);
    //     }
    // }

    void transformarNave(float ang = 0){
        angulo = angulo + ang;
        float s = sin(angulo);
        float c = cos(angulo);
        direcao.setX(cos(angulo+M_PI/2));
        direcao.setY(sin(angulo+M_PI/2));

        posicao.setX(posicao.getX()+direcao.getX());
        posicao.setY(posicao.getY()+direcao.getY());

        printf("\nX: %f, Y: %f" , direcao.getX(),direcao.getY() );

        for(int i=0; i<5; i++){
            float newX =
                (geometria[i].getX() * c) - (geometria[i].getY() * s)
                + (posicao.getX())
            ;
            float newY =
                (geometria[i].getX() * s) + (geometria[i].getY() * c)
                + (posicao.getY())
            ;

            base[i].setX(newX);
            base[i].setY(newY);
        }
    }
};

#endif
