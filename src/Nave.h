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
    bool movendo;
    bool girando;

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
        movendo = false;
        girando = false;
    }

    void setMovendo(bool m){
        this->movendo = m;
    }

    bool estaMovendo(){
        return this->movendo;
    }

    void setGirando(bool g){
        this->girando = g;
    }

    bool getGirando(){
        return this->girando;
    }

    float getAceleracao(){
        return this->aceleracao;
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
        line(posicao.getX(),posicao.getY(), posicao.getX()+direcao.getX()*50, posicao.getY()+direcao.getY()*50);
    }

    void acelerarNave(float v){
        if(v != 0.0f && this->aceleracao < 10.0f) this->aceleracao += (v);
        else if(v < 0 && this->aceleracao <= 0) this->aceleracao = 0.0f;
        else this->aceleracao = 0.0f;
    }

    void transformarNave(float ang = 0.0f){
        if(ang != 0.0f) this->angulo += (ang);
        float s = sin(this->angulo);
        float c = cos(this->angulo);
        direcao.setX(cos(this->angulo+M_PI/2));
        direcao.setY(sin(this->angulo+M_PI/2));

        posicao.setX(posicao.getX()+direcao.getX()*aceleracao);
        posicao.setY(posicao.getY()+direcao.getY()*aceleracao);

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
