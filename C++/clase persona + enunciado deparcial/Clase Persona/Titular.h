#ifndef TITULAR_H
#define TITULAR_H

#include <iostream>
#include <string.h>

using namespace std;

class Titular
{
    public:
        Titular();
        ~Titular();
        Titular(const Titular& other);
        Titular(long nroCta,double descA);
        friend ostream& operator<<(ostream& sal,const Titular& obj);
        Titular& operator=(const Titular& obj);
        long identificacion();
    protected:
    private:
        long nroCta;
        double descA;
};

#endif // TITULAR_H
