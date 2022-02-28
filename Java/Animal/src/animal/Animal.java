/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package animal;

/**
 *
 * @author Agus
 */
public class Animal {

    /**
     * @param args the command line arguments
     */
    private String nombre,
                   tipo_alimentacion;
    
    private int edad;
    
    Animal()
    {}
    
    Animal(String nombre, String tipoA, int edad)
    {
        this.nombre = nombre;
        this.tipo_alimentacion = tipoA;
        this.edad = edad;
    }
    
    //getters
    public String getNombre()
    {
        return this.nombre;
    }
    
    public String getTipoA()
    {
        return this.tipo_alimentacion;
    }
    
    public int getEdad()
    {
        return this.edad;
    }
    
    //setters
    public void setNombre(String nombre)
    {
        this.nombre = nombre;
    }
    
    public void setTipoA(String tipo)
    {
        this.tipo_alimentacion = tipo;
    }
    
    public void setEdad(int edad)
    {
        this.edad = edad;
    }
    
    //mostrar
    public void mostrarAnimal()
    {
        System.out.println("Nombre: " + this.nombre);
        System.out.println("Tipo Alimentacion: " + this.tipo_alimentacion);
        System.out.println("Edad: " + this.edad);
    }
}
