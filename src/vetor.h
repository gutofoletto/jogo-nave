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
};

#endif
