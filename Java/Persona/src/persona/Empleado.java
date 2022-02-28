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
public class Empleado extends Persona{
    
    private int idEmpleado;
    private double sueldo;
    
    //Constructor x defecto
    Empleado(){
    }
    
    //Constructor x defecto (con herencia)
    Empleado(int id, double sueldo){
        super();
        this.idEmpleado = id;
        this.sueldo = sueldo;
    }
    
    //Constructor parametrizado 1 (con herencia)
    Empleado(String n, String ap, int id, double sueldo){
        super(n, ap);
        this.idEmpleado = id;
        this.sueldo = sueldo;
    }
    
    //Constructor parametrizado
//    Empleado(int id, double sueldo)
//    {
//        this.idEmpleado = id;
//        this.sueldo = sueldo;
//    }
    
    //Getters
    public int obtenerIdEmpleado()
    {
        return this.idEmpleado;
    }
    
    public double obtenerSueldo()
    {
        return this.sueldo;
    }
    
    //Setters
    public void modificarIdEmpleado(int id)
    {
        this.idEmpleado = id;
    }
    
    public void modificaSueldo(int sueldo)
    {
        this.sueldo = sueldo;
    }
    
    public void mostrarEmpleado()
    {
        super.verInformacion(); //Llamo al metodo de Persona heredado.
        System.out.println("idEmpleado: " + this.idEmpleado);
        System.out.println("Sueldo: " + this.sueldo);
    }    
}
