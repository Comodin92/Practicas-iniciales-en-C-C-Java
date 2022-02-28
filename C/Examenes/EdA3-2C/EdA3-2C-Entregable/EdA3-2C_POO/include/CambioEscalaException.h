#ifndef CAMBIOESCALAEXCEPTION_H_INCLUDED
#define CAMBIOESCALAEXCEPTION_H_INCLUDED

#include <iostream>
using namespace std;

class CambioEscalaException :public exception
{
	public:
		CambioEscalaException():exception(){}
		const char *what() throw()
		{
		    return "No se permite cambio de escala";
		}

};
#endif // CAMBIOESCALAEXCEPTION_H_INCLUDED
