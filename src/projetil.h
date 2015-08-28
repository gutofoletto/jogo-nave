class Projetil{
    float tamanho;
    float velocidade;
    Vetor posicao;
    Vetor direcao;

    public:
        Projetil( Vetor pos, Vetor dir){
            tamanho = 10.0f;
            velocidade = 10.0f;
            posicao = pos;
            direcao = dir;
        }

        Vetor getPosicao(){
            return this->posicao;
        }

        float getTamanho(){
            return this->tamanho;
        }

        float getVelocidade(){
            return this->velocidade;
        }

        void desenharProjetil(){
            color(0,0,1);
            line(
                posicao.getX(),
                posicao.getY(),
                posicao.getX()+direcao.getX()*this->tamanho, posicao.getY()+direcao.getY()*this->tamanho
            );
        }

        void transformarProjetil(){
            posicao.setX(posicao.getX()+direcao.getX()*velocidade);
            posicao.setY(posicao.getY()+direcao.getY()*velocidade);
        }

};
