#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED

#include <iostream>

using namespace std;

class Triangulo : public Figura
{
public:
        Triangulo (float base, float altura): Figura (base, altura){}
        float Area (void)
        {
            return ((base*altura)/2);
        }

};

#endif // TRIANGULO_H_INCLUDED
