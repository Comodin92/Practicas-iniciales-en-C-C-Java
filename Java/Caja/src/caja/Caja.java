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
public class Caja {

    //Static -> si yo cambio el valor de el atributo 'a' estatico, este cambiara
    //el valor de todos los objetos de mi clase.
    
    //Sin static -> si yo cambio el valor de mis atributos, SOLO cambiaran
    //los valores del OBJETO que haya modificado.
    
    //Pertenecen al objeto
    private int ancho,
                alto,
                profundo;
    
    static int a; //Pertenece a la clase y no al objeto
    
    Caja()
    {}
    
    
    //This-> solo funciona para atributos NO ESTATICOS.
    
    Caja(int ancho, int alto, int profundo)
    {
        this.ancho = ancho;
        this.alto = alto;
        this.profundo = profundo;
    }
    
    public int volumen()
    {
        return (ancho * alto * profundo);
    }
    
    public int volumen(int ancho, int alto, int profundo)
    {
        return (ancho * alto * profundo);
    }
    
    public void mostrarAncho()
    {
        System.out.println("Ancho: " + this.ancho);
    }
    
    public static void mostrarAtributoA()
    {
        System.out.println("Atributo a: " + a);
    }
    
}
