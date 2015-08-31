#ifndef __VETOR_H__
#define __VETOR_H__

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class Vetor {
    float x, y;

    public:
        Vetor(float x = 0, float y = 0){
            this->x = x;
            this->y = y;
        }

        void setX(float x){
            this->x = x;
        }

        void setY(float y){
            this->y = y;
        }

        float getX(){
            return this->x;
        }

        float getY(){
            return this->y;
        }

        float comprimento(){
            return sqrt(x*x + y*y);
        }

        Vetor normalizar(){
            float x2, y2;
            float comp = this->comprimento();

            if(comp != 0){
                x2 = this->x/comp;
                y2 = this->y/comp;
            }

            return Vetor(x2, y2);
        }

        Vetor girarVetor(float angulo){
            float c = cos(angulo);
            float s = sin(angulo);
            return Vetor(
                (this->x * c) - (this->y * s),
                (this->x * s) + (this->y * c)
            );
        }

        Vetor moverVetor(Vetor v){
            return Vetor(
                this->x + v.getX(),
                this->y + v.getY()
            );
        }

        float produtoEscalar(Vetor v)
        {
            return x * v.getX() + y * v.getY();
        }

        float angulo() {
        	return atan2(x, y);
        }

        float anguloRelativo(Vetor v){
        	return this->angulo() - v.angulo();
        }
};

#endif
