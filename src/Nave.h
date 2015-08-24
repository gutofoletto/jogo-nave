#ifndef __NAVE_H__
#define __NAVE_H__

#include "gl_canvas2d.h"

class Nave {
    float vertX[4];
    float vertY[4];
    float x,y;
    float escala;
    float aceleracao;
    int vel_max;

public:
  Nave();
  void setVertices();
  void desenhaNave();
  void aceleraNave();
  void moveNave(float mx, float my);
  void rodaNave(float ang);
};

#endif
