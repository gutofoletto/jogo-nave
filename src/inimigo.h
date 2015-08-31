#include <vector>
#include "gl_canvas2d.h"
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
            direcao = Vetor(0, 1);
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

        Vetor localizarNave(Vetor p){
            p = p.normalizar();
            Vetor q = posicao.normalizar();

            float dp = q.produtoEscalar(p);
            float angPI = acos(dp);

            return Vetor(0,1);
        }

        void dispararBala(Vetor direcao){
            Projetil p = Projetil(
                this->posicao,
                direcao
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
