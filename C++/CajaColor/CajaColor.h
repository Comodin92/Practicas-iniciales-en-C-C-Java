#ifndef CAJACOLOR_H_INCLUDED
#define CAJACOLOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define MAX_LONG            500
#define MIN_ALT             0

using namespace std;

char *str_new_dup(char *);

class CajaColor
{
    private:
            float   ancho,
                    alto,
                    largo;
            char    *color;
    public:
            CajaColor();
            CajaColor(float ,float ,float ,char *);
            CajaColor(const CajaColor& );
            friend ostream& operator<<(ostream& ,CajaColor& );
            CajaColor& operator=(const CajaColor& );
            CajaColor operator++(int);
            CajaColor operator--(int);
            void CambiarColor(char *);
            ~CajaColor();
};


#endif // CAJACOLOR_H_INCLUDED
