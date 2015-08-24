Class Matrix {
    float m[3][3]; //em coordenadas homogêneas
public:
    Matrix();
    void operator *(Matrix m);  //multiplica por outra matriz
    void loadIdentity();        //carrega matriz identidade
    void rotate(float ang);     //concatena matriz de rotação
    void translate(float dx, float dy); //concatena matriz de translação
    void scale(float sx, float sy);     //concatena matriz de escala
    Vector operator*(Vector v);         //multiplica um ponto v pela matriz
    void push(); //empilha matriz (duplica o valor do topo)
    void pop();  //desempilha matriz (remove o topo da pilha)
} 
