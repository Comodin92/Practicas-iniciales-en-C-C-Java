#include "cadenas.h"

#include <iostream>
#include <string.h>

#define TAM_CADENA 100
#define MAX_BUFFER 100


using namespace std;

    ///CONSTRUCTOR DE CADENA
    //revisar
    Cadena :: Cadena ( char* c)
{
       if ( c != NULL )
       {
            this->cad = new char [ strlen( c ) +1 ];
           strcpy( this->cad , c);
       }
       else
       {
           this->cad = new char [ 1 ];
           strcpy(this->cad , "");
       }
       longi = strlen ( cad );
}
    ///DESTRUCTOR DE CADENA
    Cadena :: ~Cadena ( )
{
    delete [] cad;
}
    ///CONSTRUCTOR DE COPIA
Cadena :: Cadena ( const Cadena& obj)
{
    this->cad = new char [strlen ( obj.cad )+1 ]; //el que aprobo me corrigio
    strcpy ( this->cad, obj.cad );
    longi = strlen( obj.cad );
}
    ///SOBRECARGA DE OPERADOR =
Cadena& Cadena :: operator = ( const Cadena& obj )
{
    delete [] cad; //Borro lo que asigno por defecto
    cad = new char [ strlen( obj.cad)+1]; //Creo el objeto con la memoria necesaria
    strcpy ( this->cad , obj.cad); //le copiolo necesario
    longi = strlen(obj.cad); //le entrego la longitud que tiene la cadena ahora
    return *this; //entrego el puntero objeto

}
    ///SOBRECARGA DE OPERADOR +
Cadena Cadena :: operator + ( const Cadena& obj ) const
{
    char * cad_aux = new char [ strlen ( cad ) + strlen ( obj.cad )+1]; //Fabrico un char* con la memoria necesaria
    strcpy ( cad_aux , cad); //copio a cad_aux cad
    strcat ( cad_aux , obj.cad); //copio a cad_aux lo que falta)
    Cadena aux ( cad_aux );
    delete [] cad_aux;
    return aux;
}

    ///SOBRECARGA DE OPERADOR + ENTRE CHAR* Y CADENA HACIA UNA CADENA
Cadena Cadena :: operator + ( const char *c ) const
{
    char * cad_aux = new char [ strlen ( c ) + strlen ( cad )+1]; //Fabrico un char* con la memoria necesaria
    strcpy ( cad_aux , cad); //copio a cad_aux cad
    strcat ( cad_aux , c); //copio a cad_aux lo que falta)
    Cadena aux ( cad_aux );
    delete [] cad_aux;
    return aux;
}
    ///SOBRECARGA DE OPERADOR ==
bool Cadena :: operator == ( const Cadena& obj ) const
{
    return (strcmp ( cad , obj.cad ) == 0 );
}
    ///SOBRECARGA DE OPERADOR +=
    Cadena& Cadena :: operator += ( const Cadena& obj )
{
    char *aux = new char [strlen ( cad )+ strlen ( obj.cad )+1]; //creo un *char con la suficiente memoria para asignar y copiar
    strcpy( aux , cad ); // copio cad
    strcat( aux , obj.cad ); // copio el otro
    delete [] cad; //Elimino la memoria antigua de cad
    longi = strlen (aux); //le digo que tn largo quedo aux
    cad = new char [ longi +1]; //creo cad con la longitud justa
    strcpy ( this->cad , aux ); //Copio la cadena
    delete [] aux; //Borro lo que quedo en basura
    return *this;
}

    ///SOBRECARGA CON FUNCION AMIGA <<
ostream&             operator << (ostream& salida, const Cadena& obj)
{
    salida<<obj.cad;
    return salida;
}

    ///SOBRECARGA CON FUNCION AMIGA >>
istream&             operator >> (istream& entrada, Cadena& obj)
{
    //vamos a operar sobre un objeto construido
    char temp[MAX_BUFFER];//creo un buffer de entrada para poner la linea a cargar en cadena
    cout<<"\tIngrese Texto  ";
    cin.getline (temp,MAX_BUFFER,'\n');//lo que leyo del flujo de entrada lo pasa a temp
    cin.ignore();
    delete [] obj.cad; //como no se el tamaño de memoria reservada lo borro
    obj.cad = new char [strlen(temp)+1];//asigno memoria en funcion de lo que cargue como parametro
    //hay que verificar que haya memoria, en exepciones hay que terminar esto
    strcpy(obj.cad,temp);
    return entrada;
}
    /*
istream&             operator >> (istream& entrada, Cadena& obj)
{
    cout<<"\tIngrese Texto  ";
    char aux [TAM_CADENA];
                                                //aux = seria la entrada el stdin
                                                //TAM_CADENA seria la cantidad de asignacion maxima
    entrada.getline( aux, TAM_CADENA);
                                                //TAM_CADENA le digo desde donde empesar a ignorar lo que venga por la entrada
    //entrada.ignore ( TAM_CADENA,'\n' );
    strcpy (obj.cad,aux);
    return entrada;
}

*/
 Cadena          operator + ( const char* c, const Cadena& obj)
{
    char * cad_aux = new char [ strlen ( c ) + strlen ( obj.cad )+1]; //Fabrico un char* con la memoria necesaria
    strcpy ( cad_aux , c); //copio a cad_aux cad
    strcat ( cad_aux , obj.cad); //copio a cad_aux lo que falta)
    Cadena aux ( cad_aux );
    delete [] cad_aux;
    return aux;
}

int Cadena :: longitud ( void )
{
    return longi;
}


