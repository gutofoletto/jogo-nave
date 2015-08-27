class Projetil{
    float tamanho;
    float velocidade;
    Vetor posicao;
    Vetor direcao;

    public:
        Projetil(float x = 0.0f, float y = 0.0f, Vetor dir = Vetor(0.0f, 1.0f)){
            this-> tamanho = 10.0f;
            this->velocidade = 5.0f;
            this->posicao = Vetor(x, y);
            this->direcao = dir;
        }

        Vetor getPosicao(){
            return this->posicao;
        }

        float getTamanho(){
            return this->tamanho;
        }

        void desenharProjetil(){
            color(0,0,1);
            line(
                posicao.getX(),
                posicao.getY(),
                posicao.getX()+direcao.getX()*this->tamanho, posicao.getY()+direcao.getY()*this->tamanho
            );
        }

        void transformarProjetil(float ang, float aceleracao){
            direcao.setX(cos(ang+M_PI/2));
            direcao.setY(sin(ang+M_PI/2));

            posicao.setX(posicao.getX()+direcao.getX()*aceleracao);
            posicao.setY(posicao.getY()+direcao.getY()*aceleracao);
        }

        void disparaProjetil(){
            Projetil clone = Projetil(
                this->posicao.getX(),
                this->posicao.getY(),
                this->direcao
            );

            posicao.setX(posicao.getX()+direcao.getX()*velocidade);
            posicao.setY(posicao.getY()+direcao.getY()*velocidade);
        }
};
