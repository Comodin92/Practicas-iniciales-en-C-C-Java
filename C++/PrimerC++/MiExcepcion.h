#ifndef MIEXCEPCION_H_INCLUDED
#define MIEXCEPCION_H_INCLUDED

/*
ESTA CLASE ESTA EN LAS LIBRERIA STANDARD
class exception{
public:
    exception() throw(); //CON EL THROW AL FINAL DIGO QUE EL METODO NO PUEDE LANZAR EXCEPCIONES
    virtual  ~exception() throw();
    virtual const char* what() const throw();
};
*/

class DividirPorCeroException : public exception{
public:
    DividirPorCeroException() : exception(){}
    const char * what() const throw();
};

#endif // MIEXCEPCION_H_INCLUDED
