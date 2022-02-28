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
public class Perro extends Animal{
    
    String raza;
    
    Perro()
    {}
    
    Perro(String nombre, String tipoA, int edad)
    {
        super(nombre, tipoA, edad);
        this.raza = "Perro";
    }
    
    public void mostrarRazaPerro()
    {
        super.mostrarAnimal();
        System.out.println("Raza: " + this.raza);
    }

}
