/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package automovil;

/**
 *
 * @author Juan
 */
public class Automovil {

    ///Atributos de la clase
    
    private final String _marca;
    private final String _modelo;
    private int kilometraje;
    private final int anio;
    static int kilometrajeTotal;
   
    ///Constructor
    Automovil( String marca, String modelo, int anio)
    {//Si bien el año no está como atributo en la clase, pero supongo que debe de ser un problema
        /// que se le escapó al jefe. Como no tenemos lo que muestra por pantalla
        // decido agregarlo para que el toString me muestre los datos pedidos por teclado
        //sino seria una absurdo pedir por teclado un dato que no voy a usar(bajo mi criterio).
        this._marca = marca;
        this._modelo = modelo;   
        this.kilometraje = 0;
        this.anio= anio;
    }

    public int getKilometraje() {
        return kilometraje;
    }
    
    static public int getKilometrajeTotal()
    {
        return kilometrajeTotal;
        
    }
    
     public void recorre(int cantKm) 
    {
      this.kilometraje +=cantKm;
      kilometrajeTotal+=cantKm;
              
    }
     
    
    @Override
    public String toString() {
        return "Automovil{" + "_marca=" + _marca + ", _modelo=" + _modelo + ", año = "+ anio +'}';
}

  

}