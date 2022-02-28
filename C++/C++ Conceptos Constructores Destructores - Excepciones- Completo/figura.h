#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED

#include <iostream>

using namespace std;

class Figura
{
    protected:
                float base,
                      altura;
    public:
                Figura ( float base, float altura ): base (base), altura (altura) {}
                virtual float  Area () = 0; //Funcion virtual pura
                void Mostrar_area (void)
                {
                    cout<<"\tEl area es: "<<Area()<<endl;
                }
};

#endif // FIGURA_H_INCLUDED
