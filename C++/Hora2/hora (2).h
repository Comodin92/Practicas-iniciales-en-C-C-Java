#ifndef HORA_H
#define HORA_H
#include <iostream.h>
#include <string.h>

class hora
{		  private:
					int hora;
               int minuto;
               int segundo;

			public:
                 Hora();
                 Hora(int=0,int=0,int=0);
                 //~Hora();
                 Hora& operator= (const Hora&);
                 Hora& operator++ ();
                 Hora operator++(int a);
                 Hora& operator--();


 };
#endif
