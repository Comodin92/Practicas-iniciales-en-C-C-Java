/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package persona;

/**
 *
 * @author Agus
 */
public class Persona {

    //Atributos de una clase

    String nombre;
    String apellido;
    int edad;
    String ocupacion;
    int idPersona; //asociado al objeto
    static int contadorPersonas; //asociado a la clase (static)

    //Constructor por defecto
    Persona()
    {
        contadorPersonas ++;
        this.idPersona = contadorPersonas;
    }

    //Constructor parametrizado
    Persona(String nom, String ape)
    {
        this();
        nombre = nom;
        apellido = ape;
    }
    
    //Constructor parametrizado
    Persona(String nom, String ape, int ed, String ocup)
    {
        this(nom, ape);

        edad = ed;
        ocupacion = ocup;
    }

    //Metodos

    // 1 - Ambito ( privado, publico o protegido)
    // 2 - Lo que devuelve
    // 3 - Nombre del metodo
    // 4 - Lo que recibe (argumentos)
    
    //Metodo getInfo
    public void verInformacion()
    {
        System.out.println("Nombre: " + this.obtenerNombre());
        System.out.println("Apellido: " + this.apellido);
        System.out.println("Edad: " + this.edad);
        System.out.println("Ocupacion: " + this.ocupacion);
        System.out.println("Id Persona: " + this.idPersona);
    }
    
    //Metodo setNombre
    public void modificarNombre(String n){
        nombre = n;
    }
    
    //Metodo getNombre
    public String obtenerNombre()
    {
        return nombre;
    }
    
    public static int cantidadObjetosCreados()
    {
        return contadorPersonas; 
    }
    
    //sobreescribir el metodo to string

    @Override
    public String toString() {
        return "Persona{" + "nombre=" + nombre + ", apellido=" + apellido + ", edad=" + edad + ", ocupacion=" + ocupacion + ", idPersona=" + idPersona + '}';
    }
    
}
