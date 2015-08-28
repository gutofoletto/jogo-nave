#ifndef __NAVE_H__
#define __NAVE_H__

#include <iostream>
#include <vector>
#include "gl_canvas2d.h"
#include "vetor.h"
#include "projetil.h"

class Nave {
    Vetor geometria[5] = {
        Vetor(-16.0f, -16.0f),
        Vetor(0.0f, 16.0f),
        Vetor(16.0f, -16.0f),
        Vetor(0.0f, 0.0f),
        Vetor(-16.0f, -16.0f)
    };
    Vetor posicao;
    Vetor direcao;
    std::vector<Projetil> balas;
    float angulo;
    float escala;
    float aceleracao;
    bool movendo;
    bool girando;
    bool disparando;


public:
    Vetor base[5] = {
        geometria[0],
        geometria[1],
        geometria[2],
        geometria[3],
        geometria[4]
    };

    Nave(){
        posicao = Vetor(400.0f, 300.0f);
        direcao = Vetor(0.0f, 1.0f);
        angulo = 0.0f;
        escala = 1.0f;
        aceleracao = 0.0f;
        movendo = false;
        girando = false;
        disparando = false;
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

    bool estaGirando(){
        return this->girando;
    }

    void setDisparando(bool d){
        this->disparando = d;
    }

    bool estaDisparando(){
        return this->disparando;
    }

    float getAceleracao(){
        return this->aceleracao;
    }

    void acelerarNave(){
        if(this->aceleracao < 5.0f) this->aceleracao += 0.1f;
    }

    void desacelerarNave(){
        if(this->aceleracao > 0.0f){
            this->aceleracao -= 0.2f;
        }
    }

    void pararNave(){
        this->aceleracao = 0.0f;
    }

    void desenharNave(){
        for(int i=0; i<4; i++){
            color(0,0,0);
            line(
                base[i].getX(), base[i].getY(),
                base[i+1].getX(), base[i+1].getY()
            );
        }

        if(existeBala() == true){
            for(int b=0; b<balas.size(); b++){
                balas[b].desenharProjetil();
            }
        }
    }

    void transformarNave(float ang = 0.0f){
        if(ang != 0.0f) this->angulo += (ang);
        direcao.setX(cos(this->angulo+M_PI/2));
        direcao.setY(sin(this->angulo+M_PI/2));

        posicao.setX(posicao.getX()+direcao.getX()*aceleracao);
        posicao.setY(posicao.getY()+direcao.getY()*aceleracao);

        for(int i=0; i<5; i++){

            Vetor v = geometria[i].girarVetor(this->angulo);
            v = v.moverVetor(posicao);

            base[i].setX(v.getX());
            base[i].setY(v.getY());
        }

        if(Nave::existeBala() == true){
            for(int b = 0; b < balas.size(); b++){

                Vetor pos = balas[b].getPosicao();

                if( pos.getX() <= 0.0f || pos.getX() >= 800.0f
                || pos.getY() <= 0.0f || pos.getY() >= 600.0f ){
                    balas.erase(balas.begin()+b);
                }

                balas[b].transformarProjetil();
            }
        }
    }

    bool existeBala(){
        if(balas.size() > 0)
            return true;
        else return false;
    }

    void dispararBala(){
        Projetil p = Projetil(
            posicao,
            direcao
        );

        balas.push_back(p);
    }
};

#endif
