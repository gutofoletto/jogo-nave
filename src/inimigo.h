#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include "vetor.h"

class Inimigo {
    float raio;
    float angulo;
    Vetor direcao;
    Vetor posicao;
    std::vector<Projetil> balas;

    public:
        Inimigo(Vetor pos){
            raio = 10.0f;
            angulo = 0.0f;
            direcao = Vetor(1, 0);
            posicao = pos;
        }

        void desenharInimigo(){
            color(5, 0, 0);
            circle(this->posicao.getX(), this->posicao.getY(), this->raio, this->raio*1.5);
            circleFill(this->posicao.getX(), this->posicao.getY(), this->raio, this->raio*1.5);

            if(existeBala() == true){
                for(int b=0; b<balas.size(); b++){
                    balas[b].desenharProjetil();
                }
            }
        }

        bool existeBala(){
            if(balas.size() > 0)
                return true;
            else return false;
        }

        void localizarNave(Vetor p){
            Vetor alvo = p.subtrairVetor(posicao).normalizar();
            float dp = direcao.produtoEscalar(alvo);

            if(dp >= 1.0f) dp = 1.0f;
            else if (dp <= -1.0) dp = -1.0f;

            float angPI = (float)acos(dp);

            if(direcao.getY()*alvo.getX() > direcao.getX()*alvo.getY()){
                this->angulo = -angPI;
            } else this->angulo = angPI;
        }

        void dispararBala(){
            Vetor alvo = Vetor(cos(angulo), sin(angulo));

            Projetil p = Projetil(
                this->posicao,
                alvo
            );

            balas.push_back(p);
        }

        void animarBalas(){
            if(existeBala() == true){
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
};
