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
public class Main {
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        Perro p1 = new Perro("Black", "P2", 5);
        p1.mostrarRazaPerro();
        
        Caballo c1 = new Caballo("Msdsaa", "P99", 8);
        c1.mostrarRazaCaballo();
        
        Gato g1 = new Gato("Miau", "Psa2", 14);
        g1.mostrarRazaGato();
        
    }
    
}
