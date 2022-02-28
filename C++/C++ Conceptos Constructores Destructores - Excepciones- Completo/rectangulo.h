#ifndef RECTANGULO_H_INCLUDED
#define RECTANGULO_H_INCLUDED

#include <iostream>

using namespace std;

class Rectangulo : public Figura
{
public:
        Rectangulo (float base, float altura): Figura (base, altura){}
        float Area (void)
        {
            return base*altura;
        }
};

#endif // RECTANGULO_H_INCLUDED
