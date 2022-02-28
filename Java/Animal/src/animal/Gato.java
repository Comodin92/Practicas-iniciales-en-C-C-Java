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
public class Gato extends Animal {
    
    String raza;
    
    Gato()
    {}
    
    Gato(String nombre, String tipoA, int edad)
    {
        super(nombre, tipoA, edad);
        this.raza = "Gato";
    }
    
    public void mostrarRazaGato()
    {
        super.mostrarAnimal();
        System.out.println("Raza: " + this.raza);
    }
}
