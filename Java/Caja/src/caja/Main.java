/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package caja;

/**
 *
 * @author Agus
 */
public class Main {
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        Caja c1 = new Caja();
        System.out.println("El volumen de la caja2 es: " + c1.volumen(3, 2, 6));
        
        Caja c2 = new Caja(2, 4, 6);
        System.out.println("El volumen de la caja es: " + c2.volumen());
       
    }
    
}
