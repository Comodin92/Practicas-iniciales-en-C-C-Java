/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package automovil;

import java.util.Scanner;

/**
 *
 * @author Juan
 */
public class Main {
    
    
    public static void main(String[] args) {
        ///Datos de Luis
        Scanner entrada = new Scanner(System.in);
        System.out.println("Ingrese año del auto de Luis: ");
        String anLuisS = entrada.nextLine();
        int anLuis = Integer.parseInt(anLuisS);
        System.out.println("Ingrese marca del auto de Luis:");
        String marLuis = entrada.nextLine();
        System.out.println("Ingrese modelo del auto de Luis:");
        String modLuis = entrada.nextLine();
        
        ///Datos de Juan
        System.out.println("Ingrese año del auto de Juan: ");
        String anJuanS = entrada.nextLine();
        int anJuan = Integer.parseInt(anJuanS);
        System.out.println("Ingrese marca del auto de Juan:");
        String marJuan = entrada.nextLine();
        System.out.println("Ingrese modelo del auto de Juan:");
        String modJuan = entrada.nextLine();
        
        
        Automovil autoDeLuis = new Automovil(marLuis, modLuis, anLuis);
        Automovil autoDeJuan = new Automovil(marJuan, modJuan, anJuan);

        
        autoDeLuis.recorre(30);
        autoDeLuis.recorre(40);
        autoDeLuis.recorre(220);
        autoDeJuan.recorre(40);
        autoDeJuan.recorre(40);
        autoDeJuan.recorre(220);
        System.out.println(autoDeLuis.toString());
        System.out.println(autoDeJuan.toString());
        
        System.out.println("El coche de Luis ha recorrido: "+ autoDeLuis.getKilometraje()+"Km");
        System.out.println("El coche de Juan ha recorrido: "+ autoDeJuan.getKilometraje()+"Km");
        System.out.println("El kilometraje total ha sido: " + Automovil.getKilometrajeTotal()+ "Km");
       
    }
}
